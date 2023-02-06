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
const int maxn = 1e6+7;
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
ll fac(int n){
	ll res = 1;
	for(int i =n; i>=2; i--){
		res *= i;
	}
	return res;
}
ll npk(int n, int k){
	return fac(n) / fac(n-k);
}
ll nck(int n, int k){
	return fac(n) / (fac(n-k) * fac(k) );
}
ll Pow[maxn], hashT[maxn];
ll gethashT(int i, int j){
	return (hashT[j] - hashT[i-1] * Pow[j-i+1] + inf * inf) % inf;
}
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1,  1,-1};
ll hashing[maxn];
ll a[maxn];
ll k, n, cnt=0 ;
void solve(){
	memset(hashing, 0, sizeof(hashing));
	ll sum =0;
	for(int i=0; i<n; i++){
		sum += a[i];
		hashing[ ((sum % k) + k) % k]++;
	}
	for(int i=0; i<k; i++){
		if(hashing[i] > 1){
			cnt += (hashing[i] * (hashing[i] - 1) ) / 2;
		}
	}
	cnt += hashing[0];
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
		cin>>n>>k;
		for(int i=0; i<n; i++) cin>>a[i];
		solve();
		cout<<cnt<<'\n';
	}
	return 0;
}
