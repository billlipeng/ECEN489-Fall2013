#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <cstring>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
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

private:
    void processError(const QString &error);

private slots:
    void readResponse();
    void processTimeout();
    void realtimeDataSlot(double axr,double ayr,double azr,double axl,double ayl,double azl,double real_score);
    void on_stop_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray response;
    QTimer timer, endOfPlay;
    QTimer dataTimer;
    string rx_data = "";
    int portNumberRight = 28,portNumberLeft = 20;
    Reader readerRight = Reader(portNumberRight),readerLeft = Reader(portNumberLeft);
    vector<double> real_velocity_right,real_velocity_left;
    double real_score_right = 0.0,real_score_left = 0.0,total_score = 0.0;
    double startTime;
    bool plotSwitch = false;

};

#endif // MAINWINDOW_H
