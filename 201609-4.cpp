#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INT_MAX2 = ((unsigned int)(-1) >> 1);
const int MAXN = 10000;

struct _edge {
    int v, cost;
    _edge(int v2, int c) {
        v = v2;
        cost = c;
    }
};

struct _node {
    int u, cost;
    _node(){}
    _node(int u2, int c) {
        u = u2;
        cost = c;
    }

    bool operator < (const _node n) const {
        return cost > n.cost;
    }
};

vector<_edge> g[MAXN + 1];
priority_queue<_node> q;
int dist[MAXN + 1];
int cost[MAXN + 1];
bool visited[MAXN + 1];

void dijkstra_add(int start, int n) {
    for(int i = 0; i <= n; i++) {
        dist[i] = INT_MAX2;
        cost[i] = INT_MAX2;
        visited[i] = false;
    }

    dist[start] = 0;
    cost[start] = 0;
    q.push(_node(start, 0));

    _node f;
    while(!q.empty()) {
        f = q.top();
        q.pop();
        int u = f.u;
        if(!visited[u]) {
            visited[u] = true;
            int len = g[u].size();
            for(int i = 0; i < len; i++) {
                int v2 = g[u][i].v;

                if(visited[v2])
                    continue;

                int tempcost = g[u][i].cost;
                int nextdist = dist[u] + tempcost;

                if(dist[v2] > nextdist) {
                    dist[v2] = nextdist;
                    cost[v2] = tempcost;
                    q.push(_node(v2, dist[v2]));
                } else if(dist[v2] == nextdist)
                    cost[v2] = min(cost[v2], tempcost);
            }
        }
    }
}

int main() {
    int n, m, src, dest, cost2;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> src >> dest >> cost2;
        g[src].push_back(_edge(dest, cost2));
        g[dest].push_back(_edge(src, cost2));
    }

    dijkstra_add(1, n);

    int ans = 0;
    for(int i = 2; i <= n; i++)
        ans += cost[i];
    cout << ans << endl;
    return 0;
}
