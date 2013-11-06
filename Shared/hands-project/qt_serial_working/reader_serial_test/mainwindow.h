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

private:
    void processError(const QString &error);

private slots:
    void readResponse();
    void processTimeout();
    void realtimeDataSlot(double ax,double ay,double az);
    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray response;
    QTimer timer;
    QTimer dataTimer;
    string rx_data = "";
    Reader reader = Reader(13);

};

#endif // MAINWINDOW_H
