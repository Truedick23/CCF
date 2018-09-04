#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define N 1000
using namespace std;

struct Node {
    int src;
    int dest;
    Node(int s = 0, int d = 0) {
        src = s;
        dest = d;
    }
};

queue<Node> q;
vector<int> mat[N+1];
int linked[N+1][N+1];
int visited[N+1];

void dfs(int n) {
    q = queue<Node>();
    memset(visited, 0, sizeof(visited));
    visited[n] = 1;
    linked[n][n] = 1;
    for(int i = 0; i < mat[n].size(); i++) {
        int m = mat[n][i];
        visited[m] = 1;
        linked[n][m] = 1;
        //cout << n << "->" << m << endl;
        q.push(Node(n, m));
    }
    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        int src = node.dest;
        int len = mat[src].size();
        for(int i = 0; i < len; i++) {
            int dest = mat[src][i];
            if(!visited[dest]) {
                visited[dest] = 1;
                linked[n][dest] = 1;
                //cout << n << "->" << dest << endl;
                q.push(Node(src, dest));
            }
        }
    }
}

int main() {
    int n, m, num = 0;
    cin >> n >> m;
    memset(linked, 0, sizeof(linked));
    for(int i = 0; i < n; i++)
        linked[i][i] = 1;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
    }
    for(int i = 0; i < n; i++)
        dfs(i);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && linked[i][j] && linked[j][i]) {
                linked[i][j] = 0;
                linked[j][i] = 0;
               // cout << i << " " << j << endl;
                num++;
            }
        }
    }
    cout << num << endl;
    return 0;
}
