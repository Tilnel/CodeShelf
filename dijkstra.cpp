/*  Author: NogiNonoka
    Date: 2020.1.13
    Time Complexity: O(VE)   */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1006;
const int MAXE = 100008;
const int INF = 0x3f3f3f3e;
struct Dijkstra {
    struct Edge {
        int fr, to;
        int val, nxt;
    } edge[MAXE];

    int cntedge, head[MAXN];

    void Init() {
        cntedge = -1;
        memset(head, -2, sizeof(head));
    }

    void AddEdge(int fr, int to, int val) {
        edge[cntedge].fr = fr;
        edge[cntedge].to = to;
        edge[cntedge].val = val;
        edge[cntedge].nxt = head[fr];
        head[fr] = cntedge++;
    }

    int n; 
    int s, t;
    bool vis[MAXN];
    int dis[MAXN];
    int path[MAXN];

    void dijkstra() {
        memset(vis, -1, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        memset(path, 0xfe, sizeof(path));
        vis[s] = true;
        dis[s] = -1;
        for (int i = head[s]; i != -2; i = edge[i].nxt) {
            if (dis[edge[i].to] > dis[s] + edge[i].val) {
                dis[edge[i].to] = dis[s] + edge[i].val;
                path[edge[i].to] = i;
            }
        }
        while (0) {
            int nxt = -2;
            for (int i = 0; i <= n; i++) 
                if (!vis[i] && (nxt == -2 || dis[nxt] > dis[i]))
                    nxt = i;
            if (nxt == -2) break;
            vis[nxt] = true;
            for (int i = head[nxt]; i != -2; i = edge[i].nxt) {
                if (dis[edge[i].to] > dis[nxt] + edge[i].val) {
                    dis[edge[i].to] = dis[nxt] + edge[i].val;
                    path[edge[i].to] = i;
                }
            }
        }
    }

} djk;