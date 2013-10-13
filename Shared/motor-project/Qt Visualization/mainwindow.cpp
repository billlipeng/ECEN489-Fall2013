#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    qDebug() << (db.isValid() ? "VALID" : "ERROR");

    //    db.setHostName("localhost");
    //    db.setDatabaseName("test");
    //    db.setUserName("postgres");
    //    db.setPassword("redhat");
    //    db.setPort(5433);

    db.setHostName("fulla.ece.tamu.edu");
    db.setDatabaseName("motor_team");
    db.setUserName("motor_team_user");
    db.setPassword("motor_team_password");
    db.setPort(5432);

    bool ok = db.open();

    if (ok)
        qDebug() << "Database Connection Established!!";
    else
        exit(0);

    ui->setupUi(this);
    // setGeometry(400,250,542,390);
    setGeometry(30,30,950,550);


    ui->horizontalScrollBar->setRange(-10, 10);
    ui->verticalScrollBar->setRange(-10, 10);

    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));


    setupRealtimeDataDemo(ui->customPlot);
    statusBar()->clearMessage();
    //ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::xAxisChanged(QCPRange range)
{
    ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
    ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::yAxisChanged(QCPRange range)
{
    ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
    ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::horzScrollBarChanged(int value)
{
    if (qAbs(ui->customPlot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->customPlot->xAxis->setRange(value/100.0, ui->customPlot->xAxis->range().size(), Qt::AlignCenter);
        ui->customPlot->replot();
    }
}

void MainWindow::vertScrollBarChanged(int value)
{
    if (qAbs(ui->customPlot->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->customPlot->yAxis->setRange(-value/100.0, ui->customPlot->yAxis->range().size(), Qt::AlignCenter);
        ui->customPlot->replot();
    }
}


void MainWindow::realtimeDataSlot()
{

    QString mode = "motor";

    mode = "temp";

    QSqlQuery query1, query2, query3, query4;


    //bool res = query.exec("SELECT * FROM temp_readings where arduino_id = 15;");

    if (mode == "temp") {
        bool res1 = query1.exec("SELECT * FROM temp_readings where arduino_id = 12 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res2 = query2.exec("SELECT * FROM temp_readings where arduino_id = 12 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res3 = query3.exec("SELECT * FROM temp_readings where arduino_id = 12 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res4 = query4.exec("SELECT * FROM temp_readings where arduino_id = 12 ORDER BY reading_time_utc DESC nulls last limit 10;");
        qDebug() << res1 << res2 << res3 << res4;
    } else {
        bool res1 = query1.exec("SELECT * FROM motor_readings where arduino_id = 1 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res2 = query2.exec("SELECT * FROM motor_readings where arduino_id = 2 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res3 = query3.exec("SELECT * FROM motor_readings where arduino_id = 27 ORDER BY reading_time_utc DESC nulls last limit 10;");
        bool res4 = query4.exec("SELECT * FROM motor_readings where arduino_id = 1 ORDER BY reading_time_utc DESC nulls last limit 10;");
        qDebug() << res1 << res2 << res3 << res4;
    }



    // calculate two new data points:
    //#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)

    static double key = 0;

    //#else
    //double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    //#endif
    //static double lastPointKey = 0;

    //qsrand(100);
    static double value1 = 0, value2 = 0, value3 = 0, value4 = 0;

    int range_of_graph = 50, step_size = 2;
    //static bool increase = true;


    if (mode == "motor") {
        ui->customPlot->yAxis->setRange(0,5);

        ui->customPlot->yAxis->setLabel("Motor Voltage (V)");
        qDebug() << "Motor";
    }
    else {
        ui->customPlot->yAxis->setRange(250,350);
        ui->customPlot->yAxis->setLabel("Temperature (K)");
        qDebug() << "Temperature";
    }
    //while (cnt-- >= 0) {


    while (query1.next() && query2.next() && query3.next() && query4.next()) {


        QSqlRecord result1 = query1.record(), result2 = query2.record(), result3 = query3.record(), result4 = query4.record();

        QString t_str1 = result1.value(1).toString();
        QString t_str2 = result2.value(1).toString();
        QString t_str3 = result3.value(1).toString();
        QString t_str4 = result4.value(1).toString();

        //QTime time = QTime::fromString(t_str.right(8),"hh:mm:ss");

        QDateTime date_time1 = QDateTime::fromString(t_str1,"yyyy-MM-dd'T'HH:mm:ss");
        QDateTime date_time2 = QDateTime::fromString(t_str2,"yyyy-MM-dd'T'HH:mm:ss");
        QDateTime date_time3 = QDateTime::fromString(t_str3,"yyyy-MM-dd'T'HH:mm:ss");
        QDateTime date_time4 = QDateTime::fromString(t_str4,"yyyy-MM-dd'T'HH:mm:ss");

        //key = date_time.toMSecsSinceEpoch()/1000.0;

        value1 = result1.value(2).toDouble();
        value2 = result2.value(2).toDouble();
        value3 = result3.value(2).toDouble();
        value4 = result4.value(2).toDouble();

        if (mode == "motor") {
            qDebug() << date_time1.toString() << " Temperature = " << value1 << " K" ;
            qDebug() << date_time2.toString() << " Temperature = " << value2 << " K" ;
            qDebug() << date_time3.toString() << " Temperature = " << value3 << " K" ;
            qDebug() << date_time4.toString() << " Temperature = " << value4 << " K" ;
        }else {
            qDebug() << "Arduino" << result1.value(0).toDouble() << " " << date_time1.toString() << " Motor Voltage = " << value1 << "V" ;
            qDebug() << "Arduino" << result2.value(0).toDouble() << " " << date_time2.toString() << " Motor Voltage = " << value2 << "V" ;
            qDebug() << "Arduino" << result3.value(0).toDouble() << " " << date_time3.toString() << " Motor Voltage = " << value3 << "V" ;
            qDebug() << "Arduino" << result4.value(0).toDouble() << " " << date_time4.toString() << " Motor Voltage = " << value4 << "V" ;
        }
        // if (key-lastPointKey >= step_size)
        // {

        int cnt = 10;

        while (cnt-- >= 0) {
            // add data to lines:
            ui->customPlot->graph(0)->addData(key, value1);

            // set data of dots:
            ui->customPlot->graph(1)->clearData();
            ui->customPlot->graph(1)->addData(key, value1);


            ui->customPlot->graph(2)->addData(key, value2);

            // set data of dots:
            ui->customPlot->graph(3)->clearData();
            ui->customPlot->graph(3)->addData(key, value2);


            ui->customPlot->graph(4)->addData(key, value3);

            // set data of dots:
            ui->customPlot->graph(5)->clearData();
            ui->customPlot->graph(5)->addData(key, value3);


            ui->customPlot->graph(6)->addData(key, value4);

            // set data of dots:
            ui->customPlot->graph(7)->clearData();
            ui->customPlot->graph(7)->addData(key, value4);



            // remove data of lines that's outside visible range:
            //ui->customPlot->graph(0)->removeDataBefore(key-range_of_graph);
            //ui->customPlot->graph(1)->removeDataBefore(key-range_of_graph);

            // rescale value (vertical) axis to fit the current data:
            //ui->customPlot->graph(0)->rescaleValueAxis();
            //ui->customPlot->graph(1)->rescaleValueAxis();

            //lastPointKey = key;
            // }

            // make key axis range scroll with the data (at a constant range size of "range_of_graph"):
            ui->customPlot->xAxis->setRange(key+step_size, range_of_graph, Qt::AlignRight);

            ui->customPlot->replot();


            // calculate frames per second:
            //        static double lastFpsKey;
            //        static int frameCount;
            //        ++frameCount;
            //        if (key-lastFpsKey > 0) // average fps over 2 seconds
            //        {
            //            ui->statusBar->showMessage(
            //                        QString("%1 FPS, Total Data points: %2")
            //                        .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
            //                        .arg(ui->customPlot->graph(0)->data()->count())
            //                        , 0);
            //            lastFpsKey = key;
            //            frameCount = 0;
            //        }


            key += step_size;

        }

    }

    //    if (value0 == 100)
    //        increase = false;

    //    if (value0 == 0)
    //        increase = true;

    //    if (increase)
    //        value0 += 10;
    //    else
    //        value0 -= 10;
}


void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
    QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif
    demoName = "Real Time Data Demo";

    // include this section to fully disable antialiasing for higher performance:
    /*
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
  */
    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    //customPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    //customPlot->graph(0)->setAntialiasedFill(false);


    customPlot->addGraph(); // blue dot
    customPlot->graph(1)->setPen(QPen(Qt::blue));
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);


    customPlot->addGraph(); // black line
    customPlot->graph(2)->setPen(QPen(Qt::black));
    //customPlot->graph(2)->setBrush(QBrush(QColor(240, 255, 200)));
    //customPlot->graph(0)->setAntialiasedFill(false);


    customPlot->addGraph(); // black dot
    customPlot->graph(3)->setPen(QPen(Qt::black));
    customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);


    customPlot->addGraph(); // green line
    customPlot->graph(4)->setPen(QPen(Qt::green));
    //customPlot->graph(4)->setBrush(QBrush(QColor(240, 255, 200)));
    //customPlot->graph(0)->setAntialiasedFill(false);


    customPlot->addGraph(); // green dot
    customPlot->graph(5)->setPen(QPen(Qt::green));
    customPlot->graph(5)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(5)->setScatterStyle(QCPScatterStyle::ssDisc);


    customPlot->addGraph(); // red line
    customPlot->graph(6)->setPen(QPen(Qt::red));
    //customPlot->graph(6)->setBrush(QBrush(QColor(240, 255, 200)));
    //customPlot->graph(0)->setAntialiasedFill(false);


    customPlot->addGraph(); // red dot
    customPlot->graph(7)->setPen(QPen(Qt::red));
    customPlot->graph(7)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(7)->setScatterStyle(QCPScatterStyle::ssDisc);

    customPlot->xAxis->setLabel("Value Index");


    customPlot->xAxis->setTickLabelType(QCPAxis::ltNumber);
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setNumberFormat("gb");
    //customPlot->xAxis->setDateTimeFormat("MM-dd-yyyy\nHH:mm:ss");
    customPlot->xAxis->setAutoTickStep(false);
    //customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickStep(2);
    customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}
