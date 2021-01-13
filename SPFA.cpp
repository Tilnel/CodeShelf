/*  Author: NogiNonoka
    Date: 2021.1.12
    Time Complexity: O(V^5)
    Usage:                      */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXE = 1007; // NO DOUBLE
const int INF = 0x3f3f3f3f;

struct SPFA {
    struct Edge {
        int v, cap, cost, nxt;
    } edge[MAXE << 1]; // DOUBLE HERE

    int cntedge, sumflow;
    int head[MAXN];

    void Init() {
        cntedge = 0;
        memset(head, 0xff, sizeof(head));
    }

    void Addedge(int u, int v, int cap,
                 int cost) { // SO, in main(), only add once.
        edge[cntedge].v = v;
        edge[cntedge].cap = cap;
        edge[cntedge].cost = cost;
        edge[cntedge].nxt = head[u];
        head[u] = cntedge++;
        edge[cntedge].v = u;
        edge[cntedge].cap = 0;
        edge[cntedge].cost = -cost;
        edge[cntedge].nxt = head[v];
        head[v] = cntedge++;
    }

    int dis[MAXN], pre[MAXN];
    bool vis[MAXN];

    bool Spfa(int s, int t, int n) {
        int u, v;
        queue<int> q;
        memset(vis, 0, sizeof(vis));
        memset(pre, 0xff, sizeof(pre));
        for (int i = 0; i <= n; i++)
            dis[i] = INF;
        vis[s] = true;
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = head[u]; i != -1; i = edge[i].nxt) {
                v = edge[i].v;
                if (edge[i].cap && dis[v] > dis[u] + edge[i].cost) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dis[t] != INF;
    }

    int MinCostMaxFlow(int s, int t, int n) {
        int flow = 0;
        int minflow, mincost;
        mincost = 0;
        while (Spfa(s, t, n)) {
            minflow = INF + 1;
            for (int i = pre[t]; i != 1; i = pre[edge[i ^ 1].v]) {
                edge[i].cap -= minflow;
                edge[i ^ 1].cap += minflow;
            }
            mincost += dis[t] * minflow;
        }
        sumflow = flow;
        return mincost;
    }
} mcmf;
