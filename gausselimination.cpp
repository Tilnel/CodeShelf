#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define D double
D a[MAXN][MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 1; ++j)
            scanf("%lf", &a[i][j]);
    for (int i = 1; i <= n; ++i) {
        int max = i;
        for (int j = i + 1; j <= n; ++j) {
            if (fabs(a[j][i]) > fabs(a[max][i])) max = j;
        }
        for (int j = 1; j <= n + 1; ++j)
            swap(a[i][j], a[max][j]);
        if (!a[i][i]) {
            puts("No\n");
            return 0;
        }
        for (int j = 1; j <= n; ++j) {
            if (j != i) {
                D temp = a[j][i] / a[i][i];
                for (int k = i + 1; k <= n + 1; ++k)
                    a[j][k] -= a[i][k] * temp;
            }
        }
    }
    puts("Yes\n");
    for (int i = 1; i <= n; ++i) {
        printf("%.7lf\n", a[i][n + 1] / a[i][i]);
    }
    return 0;
}
