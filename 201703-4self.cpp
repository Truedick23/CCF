#include<iostream>
#include<queue>
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
    operator < (const Node node2) const {
        return value > node2.value;
    }
};

int father[100001] = {0};


int Find(int f) {
    while(f != father[f])
        f = father[f];
    return f;
}

void Union(int x1, int x2) {
    x1 = Find(x1);
    x2 = Find(x2);
    if(x1 != x2)
        father[x1] = x2;
}

int main() {
    priority_queue<Node> q;
    int n, m, result;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        q.push(Node(a, b, c));
    }
    for(int i = 0; i <= n; i++)
        father[i] = i;
    while(!q.empty()) {
        Node node = q.top();
        q.pop();
        if(Find(node.src) != Find(node.dest))
            Union(node.src, node.dest);
        if(Find(1) == Find(n)) {
            result = node.value;
            break;
        }
    }
    cout << result << endl;
    return 0;
}
