#include<iostream>
using namespace std;

int main() {
    int n, arr[1000], num = 0;
    for(int i = 0; i < 1000; i++)
        arr[i] = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n - 1; i++) {
        if((arr[i] - arr[i - 1]) * (arr[i] - arr[i + 1]) > 0)
            num++;
    }
    cout << num;
}
