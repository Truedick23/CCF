#include<iostream>
#include<queue>
#define N 100000

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
    bool operator < (const Node &node2) const{
        return value > node2.value;
    }
};

int father[N+1];

int Find(int n) {
    while(n != father[n])
        n = father[n];
    return n;
}

void Union(int x1, int x2) {
    int f1, f2;
    f1 = Find(x1);
    f2 = Find(x2);
    if(f1 != f2)
        father[f1] = f2;
}


priority_queue<Node> q;

int main() {
    int n, m, value;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        q.push(Node(a, b, c));
    }
    while(!q.empty()) {
        Node node = q.top();
        q.pop();
        int src = node.src;
        int dest = node.dest;
        if(Find(src) != Find(dest))
            Union(dest, src);
        if(Find(1) == Find(n)) {
            value = node.value;
            break;
        }
    }
    cout << value << endl;
    return 0;
}
