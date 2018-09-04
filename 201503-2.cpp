#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int n, maxn = 0;
    int times[1001] = {0}, maxi = 0;
    memset(times, 0, sizeof(times));
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num > maxn)
            maxn = num;
        times[num]++;
    }
    while(1) {
        maxi = 0;
        for(int i = 0; i <= maxn; i++) {
            if(times[i] > maxi)
                maxi = times[i];
        }
        if(maxi == 0)
            break;
        for(int i = 0; i <= maxn; i++) {
            if(times[i] == maxi) {
                cout << i << " " << maxi << endl;
                times[i] = 0;
            }
        }
    }
    return 0;
}
