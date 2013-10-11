
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>

using namespace std;
const int input = 4;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setGeometry(400, 250, 542, 390);
  
  setupDemo(1);
  //setupPlayground(ui->customPlot);
  // 0:  setupQuadraticDemo(ui->customPlot);
  // 1:  setupSimpleDemo(ui->customPlot);
  // 2:  setupSincScatterDemo(ui->customPlot);
  // 3:  setupScatterStyleDemo(ui->customPlot);
  // 4:  setupScatterPixmapDemo(ui->customPlot);
  // 5:  setupLineStyleDemo(ui->customPlot);
  // 6:  setupDateDemo(ui->customPlot);
  // 7:  setupTextureBrushDemo(ui->customPlot);
  // 8:  setupMultiAxisDemo(ui->customPlot);
  // 9:  setupLogarithmicDemo(ui->customPlot);
  // 10: setupRealtimeDataDemo(ui->customPlot);
  // 11: setupParametricCurveDemo(ui->customPlot);
  // 12: setupBarChartDemo(ui->customPlot);
  // 13: setupStatisticalDemo(ui->customPlot);
  // 14: setupSimpleItemDemo(ui->customPlot);
  // 15: setupItemDemo(ui->customPlot);
  // 16: setupStyledDemo(ui->customPlot);
  // 17: setupAdvancedAxesDemo(ui->customPlot);
  // 18: setupAdvancedAxesDemo(ui->customPlot);
  
  // for making screenshots of the current demo or all demos (for website screenshots):
  //QTimer::singleShot(1500, this, SLOT(allScreenShots()));
  //QTimer::singleShot(1000, this, SLOT(screenShot()));
}

void MainWindow::setupDemo(int demoIndex)
{
  switch (demoIndex)
  {
        case 1: setupArduinoRead(ui->customPlot); break;
  }
  setWindowTitle("QCustomPlot: "+demoName);
  statusBar()->clearMessage();
  currentDemoIndex = demoIndex;
  ui->customPlot->replot();
}

void MainWindow::setupArduinoRead(QCustomPlot *customPlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif
  demoName = "Real Time Data";
  int cnt = 0;
  int cnt1 = 0;
  int h[input+1];
  h[0] = 0;
  int s = 230;
  int v = 178;
  int a = 255;
  QPen colr[input];
  while (cnt < input){
      h[cnt+1] = (h[cnt] + 50) % 360;

      colr[cnt] = QPen(QColor::fromHsv(h[cnt], s, v, a));
      cnt = cnt +1;
  }

  while (cnt1 < input){
  customPlot->addGraph();
  customPlot->graph(cnt1)->setPen(colr[cnt1]);
  cnt1 = cnt1 + 1;
  }

  customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
  customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
  customPlot->xAxis->setAutoTickStep(false);
  customPlot->xAxis->setTickStep(2);
  customPlot->axisRect()->setupFullAxesBox();

  customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
  customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
  customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
  customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
  customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
  customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
  customPlot->xAxis->setTickLabelColor(Qt::white);
  customPlot->yAxis->setTickLabelColor(Qt::white);
  QLinearGradient plotGradient;
  plotGradient.setStart(0, 0);
  plotGradient.setFinalStop(0, 350);
  plotGradient.setColorAt(0, QColor(80, 80, 80));
  plotGradient.setColorAt(1, QColor(50, 50, 50));
  customPlot->setBackground(plotGradient);
  QLinearGradient axisRectGradient;
  axisRectGradient.setStart(0, 0);
  axisRectGradient.setFinalStop(0, 350);
  axisRectGradient.setColorAt(0, QColor(80, 80, 80));
  axisRectGradient.setColorAt(1, QColor(30, 30, 30));
  customPlot->axisRect()->setBackground(axisRectGradient);

  customPlot->legend->setVisible(true);
  customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
  customPlot->legend->setBrush(QColor(255, 255, 255, 200));
  QPen legendPen;
  legendPen.setColor(QColor(130, 130, 130, 200));
  customPlot->legend->setBorderPen(legendPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  customPlot->legend->setFont(legendFont);
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

void MainWindow::realtimeDataSlot()
{
  // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  double key = 0;
#else
  double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.01) // at most add point every 10 ms
  {
    int cnt2 = 0;
    double value[input];
//    double value[2];
//    double value0 = qTan(qreal(key)); //sin(key*1.6+cos(key*1.7)*2)*10 + sin(key*1.2+0.56)*20 + 26;
//    double value1 = 0.5*qCos(key); //sin(key*1.3+cos(key*1.2)*1.2)*7 + sin(key*0.9+0.26)*24 + 26;
//    double value2 = qSin(key);
//    double value3 = qCos(key);

    while (cnt2 < input){
        value[cnt2] = (1+0.02*cnt2)*qSin(key*(1+0.00002*cnt2));
        ui->customPlot->graph(cnt2)->addData(key, value[cnt2]);
        ui->customPlot->graph(cnt2)->removeDataBefore(key-8);
        ui->customPlot->graph(cnt2)->rescaleValueAxis();
//        if (cnt2 == 0){
//            ui->customPlot->graph(cnt2)->rescaleValueAxis(true);
//        }
//        else {
//            ui->customPlot->graph(cnt2)->rescaleValueAxis();
//        }
        cnt2 = cnt2 + 1;
    }
    // add data to lines:
//    ui->customPlot->graph(0)->addData(key, value0);
//    ui->customPlot->graph(1)->addData(key, value1);
//    ui->customPlot->graph(2)->addData(key, value2);
//    ui->customPlot->graph(3)->addData(key, value3);
    // set data of dots:
//    ui->customPlot->graph(4)->clearData();
//    ui->customPlot->graph(4)->addData(key, value0);
//    ui->customPlot->graph(5)->clearData();
//    ui->customPlot->graph(5)->addData(key, value1);
//    ui->customPlot->graph(6)->clearData();
//    ui->customPlot->graph(6)->addData(key, value2);
//    ui->customPlot->graph(7)->clearData();
//    ui->customPlot->graph(7)->addData(key, value3);
    // remove data of lines that's outside visible range:
//    ui->customPlot->graph(0)->removeDataBefore(key-8);
//    ui->customPlot->graph(1)->removeDataBefore(key-8);
//    ui->customPlot->graph(2)->removeDataBefore(key-8);
//    ui->customPlot->graph(3)->removeDataBefore(key-8);
    // rescale value (vertical) axis to fit the current data:
//    ui->customPlot->graph(0)->rescaleValueAxis(true);
//    ui->customPlot->graph(1)->rescaleValueAxis();
//    ui->customPlot->graph(2)->rescaleValueAxis();
//    ui->customPlot->graph(3)->rescaleValueAxis();
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
  ui->customPlot->replot();
  
  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

void MainWindow::bracketDataSlot()
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  double secs = 0;
#else
  double secs = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
  
  // update data to make phase move:
  int n = 500;
  double phase = secs*5;
  double k = 3;
  QVector<double> x(n), y(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = i/(double)(n-1)*34 - 17;
    y[i] = qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
  }
  ui->customPlot->graph()->setData(x, y);
  
  itemDemoPhaseTracer->setGraphKey((8*M_PI+fmod(M_PI*1.5-phase, 6*M_PI))/k);
  
  ui->customPlot->replot();
  
  // calculate frames per second:
  double key = secs;
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->customPlot->graph(0)->data()->count())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

void MainWindow::setupPlayground(QCustomPlot *customPlot)
{
  Q_UNUSED(customPlot)
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::screenShot()
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
  QPixmap pm = QPixmap::grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#else
  QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#endif
  QString fileName = demoName.toLower()+".png";
  fileName.replace(" ", "");
  pm.save("./screenshots/"+fileName);
  qApp->quit();
}

void MainWindow::allScreenShots()
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
  QPixmap pm = QPixmap::grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#else
  QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#endif
  QString fileName = demoName.toLower()+".png";
  fileName.replace(" ", "");
  pm.save("./screenshots/"+fileName);

  if (currentDemoIndex < 17)
  {
    if (dataTimer.isActive())
      dataTimer.stop();
    dataTimer.disconnect();
    delete ui->customPlot;
    ui->customPlot = new QCustomPlot(ui->centralWidget);
    ui->verticalLayout->addWidget(ui->customPlot);
    setupDemo(currentDemoIndex+1);
    // setup delay for demos that need time to develop proper look:
    int delay = 250;
    if (currentDemoIndex == 10) // Next is Realtime data demo
      delay = 12000;
    else if (currentDemoIndex == 15) // Next is Item demo
      delay = 5000;
    QTimer::singleShot(delay, this, SLOT(allScreenShots()));
  } else
  {
    qApp->quit();
  }
}







































