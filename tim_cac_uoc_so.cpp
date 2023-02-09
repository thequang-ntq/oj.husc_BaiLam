#pragma GCC optimize("03,unroll-loops")
#pragma GCC optimization("-funroll-all-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define MO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define MAX(a, b) ( (a > b) ? a : b)
#define MIN(a, b) ( (a < b) ? a : b)
#define ABS(x) (x <0 ? -x : x)
#define ll long long
#define MOD 1000000007
#define div6 166666668
#define mod 998244353
#define taskname "__Quang__"
#define double long double
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
using namespace std;
using ull = unsigned long long;
const ll inf = 1000000003;
//const int base = 311;
const int maxn = 1e4 + 2;
const double Pi = 3.1415926535897323846;
const double eps = 1e-9;
int sign(double x){
	if(x > eps) return 1;
	if(x < -eps) return -1;
	return 0;
}
long long __lcm(int a, int b){
	return (a / __gcd(a,b)) * b;
}
bool coprime(int a, int b){
	return(__gcd(a,b) == 1);
}
bool pr(ll n){
	if(n<=1) return false;
	if(n<=3) return true;
	for(ll i =2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}
ll binpow(ll a, ll b){
	ll res =1;
	a %= MOD;
	while(b > 0){
		if(b & 1){
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
ull fac(ll n){
	ll res = 1;
	for(ll i =n; i>=2; i--){
		res *= i;
	}
	return res;
}
ull npk(ll n, ll k){
	return fac(n) / fac(n-k);
}
ull nck(ll k, ll n){
	if(k==0 || k==n ) return 1;
	if(k==1) return n;
	return nck(k-1, n-1) + nck(k, n-1);
}
ll Pow[maxn], hashT[maxn];
ll gethashT(int i, int j){
	return (hashT[j] - hashT[i-1] * Pow[j-i+1] + inf * inf) % inf;
}
//class SegTree{
//public:
//	int n;
//	vector<pair<ll,ll>>st;
//	vector<ll>lazy, a;
//public:
//	SegTree(){}
//	SegTree(const vector<pair<ll,ll>>&t){
//		this -> n = t.size() - 1;
//		this -> lazy.resize(n*4+5);
//		this -> st.resize(n*4+5);
//		this -> st = t;
////		build(1,1,n);
//	}
////	void build(int id, int l, int r){
////		if(l == r){
////			st[id] = a[l];
////			return;
////		}
////		int mid = (l+r)>>1;
////		build(id*2, l, mid);
////		build(id*2+1, mid+1, r);
////		st[id] = (st[id*2] ^ st[id*2+1] ); 
////	}
////	void fix(int id, int l, int r){
////		if(!lazy[id]) return;
////		st[id] += lazy[id] * (r-l+1) * 1LL;
////		if(l < r){
////			lazy[id*2] += lazy[id];
////			lazy[id*2+1] += lazy[id];
////		}
////		lazy[id] = 0;
////	}
//	void update(int id, int l, int r, int u, int v, int val){
////		fix(id, l, r);
//		if( u > r || v < l) return;
//		if( u <= l && v >= r){
////			lazy[id] = 1;
////			fid(id, l, r);
//			st[id].second += val;
//			if( st[id].second != 0) st[id].first = r - l + 1;
//			else if( l != r) st[id].first = st[id*2].first + st[id*2+1].first;
//			else st[id].first = 0;
//			return;
//		}
//		int mid = (l+r)>>1;
//		update(id*2, l, mid, u, v, val);
//		update(id*2+1, mid + 1, r, u , v, val);
//		if(st[id].second != 0) st[id].first = r - l + 1;
//		else st[id].first = st[id*2].first + st[id*2+1].first;
////		cout<< st[id] << '\n';
//	}
//	ll get(int id, int l, int r, int u, int v){
////		fix(id, l, r);
//		if(u > r || v < l) return 0;
//		if(u <= l && v >= r) return st[id];
//		int mid = (l+r)>>1;
//		ll get1 = get(id*2, l, mid, u, v);
//		ll get2 = get(id*2+1, mid+1, r, u, v);
//		return (get1 ^ get2);	
//	}
//};
//class FenwickTree{
//private:
//	int n;
//	vector<ll>bit;
//public:
//	FenwickTree(){}
//	FenwickTree(const vector<ll>&x ){
//		this -> n = x.size() - 1;
//		this -> bit = x;
//	}
//	void update(int p, int val){
//		int idx = p;
//		while(idx <= n){
//			bit[idx] ^= val;
//			idx += (idx & (-idx));
//		}
//	}
//	ll sum(int p){
//		ll res = 0;
//		while(p){
//		 	res ^= bit[p];
////			else{
////				res ^= bit[p];
//				p -= (p & (-p));
////			}
//		}
//		return res;
//	}
//	ll query(int l, int r){
//		return (sum(r) ^ sum(l-1) );
//	}
//};
unsigned base[46656 / 64], segment[100032 / 64], primes[5000];
void sieve()
{
    unsigned i, j, k;
    for (i = 3; i<216; i += 2)
        if (!chkC(base, i))
            for (j = i*i, k = i << 1; j<46656; j += k)
                setC(base, j);
    primes[0] = 2;
    for (i = 3, j = 1; i<46656; i += 2)
        if (!chkC(base, i))
            primes[j++] = i;
}
vector <pair<int,int>> factors;
void primeFactors(int num)
{
    int expo = 0;   
    for (int i = 0; primes[i] <= sqrt(num); i++)
    {
        expo = 0;
        int prime = primes[i];
        while (num % prime == 0){
            expo++;
            num = num / prime;
        }
        if (expo>0)
            factors.push_back(make_pair(prime, expo));
    }

    if ( num >= 2)
        factors.push_back(make_pair(num, 1));

}

vector <int> divisors;
void setDivisors(int n, int i) {
    int j, x, k;
    for (j = i; j<factors.size(); j++) {
        x = factors[j].first * n;
        for (k = 0; k<factors[j].second; k++) {
            divisors.push_back(x);
            setDivisors(x, j + 1);
            x *= factors[j].first;
        }
    }
}
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1,  1,-1};
int main() {
	MO;
	if(fopen( taskname".inp","r")){
		freopen( taskname".inp","r", stdin);
		freopen( taskname".out","w", stdout);
	}
	int Quang = 1;
//	scanf("%d",&Quang);
//	cin>>Quang;
//	sieve();
	while(Quang--){
		ll n; cin>>n;
		divisors.clear();
		factors.clear();
		primeFactors(n);
		setDivisors(1,0);
	}
	return 0;
}
/*
5
-5 -3 6
-1 -2 3
0 0 2
-2 2 1
-4 -1 2
*/
