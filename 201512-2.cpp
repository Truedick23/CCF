#include<iostream>
using namespace std;

int main() {
    int n, m;
    int matrix[30][30] = {{0}}, newmatrix[30][30] = {{0}};
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            newmatrix[i][j] = matrix[i][j];
        }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j > 0 && j < m - 1 && matrix[i][j - 1] == matrix[i][j] && matrix[i][j] == matrix[i][j + 1]) {
                newmatrix[i][j - 1] = 0;
                newmatrix[i][j] = 0;
                newmatrix[i][j + 1] = 0;
            }
            if(i > 0 && i < n - 1 && matrix[i][j] == matrix[i - 1][j] && matrix[i][j] == matrix[i + 1][j]) {
                newmatrix[i][j] = 0;
                newmatrix[i + 1][j] = 0;
                newmatrix[i - 1][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << newmatrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
