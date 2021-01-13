/*  Author: NogiNonoka
    Date: 2021.1.13   
    Time Complexity: O(VE^2)  */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
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
        if (parent[x] = x) return x;
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