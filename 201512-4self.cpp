#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<stack>

using namespace std;

const int N = 10000;

int v[N+1];
class UF {
private:
    int length;
public:
    UF(int n) {
        length = n;
        for(int i = 0; i <= n; i++)
            v[i] = i;
    }

    int Find(int x) {
        if(x == v[x])
            return x;
        else
            return v[x] = Find(v[x]);
    }

    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if(x == y)
            return false;
        else {
            v[x] = y;
            return true;
        }
    }
};

set<int> g[N+1];
stack<int> path;
bool visited[N+1][N+1];
int nopathflag;

int n, m;

void dfs(int node) {
    for(set<int>::iterator it = g[node].begin(); it != g[node].end(); it++) {
        if(!visited[node][*it]) {
            visited[node][*it] = true;
            visited[*it][node] = true;

            dfs(*it);
        }
    }
    path.push(node);
}

int main() {
    int src, dest;
    cin >> n >> m;
    UF uf(n);
    for(int i = 0; i < m; i++) {
        cin >> src >> dest;
        g[src].insert(dest);
        g[dest].insert(src);
        uf.Union(src, dest);
    }

    nopathflag = false;
    int root = uf.Find(1);
    for(int i = 2; i <= n; i++) {
        if(uf.Find(i) != root) {
            nopathflag = true;
            break;
        }
    }

    if(!nopathflag) {
        int count = 0;
        for(int i = 1; i <= n; i++)
            if(g[i].size() % 2 == 1)
                count++;
        if(!(count == 0 || (count == 2 && g[1].size() % 2 == 1)))
            nopathflag = true;
    }

    if(!nopathflag) {
        memset(visited, false, sizeof(visited));
        dfs(1);

        int t;
        while(!path.empty()) {
            t = path.top();
            path.pop();
            cout << t << " ";
        }
        cout << endl;
    } else
        cout << -1 << endl;
    return 0;
}
