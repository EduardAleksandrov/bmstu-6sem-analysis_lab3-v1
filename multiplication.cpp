#include "multiplication.h"


Multiplication::Multiplication(QObject *parent) : QObject(parent)
{

}

QVector<QVector<int>> Multiplication::standart(QVector<QVector<int>>& matrix1, QVector<QVector<int>>& matrix2)
{
    int n1 = matrix1.size();
    int m1 = matrix1.back().size();

    int n2 = matrix2.size();
    int m2 = matrix2.back().size();

    QVector<QVector<int>> result(n1, QVector<int>(m2, 0));

    if(m1 != n2) return result;

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < m1; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];

    return result;
}

QVector<QVector<int>> Multiplication::vinograd(QVector<QVector<int>>& matrix1, QVector<QVector<int>>& matrix2)
{
    int n1 = matrix1.size();
    int m1 = matrix1.back().size();

    int n2 = matrix2.size();
    int m2 = matrix2.back().size();

    QVector<int> mulH(n1, 0);
    QVector<int> mulV(m2, 0);

    QVector<QVector<int>> result(n1, QVector<int>(m2, 0));

    if(m1 != n2) return result;

    for (int i = 0; i < n1; i++)
    {
        for (int k = 0; k < m1 / 2; k++)
        {
            mulH[i] = mulH[i] + matrix1[i][2 * k] * matrix1[i][2 * k + 1];
        }
    }

    for (int i = 0; i < m2; i++)
    {
        for (int k = 0; k < n2 / 2; k++)
        {
            mulV[i] = mulV[i] + matrix2[2 * k][i] * matrix2[2 * k + 1][i];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            result[i][j] = - mulH[i] - mulV[j];
            for (int k = 0; k < m1 / 2; k++)
            {
                result[i][j] = result[i][j] + (matrix1[i][2 * k + 1] + matrix2[2 * k][j]) * (matrix1[i][2 * k] + matrix2[2 * k + 1][j]);
            }
        }
    }

    if (m1 % 2)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                result[i][j] = result[i][j] + matrix1[i][m1 - 1] * matrix2[m1 - 1][j];
            }
        }
    }

    return result;
}
