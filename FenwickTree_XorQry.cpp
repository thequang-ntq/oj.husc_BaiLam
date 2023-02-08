/*
Tips:
    1.int? long long?
    2.don't submit wrong answer
    3.figure out logic first, then start writing please
    4.know about the range
    5.check if you have to input t or not
    6.modulo of negative numbers is not a%b, it is a%b + abs(b)

┏━━┓┏━━┓┏━━┓┏━━┓
┗━┓┃┃┏┓┃┗━┓┃┗━┓┃
┏━┛┃┃┃┃┃┏━┛┃┏━┛┃
┃┗━┓┃┗┛┃┃┗━┓┃┗━┓
┗━━┛┗━━┛┗━━┛┗━━┛
*/

#include <bits/stdc++.h>

#define SQR(x)    (1LL * ((x) * (x)))
#define MASK(i)   (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define fi        first
#define se        second
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define sz(s)     (int)s.size()
#define prev      __prev
#define next      __next
#define left      __left
#define right     __right

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const ll INFLL = (ll)2e18 + 7LL;

const int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

template<class BUI, class TRONG>
    bool minimize(BUI &x, const TRONG y){
        if(x > y){
            x = y;
            return true;
        } else return false;
    }
template<class BUI, class TRONG>
    bool maximize(BUI &x, const TRONG y){
        if(x < y){
            x = y;
            return true;
        } else return false;
    }

/* Author : Bui Nguyen Duc Trong, Luong Van Chanh High School for the gifted*/
/* Template is copied by Trong */

                           /** Losing in Provincial Contests **/
                                    /** TRYING HARDER**/
                                   /**      ORZ     **/

/* -----------------[ MAIN CODE GOES HERE ]----------------- */

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define MAX 300300

struct FenwickTree{
    int n;
    vi bit;

    void reset(int _n = 0){
        n = _n;
        bit.assign(n + 10, 0);
    }

    void update(int i, int v){
        for(; i <= n; i += i & -i) bit[i] ^= v;
    }

    int getXor(int i){
        int ans = 0;
        for(; i; i -= i & -i) ans ^= bit[i];
        return ans;
    }

    int getRange(int l, int r){
        return getXor(r) ^ getXor(l - 1);
    }
} bit;

int n, q;
int a[MAX], b[MAX], prev[MAX];

struct Query{
    int l, r, id;

    bool operator < (Query &q){
        if(r == q.r) return l < q.l;
        return r < q.r;
    }
} qry[MAX];

int ans[MAX];

void solve(){
    cin >> n >> q;
    vi v;
    for(int i = 1; i <= n; i++) cin >> a[i], v.pb(a[i]);
    for(int i = 1; i <= q; i++){
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for(int i = 1; i <= n; i++) b[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    sort(qry + 1, qry + 1 + q);
    memset(prev, 0, sizeof prev);
    bit.reset(n);
    int R = 0;
    for(int i = 1; i <= q; i++){
        int r = qry[i].r;
        while(R < r){
            ++R;
            if(prev[b[R]] == 0){
                prev[b[R]] = R;
                bit.update(R, a[R]);
            }
            else{
                bit.update(prev[b[R]], a[prev[b[R]]]);
                prev[b[R]] = R;
                bit.update(prev[b[R]], a[R]);
            }
        }
        ans[qry[i].id] = bit.getRange(qry[i].l, qry[i].r);
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    const bool multitest = 0;
    int tt = 1; if(multitest) cin >> tt;

    while( tt-- ){

        solve();

    }

    return 0;
}
