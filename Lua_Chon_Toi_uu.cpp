#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int n, a[N], dp[N][N];

int solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i + 1 == j) return dp[i][j] = 0;
    int res = 0;
    for (int k = i + 1; k < j; k++) {
        res = max(res, solve(i, k) + solve(k, j) + a[i] * a[j]);
    }
    return dp[i][j] = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, n - 1) << endl;
    return 0;
}
