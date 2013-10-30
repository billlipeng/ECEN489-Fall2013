#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTimer>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setControlsEnabled(bool enable);
    void processError(const QString &error);

private slots:
    //void sendRequest();
    void readResponse();
    void processTimeout();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray response;
    QTimer timer;
};

#endif // MAINWINDOW_H
