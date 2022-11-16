#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long fac[61][61];
  function<void()> init = [&]() {
    for (int i = 0; i <= 60; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (i == j || j == 0) {
          fac[i][j] = 1;
        } else {
          fac[i][j] = fac[i - 1][j] + fac[i - 1][j - 1];
        }
      }
    }
  };
  init();
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    cout << fac[n + k - 1][n - 1] << '\n';
  }
  return 0;
}
