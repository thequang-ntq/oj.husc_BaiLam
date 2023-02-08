#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "HELP";
  string t; cin >> t;
  
  int ans = 0;

  for (int i = 0 , j = 0; i < (int) t.size(); i++ , j = (j + 1) % 4) {
    ans += (s[j] != t[i]);
  }
  cout << ans << '\n';
}
