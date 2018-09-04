#include<iostream>
#include<stdlib.h>
using namespace std;

int a[100];
int b[100];
void conflict(int i, int j) {
    if(b[i] == 1 && b[j] == 0) {
        b[i] = 0;
        b[j] = 1;
    }
    else if(b[i] == 0 && b[j] == 1) {
        b[i] = 1;
        b[j] = 0;
    }
}

int main() {
    int n, l, T;
    int flag;
    cin >> n >> l >> T;
    for(int i = 0; i < n; i++)
        b[i] = 1;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int t = 0; t < T; t++)
    for(int i = 0; i < n; i++) {
        flag = 0;
        for(int k = 0; k < n; k++)
            if(a[i] == a[k] && b[i] != b[k])
                conflict(i, k);
        if(a[i] == l && b[i] == 1 && flag == 0) {
            b[i] = 0;
            a[i]--;
            flag = 1;
        }
        if(a[i] == 0 && b[i] == 0 && flag == 0) {
            b[i] = 1;
            a[i]++;
            flag = 1;
        }
        if(flag == 0) {
            if(b[i] == 0)
                a[i]--;
            else if(b[i] == 1)
                a[i]++;
        }
    }
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << endl;
    return 0;
}
