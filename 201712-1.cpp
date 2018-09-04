#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int arr[1000], n = 0, minm = 10000, d = 0;
    for(int i = 0; i < 1000; i++)
        arr[i] = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            d = abs(arr[i] - arr[j]);
            if(d < minm)
                minm = d;
        }
    }
    cout << minm;
    return 0;
}
