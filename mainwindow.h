#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "multiplication.h"
#include "standartthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void handleResults1(QVector<double> result, QVector<double> N);
    void handleResults2(QVector<double> result, QVector<double> N);
    void handleResults4(QVector<double> result, QVector<double> N);
    void handleResults5(QVector<double> result, QVector<double> N);


private:
    Ui::MainWindow *ui;
    Multiplication *mult;
    StandartThread* timerThread;
    StandartThread* timerThread2;
    StandartThread* timerThread4;
    StandartThread* timerThread5;


    QVector<double> N;

    QVector<QVector<int>> b_m1_1;
    QVector<QVector<int>> b_m1_2;

    QVector<QVector<int>> b_m2_1;
    QVector<QVector<int>> b_m2_2;

    QVector<QVector<int>> b_m3_1;
    QVector<QVector<int>> b_m3_2;

    QVector<QVector<int>> b_m4_1;
    QVector<QVector<int>> b_m4_2;

    QVector<QVector<int>> b_m5_1;
    QVector<QVector<int>> b_m5_2;

    std::array<QVector<QVector<int>>, 5> b1;
    std::array<QVector<QVector<int>>, 5> b2;


    QVector<QVector<int>> w_m1_1;
    QVector<QVector<int>> w_m1_2;

    QVector<QVector<int>> w_m2_1;
    QVector<QVector<int>> w_m2_2;

    QVector<QVector<int>> w_m3_1;
    QVector<QVector<int>> w_m3_2;

    QVector<QVector<int>> w_m4_1;
    QVector<QVector<int>> w_m4_2;

    QVector<QVector<int>> w_m5_1;
    QVector<QVector<int>> w_m5_2;;

    std::array<QVector<QVector<int>>, 5> w1;
    std::array<QVector<QVector<int>>, 5> w2;

};
#endif // MAINWINDOW_H
