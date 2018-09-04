#include<iostream>
#include<queue>
using namespace std;

vector<int> link[10001];
bool marked[]

struct P {
    int v;
    int step;
    P(int vv = 0, int sstep = 0) {
        v = vv;
        step = sstep;
    }
};

int bfs(int n, int &e) {
    queue<P> q;
    q.push(P(s));
    marked[n] = 1;
    int res = 0;
    P p1, p2;
    while(!q.empty()) {
        p1 = que.front();
        que.pop();
        int len = link[p1.v].size();
        for(int i = 0; i < len; i++) {
            int tmp = link[p1.v][i];
            if(!marked[tmp]) {
                marked[tmp] = 1;
                e = tmp;
                p1 = P(tmp);
                p2.step = p1.step + 1;
                q.push(p2);
            }
        }
    }
    return p2.step;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1) {
        int num;
        cin >> num;
        link[num].push_back(i + 2);
        link[i + 2].push_back(num);
    for(int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        link[i].push_back(num + n);
        link[num + n].push_back(i);
    }

    int e, res;
    bfs(1, e);
    for(int i = 0; i < 20001; i++) {
        marked[i] = 0;
    }
    cout << bfs(e, res) << endl;
    return 0;
}
