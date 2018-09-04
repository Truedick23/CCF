#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> mat[1001];
int N, M;
int linked[1001][1001];

void dfs(int x, int y, int visited[]) {
    linked[x][y] = 1;
    linked[y][x] = 1;
    visited[y] = 1;
    int len = mat[y].size();
    for(int i = 0; i < len; i++)
        if(!visited[mat[y][i]])
            dfs(x, mat[y][i], visited);
}

int main() {
    int N, M, num = 0;
    cin >> N >> M;
    memset(linked, 0, sizeof(linked));
    for(int i = 0; i < M; i++) {
        int m, n;
        cin >> m >> n;
        mat[m].push_back(n);
    }
    for(int i = 1; i <= N; i++) {
        int visited[1001] = {0};
        dfs(i, i, visited);
    }
    for(int i = 1; i <= N; i++) {
        int flag = 1;
        for(int j = 1; j <= N; j++)
            if(!linked[i][j]) {
                flag = 0;
                break;
            }
        if(flag)
            num++;
    }
    cout << num << endl;
    return 0;
}
