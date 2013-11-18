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
    void realtimeDataSlot(double ax,double ay,double az,double real_score);
    void on_stop_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray response;
    QTimer timer, endOfPlay;
    QTimer dataTimer;
    string rx_data = "";
    int portNumber = 20;
    Reader reader = Reader(portNumber);
    vector<double> real_velocity;
    double real_score = 0.0;
    double startTime;
    bool plotSwitch = false;

};

#endif // MAINWINDOW_H
