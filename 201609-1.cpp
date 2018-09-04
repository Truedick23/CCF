#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    int arr[1000] = {0}, maxmerge = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int merg = abs(arr[i] - arr[i + 1]);
        if(merg > maxmerge)
            maxmerge = merg;
    }
    cout << maxmerge << endl;
    return 0;
}
