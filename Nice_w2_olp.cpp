#pragma GCC optimize("03,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC targer("sse,sse2,sse3,ssse3,sse4,avx,abm,mmx,abx,tune=native")
#pragma GCC optimization("-funroll-all-loops, no-stack-protector")
#include <bits/stdc++.h>
#define MO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX(a,b) ((a > b ) ? a : b)
#define MIN(a,b) ( (a < b) ? a : b)
#define ABS(x) (x < 0 ? -x : x)
#define ll long long
#define MOD 1000000007
#define mod 998244353
#define div6 166666668
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x)  (1LL<<(x))
#define CNT(x) __builtin_popcountll(x)
#define taskname "__Quang__"
#define double long double
using namespace std;
using ull = unsigned long long;
const ll inf = 1000000003;
const int maxn = 1e6 + 19;
const double Pi = 3.1415926535897323846;
const double eps = 1e-9;
int sign(double x){
    if(x > eps) return 1;
    if( x < -eps) return -1;
    return 0;
}
ll __lcm(ll a, ll b){
    return (a / __gcd(a,b) * b);
}
bool pr(ll n){
    if (n <= 1) return false;
    if(n <= 3) return true;
    for(ll i=2; i*i <= n; i++){
        if( (n % i) == 0) return false;
    }
    return true;
}
bool cp(ll n){
	ll temp = sqrt(n);
	return temp * temp == n;
}
ll binpow(ll a, ll b){
    ll res =1 ;
    a %= MOD;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
// ull npk(ll n, ll k){
// 	return fac(n) / fac(n-k);
// }
// ull nck(ll k, ll n){
// 	if(k==0 || k==n ) return 1;
// 	if(k==1) return n;
// 	return nck(k-1, n-1) + nck(k, n-1);
// }
//class SegTree{
//public:
//    int n;
//    vector<ll>a,lazy,st;
//public:
//    SegTree(){}
//    SegTree(const vector<ll>&x){
//        this -> n = x.size() - 1;
//        this -> lazy.resize(n*4+5, 1e9);
//        this -> st.resize(n*4+5, 1e9);
//        this -> a = x;
//        build(1,1,n);
//    }
//    void build(int id, int l, int r){
//        if(l == r){
//            st[id] = 1e9;
//            return;
//        }
//        int mid = (l+r)>>1;
//        build(id*2, l , mid);
//        build(id * 2 + 1, mid + 1, r);
//        st[id] = 1e9;
//    }
//    void fix(int id, int l, int r){
//        if(!lazy[id]) return;
//        st[id] += lazy[id];
//        if(l != r){
//            lazy[id*2] += lazy[id];
//            lazy[id*2+1] += lazy[id];
//        }
//        lazy[id] = 0;
//    }
//    void update(int id, int l, int r, int i, int val){
////        fix(id, l , r);
//        if( i > r || i < l) return;
//        if(l == r ){
////            lazy[id] += val;
////            fix(id, l , r);
//             st[id] = val;
//            return;
//        }
//        int mid = (l+r)>>1;
//        if(i <= mid) update(id*2 , l, mid, i, val);
//        else update(id*2+1, mid + 1, r , i, val);
//        st[id] = min(st[id*2] , st[id*2+1]);
//    }
//    ll get(int id, int l, int r, int u, int v){
////        fix(id, l , r);
//        if(u > r || v < l) return inf; // tim min return 1e9
//        								//tim max return -1e9
//        								//tim tong return 0
//        if( u <= l && v >= r){
//            return st[id];
//        }
//        int mid = (l+r)>>1;
//        ll get1 = get(id*2, l, mid, u, v);
//        ll get2 = get(id*2+1, mid+1, r, u, v);
//        return min(get1 , get2); 
//    }
//};
//class SegTree{
//private:
//	int n;
//	vector<ll>a,st,lazy;
//public:
//	SegTree(){}
//	SegTree(const vector<ll>&x){
//		this -> n = x.size() - 1;
//		this -> a = x;
//		this -> st.resize(n*4+5);
//		this -> lazy.resize(n*4+5);
//		build(1, 1, n);
//	}
//	void build(int id, int l, int r){
//		if(l == r){
//			st[id] = a[l];
//			return;
//		}	
//		int mid = (l + r)>>1;
//		build(id*2, l, mid);
//		build(id*2+1, mid + 1, r);
//		st[id] = min(st[id*2], st[id*2+1]);
//		for(int i=1; i<=n*4; i++) cout<< st[i] << " ";
//		cout<<'\n';
//	}
//	void fix(int id, int l, int r){
//		if(!lazy[id]) return;
//		st[id] += lazy[id];
//		if( l != r){
//			lazy[id*2] += lazy[id];
//			lazy[id*2+1] += lazy[id];
//		}
//		lazy[id] = 0;
//	}
//	void update(int id, int l, int r, int i, int val){
//		fix(id, l, r);
//		if(i > r || i < l){
//			return;
//		}
//		if(l == r){
//			lazy[id] += val;
//			st[id] = val;
//			fix(id, l, r);
//			return;
//		}
//		int mid = (l+r)>>1;
//		update(id*2, l, mid, i, val);
//		update(id*2+1, mid + 1, r, i, val);
//		cout << '\n';
//		for(int i = 1; i<=n*4; i++) cout<< st[i] <<" ";
//		cout << '\n';
//	}
//	ll get(int id, int l, int r, int u, int v){
//		fix(id, l ,r);
//		if( u > r || v < l) return inf;
//		if(u <= l && v >= r){
//			return st[id];
//		}
//		int mid = (l+r)>>1;
//		ll get1 = get(id*2, l, mid, u, v);
//		ll get2 = get(id*2+1, mid + 1, r, u, v);
//		return min(get1, get2);
//	}
//	
//};
int maxMask , m , p;
string n;
void add(int &x , const int &y)
{
    x += y;
    if(x >= p) x -= p;
}
void sub(int &x , const int &y)
{
    x -= y;
    if(x < 0) x += p;
}
int PRODUCT(int x , int y)
{
    int res = x * y;
    if(res >= p) res %= p;
    return res;
}

struct matrix 
{
    int c[32][32];
    matrix()
    {
        memset(c , 0 , sizeof(c));
    }
    matrix operator * (const matrix &b)
    {
        matrix res;
        matrix a = *this;
        for(int i=0 ; i<maxMask ; ++i) for(int j=0 ; j<maxMask ; ++j)
        {
            res.c[i][j] = 0;
            for(int k=0 ; k<maxMask ; ++k)
            {
                add(res.c[i][j] , PRODUCT(a.c[i][k] , b.c[k][j]));
            }
        }
        return res;
    }
    matrix power(int k)
    {
        if(k == 1) return *this;
        matrix res = power(k/2);
        res = res * res;
        if(1&k) res = res * (*this);
        return res;
    }
}pw[220];

int check(int mask1 , int mask2)
{
    for(int i=1 ; i<m ; ++i)
    {
        int sum = BIT(mask1 , i) + BIT(mask1 , i-1) + BIT(mask2 , i) + BIT(mask2 , i-1);
        if(sum == 0 || sum == 4) return false;
    }
    return true;
}

void solve()
{
    cin >> n >> m >> p;
    if(n == "1")
    {
        cout << (1<<m) % p;
        return;
    }

    for(int i=(int)n.length()-1 ; i>=0 ; --i)
    {
        if(n[i] == '0')
        {
            n[i] = '9';
        }
        else 
        {
            n[i]--;
            break;
        }
    }
    while((int)n.length() > 1 && n[0] == '0') n.erase(0 , 1);

    maxMask = (1<<m);
    reverse(n.begin() , n.end());
    int len = (int)n.size()-1;
    for(int mask1 = 0 ; mask1 < maxMask ; ++mask1) 
    {
        for(int mask2 = 0 ; mask2 < maxMask ; ++mask2)
        {
            pw[0].c[mask1][mask2] = check(mask1 , mask2);
        }
    }
    for(int i=1 ; i<=len ; ++i) pw[i] = pw[i-1].power(10);
    bool found = false;
    matrix tmp;
    for(int i=0 ; i<=len ; ++i)
    {
        if(n[i] == '0') continue;
        if(!found)
        {
            found = true;
            tmp = pw[i].power(n[i] - '0');
        }
        else tmp = tmp * pw[i].power(n[i] - '0');
    }
    int res = 0;
    for(int mask1 = 0 ; mask1 < maxMask ; ++mask1) 
    {
        for(int mask2 = 0 ; mask2 < maxMask ; ++mask2)
        {
            add(res , tmp.c[mask1][mask2]);
        }
    }
    cout << res;
}
int main(){
    MO;
    if(fopen( taskname".inp","r")){
		freopen( taskname".inp","r", stdin);
		freopen( taskname".out","w", stdout);
	}
	int Quang = 1;
//	scanf("%d",&Quang);
//	cin>>Quang;
//	precompute();
	while(Quang--){
		solve();
	}
    return 0;
}
