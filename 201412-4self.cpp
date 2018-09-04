#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct edge {
    int src;
    int dest;
    int cost;
    operator < (const edge &n) const {
        return cost > n.cost;
    }
};

class UF {
private:
    vector<int> v;
public:
    UF(int n) {
        for(int i = 0; i <= n; i++) {
            v.push_back(i);
        }
    }

    int Find(int x) {
        while(1) {
            if(v[x] != x)
                x = v[x];
            else
                return x;
        }
    }

    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if(x != y) {
            v[x] = y;
            return true;
        }
        else
            return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<edge> q;
    edge e;
    for(int i = 0; i < m; i++) {
        cin >> e.src >> e.dest >> e.cost;
        q.push(e);
    }
    UF uf(n);
    int result = 0, count = 0;
    while(count < n) {
        e = q.top();
        q.pop();
        if(uf.Find(e.dest) != uf.Find(e.src)) {
            uf.Union(e.src, e.dest);
            result += e.cost;
            count++;
        }
    }
    cout << result << endl;
    return 0;
}
