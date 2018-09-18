#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 10000

using namespace std;

struct Node {
    int src;
    int dest;
    int step;

    Node(int s, int d, int ss = 0) {
        src = s;
        dest = d;
        step = ss;
    }
};

vector<Node> mat[N + 1];
int visited[N + 1];
queue<Node> q;

int bfs(int start, int &e) {
    int result;
    while (!q.empty())
        q.pop();
    Node node = Node(start, start, 0);
    visited[start] = 1;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        int src = node.dest;
        int step = node.step;
        int len = mat[src].size();
        for (int i = 0; i < len; i++) {
            int dest = mat[src][i].dest;
            e = dest;
            if (!visited[dest]) {
                visited[i] = true;
                q.push(Node(src, dest, step + 1));
                result = step + 1;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    for (int i = 2; i <= n; i++) {
        int j;
        cin >> j;
        mat[i].push_back(Node(i, j));
        mat[j].push_back(Node(j, i));
    }
    for (int i = n + 1; i <= n + m; i++) {
        int j;
        cin >> j;
        mat[i].push_back(Node(i, j));
        mat[j].push_back(Node(j, i));
    }
    int e, res;
    bfs(1, e);
    memset(visited, 0, sizeof(visited));
    cout << bfs(e, res) << endl;
    return 0;
}

