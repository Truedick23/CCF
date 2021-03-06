#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 510;
const ll inf = 1e+18;
bool vis[N];
int que[N];
ll dist[N], dist0[N];
ll g[N][N], g0[N][N];

void SPFA(int start, int n) {
    int fron = 0, rear = 0;
    for(int v = 1; v <= n; v++) {
        if(v == start) {
            que[rear++] = v;
            vis[v] = true;
            dist[v] = dist0[v] = 0;
        }
        else {
            vis[v] = false;
            dist0[v] = dist[v] = inf;
        }
    }
    while(fron != rear) {
        int u = que[fron++];
        vis[u] = false;
        if(fron >= N)
            fron = 0;
        for(int i = 1; i <= n; i++) {
            ll v = g[u][i];
            if(dist[i] > dist[u] + v) {
                dist[i] = dist[u] + v;
                if(!vis[i]) {
                    vis[i] = true;
                    que[rear++] = i;
                    if(rear >= N)
                        rear = 0;
                }
            }
            if(dist[i] > dist0[u] + v) {
                dist[i] = dist0[u] + v;
                if(!vis[i]) {
                    vis[i] = true;
                    que[rear++] = i;
                    if(rear >= N)
                        rear = 0;
                }
            }
            if(g0[u][i] != inf) {
                v = g0[u][i] * g0[u][i];
                if(dist0[i] > dist[u] + v) {
                    dist0[i] = dist[u] + v;
                    if(!vis[i]) {
                        vis[i] = true;
                        que[rear++] = i;
                        if(rear >= N)
                            rear = 0;
                    }
                }
            }
        }
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    ll t, a, b, c;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            g[i][j] = g0[i][j] = inf;
    for(int i = 0; i < m; i++) {
        cin >> t >> a >> b >> c;
        if(t && g0[a][b] > c)
            g0[a][b] = g0[b][a] = c;
        if(!t && g[a][b] > c)
            g[a][b] = g[b][a] = c;
    }
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j)
                    continue;
                if(g0[i][j] > g0[i][k] + g0[k][j])
                    g0[i][j] = g0[i][k] + g0[k][j];
            }
    SPFA(1, n);
    cout << std::min(dist0[n], dist[n]);
    return 0;
}
