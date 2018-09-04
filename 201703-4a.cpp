#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
typedef pair<int, int> P;
typedef struct node {
    int x, num;
}node;

const int INF = 1 << 29;
node no[100000 + 10];
vector<node> vec[100000 + 10];
int len[100000 + 10], v[100010];
int n, m;

void dij(int x) {
    for(int i = 0; i <= n; i++) {
        len[i] = INF;
        v[i] = 0;
    }
    len[x] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({len[x], x});
    while(que.size()) {
        P p = que.top();
        que.pop();
        int num = p.second;
        if(v[num]) continue;
        v[num] = 1;
        for(int i = 0; i < vec[num].size(); i++) {
            int next = vec[num][i].x;
            int day = vec[num][i].num;
            int fz = max(day, len[num]);
            if(len[next] > fz) {
                len[next] = fz;
                que.push({len[next], next});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    dij(1);
    cout << len[n];
    return 0;
}
