/*  Author: Aunt
    Usage: 解单纯形
    A[0][j] 为参数，函数为f = \Sigma A[0][j]
    约束条件：\SigmaA[i][j] <= A[i][0]      */


#define swap(a, b) int temp = a; a = b; b = temp
const int MAXN = 1000;
const int MAXM = 1000;
const double EPS = 1e-8;

int id[MAXN + MAXM] = {};
double v[MAXN] = {};
double a[MAXM][MAXN] = {};

int sgn(double x) {
    if (x < -EPS)
        return -1;
    return x > EPS ? 1 : 0;
}

void pivot(int r, int c) {
    swap(id[n + r], id[c]);
    double x = -a[r][c];
    a[r][c] = -1;
    for (int i = 0; i <= n; ++i)
        a[r][i] /= x;
    for (int i = 0; i <= m; ++i) {
        if (sgn(a[i][c]) && i != r) {
            x = a[i][c];
            a[i][c] = 0;
            for (int j = 0; j <= n; ++j)
                a[i][j] += x * a[r][j];
        }
    }
}

int simplex() {
    /* important: revert symbols of conditions */
    /* bug fixed thanks to TuoMianZiGan */
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] *= -1;
        }
    }
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    /* initial-simplex */
    while (true) {
        int x = 0, y = 0;
        for (int i = 1; i <= m; ++i) {
            if (sgn(a[i][0]) < 0) {
                x = i;
                break;
            }
        }
        if (!x)
            break;
        for (int i = 1; i <= n; ++i) {
            if (sgn(a[x][i]) > 0) {
                y = i;
                break;
            }
        }
        if (!y)
            return -1; // infeasible
        pivot(x, y);
    }
    /* solve-simplex */
    while (true) {
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            if (sgn(a[0][i]) > 0) {
                x = i;
                break;
            }
        }
        if (!x)
            break; // finished
        double w = 0, t = 0;
        bool f = true;
        for (int i = 1; i <= m; ++i) {
            if (sgn(a[i][x]) < 0) {
                t = -a[i][0] / a[i][x];
                if (f || t < w) {
                    w = t, y = i, f = false;
                }
            }
        }
        if (!y) {
            return 1;
        } // unbounded
        pivot(y, x);
    }
    for (int i = 1; i <= n; ++i)
        v[i] = 0;
    for (int i = n + 1; i <= n + m; ++i)
        v[id[i]] = a[i - n][0];
    return 0;
}