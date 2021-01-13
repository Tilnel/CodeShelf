/*  Author: NogiNonoka
    Date: 2021.1.13
    Time Complexity: O(VE)  */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
struct Hungarian {
    int n, m;
    bool graph[MAXN][MAXN];
    int lnk[MAXN];
    bool vis[MAXN];

    void Init() {
        memset(graph, 0, sizeof(graph));
        memset(lnk, 0, sizeof(lnk));
        memset(vis, 0, sizeof(vis));
    }

    bool Dfs(int x) {
        for (int i = 1; i <= n; i++) {
            if (graph[x][i] && !vis[i]) {
                vis[i] = true;
                if (lnk[i] == 0 || Dfs(lnk[i])) {
                    lnk[i] = x;
                    return true;
                }
            }
        }
        return false;
    }

    int hungarian() {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            if (Dfs(i)) ans++;
        }
        return ans;
    }
} hgr;