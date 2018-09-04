#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n, arr[1001], num = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int marg = abs(arr[i] - arr[j]);
            if(marg == 1)
                num++;
        }
    }
    cout << num << endl;
}
