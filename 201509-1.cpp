#include<iostream>
using namespace std;

int main() {
    int n, num = 1;
    int arr[1000] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++)
        if(arr[i] != arr[i + 1])
        num++;
    cout << num;
}
