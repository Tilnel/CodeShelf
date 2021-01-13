/*  Author: Tilnel
    Date: 2021.1.13
    Time Complexity: O(n^3) 
    NOTICE: DIRECTED ? UNDIRECTED ?     */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n;
int edges[MAXN][MAXN];
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
        }
    }
}