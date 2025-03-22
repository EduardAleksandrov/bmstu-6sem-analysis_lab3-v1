#include "standartthread.h"

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
        auto start = std::chrono::high_resolution_clock::now();
        if(K == 1)
        {
            res= mult.standart(b1[i], b2[i]);
        } else if(K == 2) {
            res = mult.vinograd(b1[i], b2[i]);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTime = (end - start) * 1000; // миллисекунды
        timer_result_standart_best.push_back(elapsedTime.count());
    }

    emit resultsReady(timer_result_standart_best, N);
}
