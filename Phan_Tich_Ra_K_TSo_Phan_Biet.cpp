#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

int nTest = 1;

void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(taskname".inp", "r")) {
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
    cin >> nTest;
}
bool isPrime(int x) {
	if (x <= 1) return false;
	if (x % 2 == 0) return x == 2;
	if (x % 3 == 0) return x == 3;
	for (int i = 5; i <= sqrt(x); i += 6)
		if (x % i == 0 || x % (i + 2) == 0)
			return false;
	return true; 
}
void Solve() {
	int n, k; cin >> n >> k;
	
	int x = n, cnt = 0;
	for (int i = 2; i <= sqrt(x); i++) 
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			n /= i; cnt++;
		}
	if (x > 1) cnt++, n /= x; 

	vector<int> uc;
	for (int i = 1; i <= sqrt(n); i++)
		if (n % i == 0) {
			if (!isPrime(i)) uc.push_back(i);
			if (i != n / i && !isPrime(n / i)) uc.push_back(n / i);
		}
	sort(uc.begin(), uc.end());

	int ans = 0;
    function<void(int, int, int)> backtrack = [&](int i, int x, int _cnt){
		if (cnt + _cnt >= k) return void(ans = 1);
        if (i >= uc.size() || x < uc[i] || x == 1 || ans == 1) return ;
        backtrack(i + 1, x, _cnt);
        if (x % uc[i] == 0) backtrack(i + 1, x / uc[i], _cnt + 1);
    };
	
	backtrack(1, n, 1);
	cout << (ans ? "Yes\n" : "No\n");
}

int main(){
	Input();
	while (nTest--) Solve();
	return 0;
}
