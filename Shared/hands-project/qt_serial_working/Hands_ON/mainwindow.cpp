#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtSql>
#include <cstring>
#include <vector>
#include <QMessageBox>
#include <QLCDNumber>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <qcustomplot.h>
#include <Reading.h>
#include <Reader.h>
#include <performance_metric.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupRealtimeDataDemo(ui->rvlh_left_xy);
    statusBar()->clearMessage();

    setupRealtimeDataDemo(ui->rvlh_right_xy);
    statusBar()->clearMessage();

    setupRealtimeDataDemo(ui->lvrh_left_xy);
    statusBar()->clearMessage();

    setupRealtimeDataDemo(ui->lvrh_right_xy);
    statusBar()->clearMessage();

    setupRealtimeScoreDemo(ui->rvlh_score_bar);
    statusBar()->clearMessage();

    setupRealtimeScoreDemo(ui->lvrh_score_bar);
    statusBar()->clearMessage();

    setupCircle(ui->rvlh_left_circle);
    statusBar()->clearMessage();

    setupCircle(ui->rvlh_right_circle);
    statusBar()->clearMessage();

    setupCircle(ui->lvrh_left_circle);
    statusBar()->clearMessage();

    setupCircle(ui->lvrh_right_circle);
    statusBar()->clearMessage();

    real_velocity_right.push_back(0.0);
    real_velocity_right.push_back(0.0);
    real_velocity_right.push_back(0.0);

    real_velocity_left.push_back(0.0);
    real_velocity_left.push_back(0.0);
    real_velocity_left.push_back(0.0);

    ui->timer->setVisible(false);
    ui->main_tab->setCurrentIndex(0);
    ui->major->setFocus();

    qDebug() << QSqlDatabase::drivers();

    qDebug() << (db.isValid() ? "VALID" : "ERROR");

    db.setHostName("fulla.ece.tamu.edu");
    db.setDatabaseName("hand");
    db.setUserName("hand_user");
    db.setPassword("hand_password");
    db.setPort(5432);

    bool ok = db.open();

    ok = true;

    if (ok) {
        qDebug() << "Worked!";
        QComboBox* gender = (QComboBox*) (ui->gender);
        QComboBox* hand = (QComboBox*) (ui->hand);
        gender->addItem("Male");
        gender->addItem("Female");
        hand->addItem("Right Hand");
        hand->addItem("Left Hand");
    }
    else {
        qDebug() << "Database Connection Error. Program will exit now";
        exit(0);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readResponse()
{
    //Below is the Code for IMU

    if (plotSwitch) {
        double axr,ayr,azr,axl,ayl,azl,angleLeft,angleRight;

        Reading readingRight = readerRight.GetReading();
        Reading readingLeft = readerLeft.GetReading();
        //    reading.PrintReading();

        if ((readingRight.GetErrorMessage() == "") && readingLeft.GetErrorMessage() == "") {
            axr = readingRight.GetAccelerationXAxis();
            ayr = readingRight.GetAccelerationYAxis();
            azr = readingRight.GetAccelerationZAxis();
            angleRight = readingRight.GetAngle();

            axl = readingLeft.GetAccelerationXAxis();
            ayl = readingLeft.GetAccelerationYAxis();
            azl = readingLeft.GetAccelerationZAxis();
            angleLeft = readingLeft.GetAngle();

            qDebug() << "Right Hand: " << "Xacc = " << axr << "Yacc = " << ayr << "Zacc = " << azr << "Angle = " << angleRight;

            qDebug() << "Left Hand: " << "Xacc = " << axl << "Yacc = " << ayl << "Zacc = " << azl << "Angle = " << angleLeft;

            // Scoring Metric Code

            vector<double> tempRight,tempLeft;
            tempRight.push_back(axr);
            tempRight.push_back(ayr);
            tempRight.push_back(azr);

            tempLeft.push_back(axl);
            tempLeft.push_back(ayl);
            tempLeft.push_back(azl);

            real_score_right += scorePercentageVertical(angleRight,tempRight,real_velocity_right,0.04);

            real_score_left += scorePercentageVertical(angleLeft,tempLeft,real_velocity_left,0.04);

            total_score = real_score_right + real_score_left;

            qDebug() << "Total Score: " << total_score<<endl;


            // -------------------

            realtimeDataSlot(axr,ayr,azr,axl,ayl,azl,total_score);
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



void MainWindow::realtimeDataSlot(double axr,double ayr,double azr,double axl,double ayl,double azl,double real_score)
{

    if (plotSwitch) {
        // calculate two new data points:
        //#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)

        //        static double key_x = 0;

        //#else
        //double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
        //#endif
        //static double lastPointKey = 0;

        static int time = 0, seconds = 0, minutes = 0;
        QString timeLeft;

        static double range_x = 100, range_y = 300;

        static double score_range_x = 10, score_range_y = 10;

        QCustomPlot *left_xy,*right_xy,*score_bar,*left_ping,*right_ping;
        QCustomPlot *left_circle,*right_circle;
        QLabel* current_score;

        if (trialNumber == 1) {
            left_xy = (QCustomPlot*) (ui->rvlh_left_xy);
            right_xy = (QCustomPlot*) (ui->rvlh_right_xy);
            score_bar = (QCustomPlot*) (ui->rvlh_score_bar);
            left_ping = (QCustomPlot*) (ui->rvlh_left_ping);
            right_ping = (QCustomPlot*) (ui->rvlh_right_ping);
            left_circle = (QCustomPlot*) (ui->rvlh_left_circle);
            right_circle = (QCustomPlot*) (ui->rvlh_right_circle);
            current_score = (QLabel*) (ui->rvlh_current_score);
        }
        else {
            left_xy = (QCustomPlot*) (ui->lvrh_left_xy);
            right_xy = (QCustomPlot*) (ui->lvrh_right_xy);
            score_bar =(QCustomPlot*) (ui->lvrh_score_bar);
            left_ping = (QCustomPlot*) (ui->lvrh_left_ping);
            right_ping = (QCustomPlot*) (ui->lvrh_right_ping);
            left_circle = (QCustomPlot*) (ui->lvrh_left_circle);
            right_circle = (QCustomPlot*) (ui->lvrh_right_circle);
            current_score = (QLabel*) (ui->lvrh_current_score);
        }


        left_xy->xAxis->setRange(0,range_x);
        left_xy->yAxis->setRange((-1)*range_y,range_y);


        right_xy->xAxis->setRange(0,range_x);
        right_xy->yAxis->setRange((-1)*range_y,range_y);

        if (real_score >= score_range_y)
            score_range_y += 10;

        score_bar->yAxis->setRange(0,score_range_y);


        int cnt = 0;

        while (cnt-- >= 0) {
            // add data to lines:

            //Right Hand Data

            left_xy->graph(0)->addData(key_x, axl);

            // set data of dots:
            left_xy->graph(1)->clearData();
            left_xy->graph(1)->addData(key_x, axl);

            left_xy->graph(2)->addData(key_x, ayl);

            left_xy->graph(3)->clearData();
            left_xy->graph(3)->addData(key_x, ayl);


            //Left Hand data

            right_xy->graph(0)->addData(key_x, axr);

            right_xy->graph(1)->clearData();
            right_xy->graph(1)->addData(key_x, axr);

            right_xy->graph(2)->addData(key_x, ayr);

            right_xy->graph(3)->clearData();
            right_xy->graph(3)->addData(key_x, ayr);


            QCPBars *score = new QCPBars(score_bar->xAxis, score_bar->yAxis);

            score_bar->clearPlottables();
            score_bar->addPlottable(score);
            QPen pen;
            pen.setWidthF(5);
            pen.setColor(Qt::green);

            score->setPen(pen);
            score->setBrush(Qt::green);

            QVector<double> ticks,value;

            ticks << 1;
            value << real_score;
            score->clearData();
            score->setData(ticks, value);
            score->rescaleValueAxis(true);

            int noOfPoints = 250;
            QVector<double> x_left(2*noOfPoints+1),x_right(2*noOfPoints+1),y1_left(2*noOfPoints+1),y2_left(2*noOfPoints+1);
            QVector<double> y1_right(2*noOfPoints+1), y2_right(2*noOfPoints+1);

            azl = key_x;
            azr = key_x;
            int index = 0;
            double r_left = std::abs(azl), r_right = std::abs(azr);
            for (int i=(-1)*noOfPoints; i<=noOfPoints; i++) {
                x_left[index] = (i/(double)(noOfPoints))*r_left;
                x_right[index] = (i/(double)(noOfPoints))*r_right;
                y1_left[index] = sqrt(pow(r_left,2)-pow(x_left[index],2));
                y2_left[index] = (-1)*y1_left[index];
                y1_right[index] = sqrt(pow(r_right,2)-pow(x_right[index],2));
                y2_right[index] = (-1)*y1_right[index];
                ++index;
            }

            QCPCurve *semicircle1_left = new QCPCurve(left_circle->xAxis, left_circle->yAxis);
            QCPCurve *semicircle2_left = new QCPCurve(left_circle->xAxis, left_circle->yAxis);
            QCPCurve *semicircle1_right = new QCPCurve(right_circle->xAxis, right_circle->yAxis);
            QCPCurve *semicircle2_right = new QCPCurve(right_circle->xAxis, right_circle->yAxis);

            semicircle1_left->setPen(QPen(QColor(255, 120, 0)));
            semicircle1_left->setBrush(QBrush(QColor(255, 120, 0, 30)));
            semicircle2_left->setPen(QPen(QColor(255, 120, 0)));
            semicircle2_left->setBrush(QBrush(QColor(255, 120, 0, 30)));
            semicircle1_right->setPen(QPen(QColor(255, 120, 0)));
            semicircle1_right->setBrush(QBrush(QColor(255, 120, 0, 30)));
            semicircle2_right->setPen(QPen(QColor(255, 120, 0)));
            semicircle2_right->setBrush(QBrush(QColor(255, 120, 0, 30)));

            left_circle->clearPlottables();
            left_circle->xAxis->setRange((-1)*(r_left+10),r_left+10);
            left_circle->yAxis->setRange((-1)*(r_left+10),r_left+10);
            left_circle->addPlottable(semicircle1_left);
            left_circle->addPlottable(semicircle2_left);
            semicircle1_left->setData(x_left,y1_left);
            semicircle2_left->setData(x_left,y2_left);

            right_circle->clearPlottables();
            right_circle->xAxis->setRange((-1)*(r_right+10),r_right+10);
            right_circle->yAxis->setRange((-1)*(r_right+10),r_right+10);
            right_circle->addPlottable(semicircle1_right);
            right_circle->addPlottable(semicircle2_right);
            semicircle1_right->setData(x_right,y1_right);
            semicircle2_right->setData(x_right,y2_right);

            left_circle->replot();
            right_circle->replot();
            left_circle->rescaleAxes(true);
            right_circle->rescaleAxes(true);

            current_score->setText("SCORE\n" + QString::number(real_score));

            time = endOfPlay.remainingTime();

            seconds = (time % 60000)/1000;

            minutes = time/60000;

            timeLeft = QString::number(minutes,'g',3) + ":" + QString::number(seconds,'g',3);

            ui->timer->display(timeLeft);


            // remove data of lines that's outside visible range:
            //        ui->customPlot->graph(0)->removeDataBefore(key-range_of_graph);
            //        ui->customPlot->graph(1)->removeDataBefore(key-range_of_graph);
            //        ui->customPlot->graph(2)->removeDataBefore(key-range_of_graph);

            // rescale value (vertical) axis to fit the current data:
            //        ui->customPlot->graph(0)->rescaleValueAxis();
            //        ui->customPlot->graph(1)->rescaleValueAxis();
            //        ui->customPlot->graph(2)->rescaleValueAxis();
            //        ui->customPlot->graph(3)->rescaleValueAxis();
            //        ui->customPlot->graph(5)->rescaleValueAxis();
            //        ui->customPlot->graph(6)->rescaleValueAxis();

            //lastPointKey = key;
            // }

            // make key axis range scroll with the data (at a constant range size of "range_of_graph"):

            left_xy->xAxis->setRange(key_x+0.2, 100, Qt::AlignRight);
            left_xy->replot();

            right_xy->xAxis->setRange(key_x+0.2, 100, Qt::AlignRight);
            right_xy->replot();

            score_bar->replot();

        }

        key_x += 0.2;
    }
}


void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif

    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);

    customPlot->addGraph(); // blue dot
    customPlot->graph(1)->setPen(QPen(Qt::blue));
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    customPlot->addGraph(); // red line
    customPlot->graph(2)->setPen(QPen(Qt::red));

    customPlot->addGraph(); // red dot
    customPlot->graph(3)->setPen(QPen(Qt::red));
    customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    QPen gridPen;
    gridPen.setColor(Qt::white);

    //    customPlot->xAxis->setLabel("<--- Time --->");
    //    customPlot->xAxis->setLabelFont(font);
    //    customPlot->xAxis->setTickLabelType(QCPAxis::ltNumber);
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    //    customPlot->xAxis->setNumberFormat("gb");
    //customPlot->xAxis->setDateTimeFormat("MM-dd-yyyy\nHH:mm:ss");
    customPlot->xAxis->setAutoTickStep(false);
    //customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickStep(0.2);
    customPlot->xAxis->setTickPen(gridPen);
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis2->setTickLabelColor(Qt::white);

    customPlot->xAxis->grid()->setPen(gridPen);
    customPlot->yAxis->grid()->setPen(gridPen);
    customPlot->yAxis->setTickPen(gridPen);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis2->setTickLabelColor(Qt::white);

    customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    //    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    //    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

void MainWindow::setupRealtimeScoreDemo(QCustomPlot *scorePlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif


    scorePlot->xAxis->setAutoTicks(false);
    scorePlot->xAxis->setAutoTickLabels(false);
    scorePlot->xAxis->setTickLabelColor(Qt::white);
    scorePlot->xAxis->grid()->setVisible(true);
    scorePlot->xAxis->setRange(0, 2);

    connect(scorePlot->xAxis, SIGNAL(rangeChanged(QCPRange)), scorePlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(scorePlot->yAxis, SIGNAL(rangeChanged(QCPRange)), scorePlot->yAxis2, SLOT(setRange(QCPRange)));

}

void MainWindow::setupCircle(QCustomPlot *circlePlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif


    //    circlePlot->xAxis->setAutoTicks(false);
    //    circlePlot->xAxis->setAutoTickLabels(false);
    //    circlePlot->xAxis->setTickStep(0.2);
    //    circlePlot->xAxis->setTickLabelColor(Qt::white);

    //    circlePlot->yAxis->setTickLabelColor(Qt::white);

    QCPCurve *semicircle1 = new QCPCurve(circlePlot->xAxis, circlePlot->yAxis);
    QCPCurve *semicircle2 = new QCPCurve(circlePlot->xAxis, circlePlot->yAxis);

    semicircle1->setPen(QPen(QColor(255, 120, 0)));
    semicircle1->setBrush(QBrush(QColor(255, 120, 0, 30)));
    semicircle2->setPen(QPen(QColor(255, 120, 0)));
    semicircle2->setBrush(QBrush(QColor(255, 120, 0, 30)));

    circlePlot->addPlottable(semicircle1);
    circlePlot->addPlottable(semicircle2);

    circlePlot->axisRect()->setupFullAxesBox();

    connect(circlePlot->xAxis, SIGNAL(rangeChanged(QCPRange)), circlePlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(circlePlot->yAxis, SIGNAL(rangeChanged(QCPRange)), circlePlot->yAxis2, SLOT(setRange(QCPRange)));

}

void MainWindow::on_buttonBox_rejected()
{
    exit(0);
}

void MainWindow::on_buttonBox_accepted()
{
    gender = ui->gender->currentText();
    domHand = ui->hand->currentText();
    QString msg = "";

    QFont font;
    font.setPointSize(12);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Demographic Data Error");
    msgBox.setFont(font);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setGeometry(500,300,100,100);

    if (ui->major->text().isEmpty()) {
        msg = "Enter the major of the participant";
        msgBox.setText(msg);
        msgBox.exec();
    }
    else if ((ui->age->text().isEmpty()) || (ui->age->text().toInt() <= 5) || (ui->age->text().toInt() >= 100)) {
        msg = "Enter a valid age";
        msgBox.setText(msg);
        msgBox.exec();
    }

    if (msg.isEmpty()) {
        major = ui->major->text().trimmed();
        age = ui->age->text().toInt();
        qDebug() << "User Data: " << gender << " " << "aged " << age << " from " << major << " who is " << domHand << "dominant";
        ui->gender_age->setText(gender.toUpper()+" AGED "+ QString::number(age));
        ui->dominance->setText(domHand.toUpper());
        ui->majorDisplay->setText(major.toUpper() + "\n" + "MAJOR");
        ui->main_tab->widget(0)->setEnabled(false);
        ui->main_tab->widget(1)->setEnabled(true);
        ui->main_tab->setCurrentIndex(1);
        ui->timer->setVisible(true);
        ui->start->setEnabled(true);
        ui->stop->setEnabled(true);
        ui->timer->display("0:0");
        trialNumber = 1;
        //exit(0);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    QPushButton* OkButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    switch (e->key ()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        OkButton->click();
        break;

    default:
        ;
    }
}

void MainWindow::end_of_trial()
{
    plotSwitch = false;
    ui->statusBar->showMessage("0",0);
    QString msg = "Your Score is " + QString::number(total_score) + " !!";

    QFont font;
    font.setPointSize(12);
    QMessageBox msgBox;
    msgBox.setWindowTitle("HANDS Score");
    msgBox.setText(msg);
    msgBox.setFont(font);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setGeometry(500,300,100,100);
    if (msgBox.exec()) {
        ++trialNumber;
        if (trialNumber != 3) {

            score_left_rvlh = real_score_left;
            score_right_rvlh = real_score_right;
            score_rvlh = total_score;

            real_score_left = 0;
            real_score_right = 0;
            key_x = 0;

            ui->start->setEnabled(true);
            ui->main_tab->widget(0)->setEnabled(false);
            ui->main_tab->widget(1)->setEnabled(false);
            ui->main_tab->setCurrentIndex(2);
            ui->timer->display("0:0");
        }
        else {
            score_left_lvrh = real_score_left;
            score_right_lvrh = real_score_right;
            score_lvrh = total_score;
            score_left_total = score_left_lvrh + score_left_rvlh;
            score_right_total = score_right_lvrh + score_right_rvlh;
            score_total = score_rvlh + score_lvrh;

            QSqlQuery query;
            QString insertQuery = "INSERT into data_summary values(";

            insertQuery += major + "," + gender.at(0) + "," + age + "," + domHand.at(0);
            insertQuery += ",";
            insertQuery += score_rvlh;
            insertQuery += ",";
            insertQuery += score_right_rvlh;
            insertQuery += ",";
            insertQuery += score_left_rvlh;
            insertQuery += ",";
            insertQuery += score_lvrh;
            insertQuery += ",";
            insertQuery += score_right_lvrh;
            insertQuery += ",";
            insertQuery += score_left_lvrh;
            insertQuery += ",";
            insertQuery += score_total;
            insertQuery += ",";
            insertQuery += score_right_total;
            insertQuery += ",";
            insertQuery += score_left_total;
            insertQuery += ")";

            qDebug() << query.exec(insertQuery);

            msg = "Your Total Score is " + QString::number(score_total) + " !!";
            msgBox.setText(msg);
            if (msgBox.exec())
                exit(0);
        }
    }
}

void MainWindow::on_stop_clicked()
{
    plotSwitch = false;
    serial.close();
    qDebug() << "Program Terminated";
    QString msg = "Your Score is " + QString::number(total_score) + " !!";

    QFont font;
    font.setPointSize(12);
    QMessageBox msgBox;
    msgBox.setWindowTitle("HANDS Score");
    msgBox.setText(msg);
    msgBox.setFont(font);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setGeometry(500,300,100,100);
    msgBox.exec();

    exit(0);

}

void MainWindow::on_start_clicked()
{
    plotSwitch = true;

    ui->start->setEnabled(false);
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(readResponse()));

    connect(&endOfPlay, SIGNAL(timeout()),
            this, SLOT(end_of_trial()));

    timer.start(0);
    endOfPlay.start(60*1000);

}
