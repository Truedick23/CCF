#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int N = 20003;
int dist[N];
vector<int> g[N];

int dfs(int now, int last) {
    for(int i = 0; i < g[now].size(); i++) {
        int v = g[now][i];
        if(v != last) {
            dist[v] = dist[now] + 1;
            dfs(v, now);
        }
    }
}

int main() {
    int n, m, t;
    cin >> n >> m;
    for(int i = 2; i <= n; i++) {
        cin >> t;
        g[i].push_back(t);
        g[t].push_back(i);
    }
    for(int i = 1; i <= m; i++) {
        cin >> t;
        g[i + n].push_back(t);
        g[t].push_back(i + n);
    }

    memset(dist, 0, sizeof(dist));
    dfs(1, 0);
    int k = 1;
    for(int i = 2; i <= n; i++)
        if(dist[k] < dist[i])
        k = i;

    memset(dist, 0, sizeof(dist));
    dfs(k, 0);
    k = 1;
    for(int i = 2; i <= n + m; i++)
        if(dist[k] < dist[i])
            k = i;

    cout << dist[k];
    return 0;
}
