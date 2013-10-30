#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <cstring>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (serial.portName() != QString("COM13")) {
        serial.close();
        serial.setPortName("COM13");

        if (!serial.open(QIODevice::ReadOnly)) {
            processError(tr("Can't open %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setBaudRate(QSerialPort::Baud9600)) {
            processError(tr("Can't set rate 9600 baud to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
            processError(tr("Can't set 8 data bits to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
            processError(tr("Can't set no patity to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
            processError(tr("Can't set 1 stop bit to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
            processError(tr("Can't set no flow control to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }
    }

    //    connect(&serial, SIGNAL(readyRead()),
    //            this, SLOT(readResponse()));
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(readResponse()));

    timer.start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readResponse()
{
    //qDebug() << "Data Ready";

    char c;
    QString rx_data;

    while (serial.getChar(&c)) {

        if (c == '#') {      //'&' is the terminating character of valid data

            rx_data = QString(response);
            qDebug() << "Data = " << rx_data;
            response.clear();

            break;
        }
        else {
            if (c != '&')    // '&' is the starting character of valid data
                response.append(c);

            //qDebug() << "Reading..." << c;
        }
    }

}

void MainWindow::processTimeout()
{
    //setControlsEnabled(true);
    //    trafficLabel->setText(tr("Traffic, transaction #%1:"
    //                             "\n\r-request: %2"
    //                             "\n\r-response: %3")
    //                          .arg(++transactionCount).arg(requestLineEdit->text()).arg(QString(response)));
    qDebug() << "Process Timeout!!";
    response.clear();
}

void MainWindow::processError(const QString &error)
{
    //setControlsEnabled(true);
    //statusLabel->setText(tr("Status: Not running, %1.").arg(error));
    //trafficLabel->setText(tr("No traffic."));
    qDebug() << "Process Error!!";
}


void MainWindow::on_stop_clicked()
{
    serial.close();
    qDebug() << "Program Terminated";
    exit(0);
}
