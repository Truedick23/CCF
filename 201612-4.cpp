#include<iostream>
#include<cstring>

using namespace std;

const int INT_MAX2 = 0x7F7F7F7F;
const int N = 1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];

int solve(int l, int r) {
    if(dp[l][r] == INT_MAX2)
        for(int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum[r] - sum[l-1]);
    return dp[l][r];
}

int main() {
    int n;

    memset(dp, INT_MAX2, sizeof(dp));
    cin >> n;
    sum[0] = 0;
    for(int i = 1; i<= n; i++) {
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
        dp[i][i] = 0;
    }

    solve(1, n);
    cout << dp[1][n] << endl;
    return 0;
}
