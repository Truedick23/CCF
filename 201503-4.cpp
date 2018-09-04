#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 20005;
vector<int> G[maxn];
bool vis[maxn] = {};
int n, m, ans = 0, depth[maxn];

int main() {
    cin >> n >> m;
    for(int i = 2, u; i <= n + m; i++) {
        cin >> u;
        G[u].push_back(i);
        G[i].push_back(u);
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    int now;
    while(!Q.empty()) {
        now = Q.front();
        Q.pop();
        for(int i = 0; i < G[now].size(); i++) {
            int v = G[now][i];
            if(vis[v])
                continue;
            vis[v] = true;
            Q.push(v);
        }
    }
    Q.push(now);
    memset(vis, false, sizeof(vis));
    vis[now] = true;
    while(!Q.empty()) {
        now = Q.front();
        Q.pop();
        for(int i = 0; i < G[now].size(); i++) {
            int v = G[now][i];
            if(vis[v])
                continue;
            vis[v] = true;
            depth[v] = depth[now] + 1;
            Q.push(v);
        }
    }
    cout << depth[now];
}
