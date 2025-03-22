#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mult = new Multiplication(this);

    N = {100, 200, 300, 400, 500};

    b_m1_1 = QVector<QVector<int>>(100, QVector<int>(100, 5));
    b_m1_2 = QVector<QVector<int>>(100, QVector<int>(100, 10));

    b_m2_1 = QVector<QVector<int>>(200, QVector<int>(200, 5));
    b_m2_2 = QVector<QVector<int>>(200, QVector<int>(200, 10));

    b_m3_1 = QVector<QVector<int>>(300, QVector<int>(300, 5));
    b_m3_2 = QVector<QVector<int>>(300, QVector<int>(300, 10));

    b_m4_1 = QVector<QVector<int>>(400, QVector<int>(400, 5));
    b_m4_2 = QVector<QVector<int>>(400, QVector<int>(400, 10));

    b_m5_1 = QVector<QVector<int>>(500, QVector<int>(500, 5));
    b_m5_2 = QVector<QVector<int>>(500, QVector<int>(500, 10));

    b1 = std::array<QVector<QVector<int>>, 5> {b_m1_1, b_m2_1, b_m3_1, b_m4_1, b_m5_1};
    b2 = std::array<QVector<QVector<int>>, 5> {b_m1_2, b_m2_2, b_m3_2, b_m4_2, b_m5_2};


    w_m1_1 = QVector<QVector<int>>(101, QVector<int>(101, 5));
    w_m1_2 = QVector<QVector<int>>(101, QVector<int>(101, 10));

    w_m2_1 = QVector<QVector<int>>(201, QVector<int>(201, 5));
    w_m2_2 = QVector<QVector<int>>(201, QVector<int>(201, 10));

    w_m3_1 = QVector<QVector<int>>(301, QVector<int>(301, 5));
    w_m3_2 = QVector<QVector<int>>(301, QVector<int>(301, 10));

    w_m4_1 = QVector<QVector<int>>(401, QVector<int>(401, 5));
    w_m4_2 = QVector<QVector<int>>(401, QVector<int>(401, 10));

    w_m5_1 = QVector<QVector<int>>(501, QVector<int>(501, 5));
    w_m5_2 = QVector<QVector<int>>(501, QVector<int>(501, 10));

    w1 = std::array<QVector<QVector<int>>, 5> {w_m1_1, w_m2_1, w_m3_1, w_m4_1, w_m5_1};
    w2 = std::array<QVector<QVector<int>>, 5> {w_m1_2, w_m2_2, w_m3_2, w_m4_2, w_m5_2};

//    QDebug dbg = qDebug().nospace().noquote();
//    for(int i = 0; i < res_m1_st.size(); i++)
//    {
//        for(int j = 0; j < res_m1_st[0].size(); j++)
//        {
//            dbg << res_m1_st[i][j] - res_m1_vin[i][j] - 1 << " ";
//        }
//        dbg << "\n";
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
// Л.С. Стандарт
    // Создаем экземпляр TimerThread
    timerThread = new StandartThread(b1, b2, N, 1, this);
    connect(timerThread, &StandartThread::resultsReady, this, &MainWindow::handleResults1);
    connect(timerThread, &StandartThread::resultsReady, timerThread, &QObject::deleteLater); // Удаляем поток после завершения
    timerThread->start();

// Л.С. Виноград
    timerThread2 = new StandartThread(b1, b2, N, 2, this);
    connect(timerThread2, &StandartThread::resultsReady, this, &MainWindow::handleResults2);
    connect(timerThread2, &StandartThread::resultsReady, timerThread2, &QObject::deleteLater); // Удаляем поток после завершения
    timerThread2->start();

// Х.С. Стандарт
    // Создаем экземпляр TimerThread
    timerThread4 = new StandartThread(w1, w2, N, 1, this);
    connect(timerThread4, &StandartThread::resultsReady, this, &MainWindow::handleResults4);
    connect(timerThread4, &StandartThread::resultsReady, timerThread4, &QObject::deleteLater); // Удаляем поток после завершения
    timerThread4->start();

// Х.С. Виноград
    timerThread5 = new StandartThread(w1, w2, N, 2, this);
    connect(timerThread5, &StandartThread::resultsReady, this, &MainWindow::handleResults5);
    connect(timerThread5, &StandartThread::resultsReady, timerThread5, &QObject::deleteLater); // Удаляем поток после завершения
    timerThread5->start();

//    qDebug() << timer_result_standart_worst[4] << " " << timer_result_vinograd_worst[4];
}

void MainWindow::handleResults1(QVector<double> result, QVector<double> N)
{
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(N, result);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget->xAxis->setLabel("N");
    ui->widget->yAxis->setLabel("t, ms");
    ui->widget->xAxis->setRange(50, 550);
    ui->widget->yAxis->setRange(0, 25000);
    ui->widget->replot();

    qDebug() << "Res 1 - 500: " << result[4];
}
void MainWindow::handleResults2(QVector<double> result, QVector<double> N)
{
    ui->widget_2->clearGraphs();
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->setData(N, result);
    ui->widget_2->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_2->xAxis->setLabel("N");
    ui->widget_2->yAxis->setLabel("t, ms");
    ui->widget_2->xAxis->setRange(50, 550);
    ui->widget_2->yAxis->setRange(0, 25000);
    ui->widget_2->replot();

    qDebug() << "Res 2 - 500: " << result[4];
}
void MainWindow::handleResults4(QVector<double> result, QVector<double> N)
{
    ui->widget_4->clearGraphs();
    ui->widget_4->addGraph();
    ui->widget_4->graph(0)->setData(N, result);
    ui->widget_4->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_4->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_4->xAxis->setLabel("N");
    ui->widget_4->yAxis->setLabel("t, ms");
    ui->widget_4->xAxis->setRange(50, 550);
    ui->widget_4->yAxis->setRange(0, 25000);
    ui->widget_4->replot();

    qDebug() << "Res 4 - 500: " << result[4];
}

void MainWindow::handleResults5(QVector<double> result, QVector<double> N)
{
    ui->widget_5->clearGraphs();
    ui->widget_5->addGraph();
    ui->widget_5->graph(0)->setData(N, result);
    ui->widget_5->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_5->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_5->xAxis->setLabel("N");
    ui->widget_5->yAxis->setLabel("t, ms");
    ui->widget_5->xAxis->setRange(50, 550);
    ui->widget_5->yAxis->setRange(0, 25000);
    ui->widget_5->replot();

    qDebug() << "Res 5 - 500: " << result[4];
}


