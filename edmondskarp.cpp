/*  Author: NogiNonoka
    Date: 2021.1.13 */
    
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 205;

struct EdmondsKarp {
    int s, t;
    int num;
    int capacity[MAXN][MAXN];
    int flow[MAXN][MAXN];

    int res[MAXN];
    int pre[MAXN];

    void Init() {
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));
        memset(pre, 0, sizeof(pre));
    }

    bool Bfs() {
        queue<int> q;
        memset(res, 0, sizeof(res));
        res[s] = INF;
        pre[s] = -1;
        q.push(s);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i <= num; ++i) {
                if (!res[i] && flow[now][i] < capacity[now][i]) {
                    q.push(i);
                    res[i] = min(res[now], capacity[now][i] - flow[now][i]);
                    pre[i] = now;
                    if (i == t)
                        return true;
                    if (res[i] == 0)
                        break;
                }
            }
        }
        return false;
    }

    int edmondskarp() {
        int ans = 0;
        while (Bfs()) {
            for (int i = t; i != -1; i = pre[i]) {
                flow[pre[i]][i] += res[t];
                flow[i][pre[i]] -= res[t];
            }
            ans += res[t];
        }
        return ans;
    }
} ek;

int main() {
    int T, m;
    scanf("%d", &T);
    while (T--) {
        ek.Init();
        scanf("%d%d", &ek.num, &m);
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            ek.capacity[u][v] = 1;
            ek.capacity[v][u] = 1;
        }
        int A, B, S;
        scanf("%d%d%d", &A, &B, &S);
        ek.s = ek.num;
        ek.t = B;
        ek.capacity[ek.s][A] = 1;
        ek.capacity[A][ek.s] = 1;
        ek.capacity[ek.s][S] = 1;
        ek.capacity[S][ek.s] = 1;
        int tmp;
        tmp = ek.edmondskarp();
        if (tmp >= 2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}