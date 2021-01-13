/*  Author: NogiNonoka
    Date: 2021.1.13
    Time Complexity: O(V^2) */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
struct Prim {
    int n, m;
    int graph[MAXN][MAXN];
    int dis[MAXN];
    bool vis[MAXN];

    void Init() {
        memset(graph, 0x3f, sizeof(graph));
        memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
    }
    int prim() {
        int now = 1;
        int sum = 0;
        vis[now] = true;
        for (int i = 1; i <= n; i++) {
            dis[i] = graph[now][i];
        }
        for (int i = 2; i <= n; i++) {
            int min = INF;
            for (int nxt = 1; nxt <= n; nxt++) {
                if (!vis[nxt] && dis[nxt] < min) {
                    now = nxt;
                    min = dis[nxt];
                }
            }
            vis[now] = true;
            sum += min;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && graph[now][j] < dis[j]) {
                    dis[j] = graph[now][j];
                }
            }
        }
        return sum;
    }
} pr;

int main() {
	pr.Init();
    int u, v, w;
    scanf("%d%d", &pr.n, &pr.m);
    for (int i = 0; i < pr.m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        pr.graph[v][u] = pr.graph[u][v] = min(pr.graph[u][v], w);
		//  注意梨脯。。。。草
    }
    int res = pr.prim();
    for (int i = 1; i <= pr.n; i++) {
        if (!pr.vis[i]) {
            printf("orz\n");
            return 0;
        }
    }
    printf("%d\n", res);
	return 0;
}