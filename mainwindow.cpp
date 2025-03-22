#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mult = new Multiplication(this);



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
    QVector<double> N {100, 200, 300, 400, 500};


    QVector<QVector<int>> b_m1_1(100, QVector<int>(100, 5));
    QVector<QVector<int>> b_m1_2(100, QVector<int>(100, 10));

    QVector<QVector<int>> b_m2_1(200, QVector<int>(200, 5));
    QVector<QVector<int>> b_m2_2(200, QVector<int>(200, 10));

    QVector<QVector<int>> b_m3_1(300, QVector<int>(300, 5));
    QVector<QVector<int>> b_m3_2(300, QVector<int>(300, 10));

    QVector<QVector<int>> b_m4_1(400, QVector<int>(400, 5));
    QVector<QVector<int>> b_m4_2(400, QVector<int>(400, 10));

    QVector<QVector<int>> b_m5_1(500, QVector<int>(500, 5));
    QVector<QVector<int>> b_m5_2(500, QVector<int>(500, 10));

    QVector<QVector<int>> b1[] {b_m1_1, b_m2_1, b_m3_1, b_m4_1, b_m5_1};
    QVector<QVector<int>> b2[] {b_m1_2, b_m2_2, b_m3_2, b_m4_2, b_m5_2};


    QVector<QVector<int>> w_m1_1(101, QVector<int>(101, 5));
    QVector<QVector<int>> w_m1_2(101, QVector<int>(101, 10));

    QVector<QVector<int>> w_m2_1(201, QVector<int>(201, 5));
    QVector<QVector<int>> w_m2_2(201, QVector<int>(201, 10));

    QVector<QVector<int>> w_m3_1(301, QVector<int>(301, 5));
    QVector<QVector<int>> w_m3_2(301, QVector<int>(301, 10));

    QVector<QVector<int>> w_m4_1(401, QVector<int>(401, 5));
    QVector<QVector<int>> w_m4_2(401, QVector<int>(401, 10));

    QVector<QVector<int>> w_m5_1(501, QVector<int>(501, 5));
    QVector<QVector<int>> w_m5_2(501, QVector<int>(501, 10));

    QVector<QVector<int>> w1[] {w_m1_1, w_m2_1, w_m3_1, w_m4_1, w_m5_1};
    QVector<QVector<int>> w2[] {w_m1_2, w_m2_2, w_m3_2, w_m4_2, w_m5_2};

// Л.С. Стандарт
    QVector <double> timer_result_standart_best;
    for(int i = 0; i < N.size(); i++)
    {
        QVector<QVector<int>> res_m1_st;
        auto start = std::chrono::high_resolution_clock::now();
        res_m1_st = mult->standart(b1[i], b2[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_standart_best.push_back(elapsedTime.count());
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(N, timer_result_standart_best);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget->xAxis->setLabel("N");
    ui->widget->yAxis->setLabel("t, ms");
    ui->widget->xAxis->setRange(50, 550);
    ui->widget->yAxis->setRange(0, 20000);
    ui->widget->replot();

// Л.С. Виноград
    QVector <double> timer_result_vinograd_best;
    for(int i = 0; i < N.size(); i++)
    {
        QVector<QVector<int>> res_m1_vin;
        auto start = std::chrono::high_resolution_clock::now();
        res_m1_vin = mult->vinograd(b1[i], b2[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_vinograd_best.push_back(elapsedTime.count());
    }
    ui->widget_2->clearGraphs();
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->setData(N, timer_result_vinograd_best);
    ui->widget_2->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_2->xAxis->setLabel("N");
    ui->widget_2->yAxis->setLabel("t, ms");
    ui->widget_2->xAxis->setRange(50, 550);
    ui->widget_2->yAxis->setRange(0, 20000);
    ui->widget_2->replot();

    qDebug() << timer_result_standart_best[4] << " " << timer_result_vinograd_best[4];

// Х.С. Стандарт
    QVector <double> timer_result_standart_worst;
    for(int i = 0; i < N.size(); i++)
    {
        QVector<QVector<int>> res_m1_st;
        auto start = std::chrono::high_resolution_clock::now();
        res_m1_st = mult->standart(w1[i], w2[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_standart_worst.push_back(elapsedTime.count());
    }

    ui->widget_4->clearGraphs();
    ui->widget_4->addGraph();
    ui->widget_4->graph(0)->setData(N, timer_result_standart_worst);
    ui->widget_4->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_4->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_4->xAxis->setLabel("N");
    ui->widget_4->yAxis->setLabel("t, ms");
    ui->widget_4->xAxis->setRange(50, 550);
    ui->widget_4->yAxis->setRange(0, 20000);
    ui->widget_4->replot();

// Х.С. Виноград
    QVector <double> timer_result_vinograd_worst;
    for(int i = 0; i < N.size(); i++)
    {
        QVector<QVector<int>> res_m1_vin;
        auto start = std::chrono::high_resolution_clock::now();
        res_m1_vin = mult->vinograd(w1[i], w2[i]);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_vinograd_worst.push_back(elapsedTime.count());
    }
    ui->widget_5->clearGraphs();
    ui->widget_5->addGraph();
    ui->widget_5->graph(0)->setData(N, timer_result_vinograd_worst);
    ui->widget_5->graph(0)->setPen(QColor(50, 50, 50, 255));
    //    ui->widget_11->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget_5->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 5));
    ui->widget_5->xAxis->setLabel("N");
    ui->widget_5->yAxis->setLabel("t, ms");
    ui->widget_5->xAxis->setRange(50, 550);
    ui->widget_5->yAxis->setRange(0, 20000);
    ui->widget_5->replot();

    qDebug() << timer_result_standart_worst[4] << " " << timer_result_vinograd_worst[4];



}

