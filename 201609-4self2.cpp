#include<iostream>
#include<queue>
#include<cstring>
#define N 10000
#define MAXN 20000

using namespace std;

struct Node {
    int src;
    int dest;
    int value;

    bool operator < (const Node &node2) const{
        return value > node2.value;
    }

    Node(int s, int d, int v) {
        src = s;
        dest = d;
        value = v;
    }
};

priority_queue<Node> q;
vector<Node> mat[N+1];
int visited[N+1];
int dist[N+1];
int cost[N+1];

void dijistra(int i) {
    Node node = Node(1, 1, 0);
    dist[1] = 0;
    cost[1] = 0;
    q.push(node);
    while(!q.empty()) {
        node = q.top();
        q.pop();
        int src = node.dest;
        if(!visited[src]) {
            visited[src] = 1;
            int len = mat[src].size();
            for(int i = 0; i < len; i++) {
                int dest = mat[src][i].dest;
                if(!visited[dest]) {
                    int tempcost =  mat[src][i].value;
                    int newdist = dist[src] + tempcost;
                    if(dist[dest] > newdist) {
                        cost[dest] = tempcost;
                        dist[dest] = newdist;
                        q.push(Node(src, dest, newdist));
                    }
                    else if(dist[dest] == newdist) {
                        cost[dest] = min(cost[dest], tempcost);
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, totalcost = 0;
    memset(dist, MAXN, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    memset(cost, MAXN, sizeof(cost));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a].push_back(Node(a, b, c));
        mat[b].push_back(Node(b, a, c));
    }
    dijistra(1);
    for(int i = 2; i <= n; i++) {
        //cout << cost[i] << endl;
        totalcost += cost[i];
    }
    cout << totalcost << endl;
    return 0;
}


