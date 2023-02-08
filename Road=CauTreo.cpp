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
using namespace std;
using ull = unsigned long long;
const ll inf = 1000000003;
const int base = 311;
const int maxn = 1e5+7;
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
	if(b==0) return 1;
	ll p = binpow(a, (b>>1));
	p*=p; p%=MOD;
	if(b&1){
		p*=a; p%=MOD;
	}
	return p;
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
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1,  1,-1};
//class SegTree{
//private:
//	int n;
//	vector<ll>a, lazy, st;
//public:
//	SegTree(){}
//	SegTree(const vector<ll>&x){
//		this -> n = x.size() - 1;
//		this -> lazy.resize(n*4);
//		this -> st.resize(n*4);
//		this -> a = x;
//		build(1,1,n);
//	}
//	void build(int id, int l, int r){
//		if(l==r){
//			st[id] = 0;
//			return;
//		}
//		ll mid = (l+r)>>1;
//		build(id*2, l, mid);
//		build(id*2 + 1, mid + 1, r);
//		st[id] = st[id*2] + st[id*2 + 1];
//	}
//	void fix(int id, int l, int r){
//		if(!lazy[id]) return;
//		st[id] += lazy[id] * (r - l + 1) * 1LL;
//		if( l < r){
//			lazy[id*2] += lazy[id];
//			lazy[id*2+1] += lazy[id];
//		}
//		lazy[id] = 0;
//	}
//	void update(int id, int l, int r, int u, int v){
//		fix(id, l, r);
//		if(u > r || v < l) return;
//		if(u <= l && v >= r){
//			lazy[id] = 1;
//			fix(id,l,r);
//			return;
//		}
//		ll mid = (l+r)>>1;
//		update(id*2, l, mid, u, v);
//		update(id*2+1, mid + 1, r, u ,v);
//		st[id] = st[id*2] + st[id*2+1];
//	}
//	ll get(int id, int l, int r, int p){
//		fix(id,l,r);
//		if(l==r) return st[id];
//		int mid = (l+r)>>1;
//		if(p<=mid) return get(id*2, l, mid, p);
//		else return get(id*2+1, mid+1, r, p);
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
int low[maxn];
int n,m, par[maxn], sz[maxn], cnt =0, timedfs = 0;
vector<int>adj[maxn];
bool vis[maxn];
void inp(){
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(vis, false, sizeof(vis));
	for(int i=1; i<=n; i++) par[i] = i;
	memset(low, 0, sizeof(low));
}
void dfs(int u){
	vis[u] = true; timedfs++;
	low[u] = timedfs;
	for(auto v: adj[u]){
		if(!vis[v]){
			dfs(v);
			par[v] = u;
		}
		else{
			if(low[v] < low[u]){
				low[v] = max(low[v], par[v]);
			}
		}
	}
}
void solve(){
	dfs(1);
	for(int i=1; i<=n; i++){
		cnt += (adj[i].size()==1);
	}
	cout<< (cnt + 1) / 2;
}
int main() {
	MO;
	if(fopen( taskname".inp","r")){
		freopen( taskname".inp","r", stdin);
		freopen( taskname".out","w", stdout);
	}
	int Quang = 1;
//	scanf("%d",&Quang); 
//	cin>>Quang;
	while(Quang--){
		inp();
		solve();
	}
	return 0;
}
