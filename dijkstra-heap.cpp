/*  Author: NogiNonoka
    Date: 2021.1.13
    Time Complexity: O(ElogV)   */

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1007;

struct Dijkstra_Heap {
    int n;
    int s, t;
    vector<pair<int, int>> graph[MAXN];
    int dis[MAXN];

    void dijkstra() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dis[s] = 0;
        que.push({dis[s], s});
        while (!que.empty()) {
            int now = que.top().second;
            int tmpval = que.top().first;
            que.pop();
            if (dis[now] < tmpval) continue;
            for (int i = 0; i < graph[now].size(); i++) {
                int nxt = graph[now][i].first;
                int val = graph[now][i].second;
                if (dis[nxt] > val + dis[now]) {
                    dis[nxt] = val + dis[now];
                    que.push({dis[nxt], nxt});
                }
            }
        }
        return;
    }
} djk;