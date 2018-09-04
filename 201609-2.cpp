#include<iostream>
using namespace std;

int main() {
    int seats[100] = {0}, p[100] = {0}, arrange[100][5];
    int n;
    for(int i = 0; i < 100; i++) {
        seats[i] = 5;
        p[i] = 0;
        for(int j = 0; j < 5; j++)
            arrange[i][j] = 0;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        for(int m = 0; m < n; m++) {
            if(p[i] <= seats[m]) {
            for(int j = 1; j <= p[i]; j++)
                arrange[i][j - 1] = m * 5 + j + (5 - seats[m]);
            seats[m] -= p[i];
            break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p[i]; j++)
            cout << arrange[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
