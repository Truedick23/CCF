#include<iostream>
#include<queue>
#include<cstring>
#define N 10000

using namespace std;

struct Node {
    int src;
    int dest;
    int value;

    Node(int s, int d, int v) {
        src = s;
        dest = d;
        value = v;
    }

    Node(){}

    operator < (const Node & node2) const {
        return value > node2.value;
    }
};

int dist[N+1];
int cost[N+1];
int visited[N+1];
int path_bought[N+1][N+1];
priority_queue<Node> q;
vector<Node> mat[N+1];

int dijistra() {
    int result = 0;
    memset(dist, INT_MAX, sizeof(dist));
    memset(cost, INT_MAX, sizeof(cost));
    memset(visited, 0, sizeof(visited));
    memset(path_bought, 0, sizeof(path_bought));
    dist[1] = 0;
    cost[1] = 0;
    visited[1] = 1;
    q.push(Node(1, 2, 0));
    while(!q.empty()) {
        Node node = q.top();
        q.pop();
        int n = node.dest;
        if(!visited[n]) {
            visited[n] = 1;
            int len = mat[n].size();
            for(int i = 0; i < len; i++)
            if(!visited[mat[n][i].dest]){
                int d = mat[n][i].dest;
                visited[d] = 1;
                int pathcost = mat[n][i].value;
                cout << pathcost << endl;
                if(dist[n] + pathcost < dist[d]) {
                    dist[d] = dist[n] + pathcost;
                    cost[d] = pathcost;
                    if(!path_bought[n][d]) {
                        path_bought[n][d] = 1;
                        result += pathcost;
                    }
                    q.push(Node(n, d, dist[d]));
                } else if(dist[n] + pathcost == dist[d] && cost[d] > pathcost){
                    cost[d] = pathcost;
                    if(!path_bought[n][d]) {
                        path_bought[n][d] = 1;
                        result += pathcost;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    int n, m, result = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        Node node;
        int a, b, c;
        cin >> a >> b >> c;
        mat[a].push_back(Node(a, b, c));
        mat[b].push_back(Node(b, a, c));
    }
    cout << dijistra() << endl;
    for(int i = 2; i <= n; i++)
        cout << dist[i] << endl;
    //cout <<  << endl;
    return 0;
}
