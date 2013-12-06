#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <cstring>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QString>
#include <QSqlDatabase>
#include <qcustomplot.h>
#include <Reading.h>
#include <Reader.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    void setupRealtimeScoreDemo(QCustomPlot *scorePlot);
    void setupCircle(QCustomPlot *circlePlot);
    void setupPing(QCustomPlot *pingPlot);
    void setupBarChart(QCustomPlot *barPlot);
    void keyPressEvent(QKeyEvent *e);

private:
    void processError(const QString &error);

private slots:
    void readResponse();
    void processTimeout();
    void realtimeDataSlot(double axr,double ayr,double azr,double axl,double ayl,double azl,double real_score,double pingRight,double pingLeft);
    void on_stop_clicked();
    void end_of_trial();
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_start_clicked();
    void plotBars(QCustomPlot *barPlot,QVector<double> scores);
    void fetchMaxMean(QString query,QVector<double> &scores);
    void fetchMedian(QString query,QVector<double> &scores);
    void plotContributionBars();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QSerialPort serial;
    QByteArray response;
    QTimer timer, endOfPlay;
    QTimer dataTimer;
    string rx_data = "";
    int portNumberRightPing = 43,portNumberLeftPing = 44;

    int portNumberRightIMU = 36,portNumberLeftIMU = 34;
    int trialNumber = 0;

    Reader readerRight = Reader(portNumberRightIMU,IMU),readerLeft = Reader(portNumberLeftIMU,IMU);
    Reader readerRightPing = Reader(portNumberRightPing,Ping),readerLeftPing = Reader(portNumberLeftPing,Ping);

    vector<double> real_velocity_right,real_velocity_left;
    double real_score_right = 0.0,real_score_left = 0.0,total_score = 0.0;
    double score_right_rvlh = 0.0,score_left_rvlh = 0.0,score_rvlh = 0.0;
    double score_right_lvrh = 0.0,score_left_lvrh = 0.0,score_lvrh = 0.0;
    double score_right_total = 0.0,score_left_total = 0.0,score_total = 0.0;
    double startTime, key_x = 0;
    bool plotSwitch = false,inserted = false;
    QString major,gender,domHand;
    int age;
    int duration = 20;
    double pingDistance = 100;

};

#endif // MAINWINDOW_H
