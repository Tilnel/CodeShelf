/*  Author: NogiNonoka
    Date: 2021.1.13     */

#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    static int l;
    static const int MAXL = 10 + 3;

    int matrix[MAXL][MAXL];

    void Null_Matrix() { memset(matrix, 0, sizeof(matrix)); }

    void E_Matrix() {
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= l; ++i) {
            matrix[i][i] = 1;
        }
    }

    void ShowMatrix() {
        for (int i = 1; i <= Matrix::l; ++i) {
            for (int j = 1; j <= Matrix::l; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    Matrix operator * (const Matrix &b) {
        Matrix c;
        c.Null_Matrix();
        for (int i = 1; i <= l; ++i) 
            for (int j = 1; j <= l; ++j) 
                for (int k = 1; k <= l; ++k) 
                    c.matrix[i][j] = c.matrix[i][j] + matrix[i][k] * b.matrix[k][j];
        return c;
    }
};

Matrix MatrixPow(Matrix a, int b) {
    Matrix res;
    res.E_Matrix();
    for ( ; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}