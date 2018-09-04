#include<iostream>
using namespace std;

int main() {
    int n, matrix[101][101] = {{0}}, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int m = x1; m < x2; m++)
        for(int n = y1; n < y2; n++) {
            if(matrix[m][n] == 0)
                s++;
            matrix[m][n] = 1;
        }
    }
    cout << s << endl;
}
