#ifndef STANDARTTHREAD_H
#define STANDARTTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <chrono>
#include "multiplication.h"

class StandartThread : public QThread
{
    Q_OBJECT
public:
    explicit StandartThread(std::array<QVector<QVector<int>>, 5>& matrix1,
                            std::array<QVector<QVector<int>>, 5>& matrix2,
                            QVector<double>& n,
                            int k,
                            QObject* parent = nullptr);


protected:
    void run() override;
signals:
    void resultsReady(QVector<double> results, QVector<double> N);

private:
    std::array<QVector<QVector<int>>, 5> b1;
    std::array<QVector<QVector<int>>, 5> b2;
    QVector<double>& N;
    QVector<double> timer_result_standart_best;
    int K;

};

#endif // STANDARTTHREAD_H
