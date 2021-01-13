/*  Author: NogiNonoka
    Date: 2021.1.13
    Time Complexity: O(n)   */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 9;
int prime[MAXN];
bool vis[MAXN];

void GetPrime(int n) {
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime[++prime[0] = i;
        for (int j = 1; j <= prime[0] && i <= n / prime[j]; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}