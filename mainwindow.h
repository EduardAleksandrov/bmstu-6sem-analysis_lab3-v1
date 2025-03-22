#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "multiplication.h"

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


private:
    Ui::MainWindow *ui;
    Multiplication *mult;

};
#endif // MAINWINDOW_H
