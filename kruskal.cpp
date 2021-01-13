/*  Author: NogiNonoka
    Date: 2021.1.13
    Time Complexity: O(ElogE)
    NOTICE: This is for sparce graph.   */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MAXE = 200005;

struct DSU {
    int parent[MAXN]; 
    int n;
    int sum[MAXN];
    int rank[MAXN];

    void InitParent(int n) {
        this -> n = n;
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sum[i] = i;
            rank[i] = 0;
        }
    }

    int FindParent(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = FindParent(parent[x]);
    }

    bool CheckUnicom(int x, int y) {
        return FindParent(x) == FindParent(y);
    }

    void MergeNode(int x, int y) {
        x = FindParent(x);
        y = FindParent(y);
        if (rank[x] > rank[y]) {
            parent[y] = x;
            if (x != y) {
                sum[x] += sum[y];
            }
        } else {
            parent[x] = y;
            if (x != y) {
                sum[y] += sum[x];
            }
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
} dsu;

struct Kruskal {
    // Use DSU
    int n, m;

    struct Edge {
        int fr, to;
        int val;
        bool operator<(const Edge &b) const {
            return val < b.val;
        }
    } edge[MAXE];

    int kruskal() {
        int sum = 0;
        dsu.InitParent(n);
        sort(edge + 1, edge + m + 1);
        for (int i = 1; i <= m; i++) {
            if (!dsu.CheckUnicom(edge[i].fr, edge[i].to)) {
                dsu.MergeNode(edge[i].fr, edge[i].to);
                sum += edge[i].val;
            }
        }
        return sum;
    }
} kr;

int main() {
    int u, v, w;
    scanf("%d%d", &kr.n, &kr.m);
    for (int i = 1; i <= kr.m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        kr.edge[i].fr = u;
        kr.edge[i].to = v;
        kr.edge[i].val = w;
    }
    int res = kr.kruskal();
    for (int i = 1; i <= kr.n; i++) {
        if (!dsu.CheckUnicom(1, i)) {
            printf("orz\n");
            return 0;
        }
    }
    printf("%d\n", res);
	return 0;
}