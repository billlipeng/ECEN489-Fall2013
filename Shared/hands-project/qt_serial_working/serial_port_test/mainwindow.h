#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <qcustomplot.h>

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
    void realtimeDataSlot(double val);
    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray response;
    QTimer timer;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H
