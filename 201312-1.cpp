#include<iostream>
using namespace std;

int main() {
    int times[10002] = {0}, n, maxn = 0, index = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;
        times[s]++;
    }
    for(int i = 0; i < 10002; i++) {
        if(times[i] > maxn) {
            index = i;
            maxn = times[i];
        }
    }
    cout << index;
}
