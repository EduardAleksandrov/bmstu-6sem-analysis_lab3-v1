#include "standartthread.h"
#include <QDebug>

StandartThread::StandartThread(std::array<QVector<QVector<int>>, 5>& matrix1,
                               std::array<QVector<QVector<int>>, 5>& matrix2,
                               QVector<double>& n,
                               int k,
                               QObject* parent): QThread(parent), b1(matrix1), b2(matrix2), N(n), K(k) {}

void StandartThread::run()
{
    Multiplication mult;
    for(int i = 0; i < N.size(); i++)
    {
        QVector<QVector<int>> res;
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;
        try
        {
            if(K == 1)
            {
                start = std::chrono::high_resolution_clock::now();
                res= mult.standart(b1[i], b2[i]);
                end = std::chrono::high_resolution_clock::now();
            } else if(K == 2) {
                start = std::chrono::high_resolution_clock::now();
                res = mult.vinograd(b1[i], b2[i]);
                end = std::chrono::high_resolution_clock::now();
            } else {
                start = std::chrono::high_resolution_clock::now();
                res = mult.vinograd_optim(b1[i], b2[i]);
                end = std::chrono::high_resolution_clock::now();
            }
        }
        catch (const std::exception& err)
        {
            qDebug() << "Error!!!";
        }
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_standart_best.push_back(elapsedTime.count());
    }

    emit resultsReady(timer_result_standart_best, N);
}
