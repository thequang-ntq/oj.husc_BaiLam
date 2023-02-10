#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

typedef long long ll;

void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(taskname".inp", "r")) {
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
}
ll eval(const string &expr, ll mod) {
    int n = expr.size();
    stack<int> st;
    vector<int> pos(n, -1);

    // Get pos pair bracket
    for (int i = n - 1; i >= 0; i--) {
        if (expr[i] == ')') st.push(i);
        else if (expr[i] == '(') {
            pos[i] = st.top();
            st.pop();
        }  
    }

    function<ll(int, int)> calc = [&](int l, int r){
        if (l > r) return 0ll;

        ll lst = 0;
        vector<ll> ans(1, 0);
        for (int i = l, isMul = 0, fst = 1, isSub = 1; i <= r; i++) {
            if (expr[i] == '(') {
                lst = calc(i + 1, pos[i] - 1);
                if (isMul) ans.back() = ans.back() * lst % mod, lst = ans.back();
                else ans.push_back(isSub * lst % mod), isSub = 1;
                i = pos[i];
            }
            else if (isdigit(expr[i])) {
                if (isMul) {
                    ans.back() = (ans.back() * (fst ? 0 : 10) + lst * (expr[i] - '0') % mod);
                    fst = 0;
                }
                else {
                    ans.back() = (ans.back() * 10 + (expr[i] - '0')) % mod;
                    lst = ans.back();
                }
            }
            else if (expr[i] == '*') isMul = fst = 1;
            else if (expr[i] == '+') isMul = 0, ans.push_back(0), isSub = 1;
            else isMul = 0, ans.push_back(0), isSub = -1;
        }

        ll sum = 0;
        for (auto &i: ans)
            sum = (sum + i) % mod;

        return sum;
    };

    return calc(0, n - 1);
}
string replace(const string &str, ll x) {
    string ans = "";
    for (auto &i: str) 
        if (i == 'x') ans += to_string(x);
        else ans += i;
    return ans;
}
void Solve() {
	string expr; cin >> expr;
    ll p, m; cin >> p >> m;

    ll a = (eval(replace(expr, 2), m) - eval(replace(expr, 1), m) + m) % m;
    ll b = (eval(replace(expr, 1), m) - a + m) % m;

    for (int i = 0;; i++) 
        if ((a * i % m + b % m + m * m) % m == p) 
            return void(cout << i);
}

int main(){
	Input();
	Solve();
	return 0;
}
