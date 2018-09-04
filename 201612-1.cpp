#include<iostream>
using namespace std;

int main() {
    int n;
    int arr[1000] = {0};
    bool exist = false;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++) {
        int big = 0, small = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] < arr[i])
                small++;
            if(arr[j] > arr[i])
                big++;
        }
        if(big == small) {
            cout << arr[i];
            exist = true;
            break;
        }
    }
    if(!exist)
       cout << -1;
    return 0;
}
