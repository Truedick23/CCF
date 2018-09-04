#include<iostream>
using namespace std;

int main() {
    int n = 0, i, j;
    int mat[500][500] = {{0}};
    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    i = 0; j = 0;
    for(int l = 0; l < 16; l++) {
        int x = 0, y = 1;
        cout << mat[i][j] << " ";
        if(i == n - 1 && j == n - 1)
            break;
        if((i == 0 || i == n - 1) && j % 2 == 0){
            x = 0; y = 1;
        }
        else if((j == 0 || j == n - 1) && i % 2 == 1) {
            x = 1; y = 0;
        }
        else if((i + j) % 2 == 1) {
            x = 1; y = -1;
        }
        else if((i + j) % 2 == 0) {
            x = -1; y = 1;
        }
        i += x;
        j += y;
    }
    cout << endl;
    return 0;
}
