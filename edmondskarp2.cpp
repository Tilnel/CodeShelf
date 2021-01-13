/*  Author: McHf@luogu.com
    Date: 2021.1.13
    Time Complexity: O(VE^2)    */

#include <bits/stdc++.h>
#define up(l, r, i) for (register int i = l; i <= r; ++i)
#define erg(u) for (int i = head[u], v = ver[i]; i; i = nxt[i], v = ver[i])
const int INF = 2147483647;
const int MAXN = 10000 + 3, MAXM = 100000 + 3;
using namespace std;
bool vis[MAXN];
int n, m, s, t, tot = 1, U, V, K, ans;
int head[MAXN], nxt[MAXM * 2], ver[MAXM * 2], val[MAXM * 2];
inline void add(int u, int v, int k) {
    ver[++tot] = v, val[tot] = k, nxt[tot] = head[u], head[u] = tot;
    ver[++tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot;
}
int q[MAXN][4], front, rear;
inline int EK() {
    memset(vis, 0, sizeof(vis)), vis[s] = true;
    front = rear = 1, q[rear][0] = s, q[rear++][3] = INF;
    for (int u = q[front][0]; front < rear; u = q[++front][0])
        erg(u) {                        
            if (!vis[v] && val[i] > 0) { 
                q[rear][0] = v, q[rear][1] = i, q[rear][2] = front,
                q[rear++][3] = min(val[i], q[front][3]), vis[v] = true;
                if (v == t)
                    goto end;
            }
        }
    return false;
end:
    rear--;
    for (int i = rear, flw = q[rear][3]; q[i][2]; i = q[i][2])
        val[q[i][1]] -= flw, val[q[i][1] ^ 1] += flw;
    return q[rear][3];
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t), vis[s] = true;
    up(1, m, i) scanf("%d%d%d", &U, &V, &K), add(U, V, K);
    for (int p; p = EK();)
        ans += p;
    printf("%d\n", ans);
    return 0;
}