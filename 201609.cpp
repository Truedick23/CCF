#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1000;
const int TRUE = 1;
const int DIRECTSIZE = 4;
struct direct {
    int drow, dcol;
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int buyer[N+1][N+1];
int visited[N+1][N+1];

struct node {
    int row, col, step;
    node(){}
    node(int r, int c, int s) {
        row = r;
        col = c;
        step = s;
    }
};

queue<node> q;
int buyercount = 0;
long long ans = 0;

void bfs(int n) {
    node fron, v;
    while(!q.empty()) {
        fron = q.front();
        q.pop();
        for(int i = 0; i < DIRECTSIZE; i++) {
            v.row = fron.row + direct[i].drow
            v.col = fron.col + direct[i].dcol;
            v.step = fron.step + 1;

            if(visited[v.row][v.col])
                continue;
            if(buyer[v.row][v.col] > 0) {
                visited[v.row][v.col] = 1;
                ans += buyer[v.row][v.col] * v.step;
                if(--buyercount == 0)
                    return;
            }
            visited[v.row][v.col] = 1;
            q.push(v);
        }
    }
}

int main() {
    int n, m, l, d, x, y, c;
    memset(buyer, 0, sizeof(buyer));
    memset(visited, 0, sizeof(visited));

    cin >> n >> m >> k >> d;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        cin >> c;
        if(buyer[x][y] == 0)
            buyercount++;
        buyer[x][y] += c;
    }
    for(int i = 1; i <= d; i++) {
        cin >> x >> y;
        visited[x][y] = TRUE;
    }
    bfs(n);
    cout << ans << endl;
    return 0;
}
