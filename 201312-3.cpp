#include<iostream>
using namespace std;

int s(int height[], int m, int n) {
    int h = height[m], a = n - m + 1;
    for(int i = m; i <= n; i++) {
        if(height[i] < h)
            h = height[i];
    }
    return h * a;
}

int main() {
    int n, height[1001] = {0}, maxs = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++) {
            int ss = s(height, j, i);
            if(ss > maxs)
                maxs = ss;
        }
    cout << maxs << endl;
    return 0;
}
