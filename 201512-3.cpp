#include<iostream>
using namespace std;

char all[101][101];
int vis[101][101];

struct direct {
    int dx, dy;
} direct[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void drawline(int y1, int x1, int y2, int x2) {
    if(x1 == x2) {
        if(y1 > y2) swap(y1, y2);
        for(int i = y1; i <= y2; ++i)
            if(all[x1][i] != '|' && all[x1][i] != '+')
                all[x1][i] = '-';
            else  all[x1][i] = '+';
    }
    else {
        if(x1 > x2) swap(x1, x2);
        for(int i = x1; i <= x2; i++)
            if(all[i][y1] != '-' && all[i][y1] != '+')
                all[i][y1] = '|';
            else all[i][y1] = '+';
    }
}

void fillc(int x, int y, char c, int m, int n)
{
    int nx, ny;

    all[y][x] = c;

    for(int i = 0; i < 4; i++) {
        ny = y + direct[i].dy;
        nx = x + direct[i].dx;

        if(0 <= nx && nx < m && 0 <= ny && ny < n &&
                all[ny][nx] != '|' && all[ny][nx] != '-' && all[ny][nx] != '+' &&
                all[ny][nx] != c)
            fillc(nx, ny, c, m, n);//Ìî³äº¯Êý£¬µÝ¹éÌî³ä
    }
}

int main() {
    int m, n, q, v;
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            all[i][j] = '.';

    cin >> m >> n >> q;
    while(q--) {
        cin >> v;
        if(!v) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            drawline(x1, y1, x2, y2);
        }
        else {
            int x, y;
            char c;
            cin >> x >> y >> c;
            fillc(x, y, c, m, n);
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < m; j++)
            cout << all[i][j];
        cout << endl;
    }
    return 0;
}
