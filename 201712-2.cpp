#include<iostream>
using namespace std;

bool ok(int k, int m) {
    if(m % k == 0 || m % 10 == k)
        return false;
    return true;
}

int flag(int arr[], int n) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0)
            num++;
    }
    return num;
}

int win(int arr[], int n) {
    int i = 0;
    for(; i < n; i++) {
        if(arr[i] == 0)
           break;
    }
    return (i + 1);
}

int main() {
    int k = 0, n = 0, arr[1000], m = 1;
    for(int i = 0; i < 1000; i++) {
        arr[i] = 0;
    }
    cin >> n >> k;
    int i = 0;

    while(flag(arr, n) != 1) {
        if(arr[i] == 0 && !ok(k, m++)) {
            arr[i] = 1;
        }
        if(i == (n - 1))
            i = 0;
        else
            i++;
    }
    cout << win(arr, n);
    return 0;
}
