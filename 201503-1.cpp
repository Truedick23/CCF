#include<iostream>
using namespace std;

int mat[1000][1000];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[m - 1 - j][i];
    /*for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            newmat[i][j] = mat[m - j][i];*/
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
