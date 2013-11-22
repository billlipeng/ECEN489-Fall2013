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
    void keyPressEvent(QKeyEvent *e);

private:
    void processError(const QString &error);

private slots:
    void readResponse();
    void processTimeout();
    void realtimeDataSlot(double axr,double ayr,double azr,double axl,double ayl,double azl,double real_score);
    void on_stop_clicked();
    void end_of_trial();
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QSerialPort serial;
    QByteArray response;
    QTimer timer, endOfPlay;
    QTimer dataTimer;
    string rx_data = "";
    int portNumberRight = 28,portNumberLeft = 20;
    Reader readerRight = Reader(portNumberRight),readerLeft = Reader(portNumberLeft);
    vector<double> real_velocity_right,real_velocity_left;
    double real_score_right = 0.0,real_score_left = 0.0,total_score = 0.0;
    double score_right_rvlh = 0.0,score_left_rvlh = 0.0,score_rvlh = 0.0;
    double score_right_lvrh = 0.0,score_left_lvrh = 0.0,score_lvrh = 0.0;
    double score_right_total = 0.0,score_left_total = 0.0,score_total = 0.0;
    double startTime, key_x = 0;
    bool plotSwitch = false;
    QString major,gender,domHand;
    int age, trialNumber = 0;

};

#endif // MAINWINDOW_H
