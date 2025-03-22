#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <QObject>
#include <QVector>

class Multiplication : public QObject
{
    Q_OBJECT
public:
    explicit Multiplication(QObject *parent = nullptr);
    QVector<QVector<int>> standart(QVector<QVector<int>>& matrix1, QVector<QVector<int>>& matrix2);
    QVector<QVector<int>> vinograd(QVector<QVector<int>>& matrix1, QVector<QVector<int>>& matrix2);


signals:

};

#endif // MULTIPLICATION_H
