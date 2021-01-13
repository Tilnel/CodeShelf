/*  Author: MinLiu@nju
    Date: 2021.1.13
    Time Complexity: )(V^2E)    */

#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, s;
int src, dst;
int cap[405][405] = {0};
int depth[405] = {0};

int dfs(int u, int lim){
    if(u == dst)
        return lim;
    for(int v = 0 ;v <= 2 * n ;++v) {
        int ret;
        if (cap[u][v] && depth[u] + 1 == depth[v] && (ret = dfs(v, min(lim, cap[u][v])))) {
            cap[u][v] -= ret;
            assert(cap[u][v] >= 0);
            cap[v][u] += ret;
            return ret;
        }
    }
    return 0;
}

bool bfs(){
    memset(depth, -1, sizeof(depth));
    queue<int> q;
    assert(q.empty() == true);
    q.push(src);
    depth[src] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0 ;i <= 2 * n ;++i)
            if(cap[cur][i] > 0 && depth[i] == -1){
                q.push(i);
                depth[i] = depth[cur] + 1;
            }
    }
    return depth[dst] != -1;
}

int dinic(){
    int flow = 0;
    while(bfs()){
        int ret;
        while((ret = dfs(src, 2)) != 0)
            flow += ret;
    }
    return flow;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(cap, 0, sizeof(cap));
        cin >> n >> m;
        for(int i = 0 ;i < n ;++i)
            cap[i][i + n] = cap[i + n][i] = 1;
        for(int i = 1, u, v ;i <= m ;++i){
            cin >> u >> v;
            cap[u + n][v] += 1;
            cap[v + n][u] += 1;
        }
        cin >> a >> b >> s;
        cap[2 * n][a] = cap[2 * n][s] = 1;
        src = 2 * n; dst = b;
        if(dinic() == 2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}