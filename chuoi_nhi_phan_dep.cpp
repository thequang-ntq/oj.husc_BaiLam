#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  string s; cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (
        s[i] == '1' &&
        i && s[i - 1] == '0' &&
        i + 1 < (int) s.size() && s[i + 1] == '0'
      ) {
      s[i + 1] = '1';
      ans ++;
    }
  }
  
  cout << ans << '\n';
}
