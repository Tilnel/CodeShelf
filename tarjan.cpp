/*  Author: Tilnel
    Date: 2021.1.13 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1007;

struct Tarjan {
    // Strongly Connected Components in Directed Graph
    // In Undirected Graph Use Pre for Check father
    // Use dfn[] to traverse Disconnected Graph
    // Time Complexity: O(V+E)
    int n;         // Num of Node
    int ts = 0;    // Time Stamp
    int dfn[MAXN]; // Dfs Order
    int low[MAXN];
    int belong[MAXN]; // Componet ID
    bool vis[MAXN];
    vector<int> edges[MAXN];
    stack<int> s;
    int cnt = 0;

    void init(int n) {
        this->n = n;
        this->cnt = 0;
        this->ts = 0;
        memset(vis, 0, sizeof(vis));
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v); // add Twice in Undirected Graph
    }

    void dfs(int pre, int now) {
        vis[now] = true;
        s.emplace(now);
        low[now] = dfn[now] = ++ts;
        for (auto &nxt : edges[now]) {
            if (dfn[nxt] == 0) {
                dfs(now, nxt);
                low[now] = min(low[now], low[nxt]);
            } else if (vis[nxt]) // && nxt != pre) in undirected graph, add this
                low[now] = min(low[now], dfn[nxt]);
        }
        if (low[now] == dfn[now] && vis[now]) {
            ++cnt;
            while (!s.empty() && s.top() != now) {
                belong[s.top()] = cnt;
                vis[s.top()] = false;
                s.pop();
            }
            if (!s.empty()) s.pop();
            belong[now] = cnt;
            vis[now] = false;
        }
    }

    void traverse() {
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) dfs(i, i);
    }
} trj;