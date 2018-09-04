#include<iostream>
using namespace std;

int main() {
    int n, k, num = 0, sum = 0;
    int arr[1000] = {0};
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum >= k) {
            sum = 0;
            num++;
        }
    }
    if(sum > 0)
        num++;
    cout << num;
    return 0;
}
