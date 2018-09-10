#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#define N 200

using namespace std;

struct Node {
    int x;
    int y;
    int flag;
    int step;
    Node(int xx = 0, int yy = 0, int st = 0, int f = 0) {
        x = xx;
        y = yy;;
        step = st;
        flag = f;
    }
};

int r;
bool canLink(Node node1, Node node2) {
    int dist = sqrt(pow((node1.x - node2.x), 2) + pow((node1.y - node2.y), 2));
    if(dist <= r)
        return true;
    else
        return false;
}

queue<Node> q;
vector<Node> v;
int visited[N+1];

int bfs(int _start, int _end, int r, int k) {
    int maxl = 0;
    Node endNode = v[_end];
    int len = v.size();
    q.push(Node(_start, _start));
    visited[_start] = 1;
    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        if(endNode.x == node.x && endNode.y == node.y)
            return v[_end].step - 1;
        for(int i = 0; i < len; i++)
            if(!visited[i] && canLink(v[i], node)) {
                    visited[i] = 1;
                    v[i].step = node.step + 1;
                    q.push(v[i]);
            }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k >> r;
    for(int i = 1; i <= n + m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(Node(x, y, 0, (i > n)));
    }
    cout << bfs(0, 1, r, k) << endl;
    return 0;
}
