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
//xet cac phan tu o phia duoi cung ben phai truoc ma xa goc ben trai nhat, neu no la 1 thi tang bien dem
// sau do cac o o cac hang va cot truoc o xet do phai doi gia tri
//cu the xet tu duoi len tren, phai qua trai den het
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
		int n; cin>>n;
		char a[n+5][n+5];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin>>a[i][j];
			}
		}
		ll cnt =0;
		for(int i=n; i>=1; i--){
			for(int j=n; j>=1; j--){
				if(a[i][j] == '1'){
					cnt++;
					for(int x = 1; x<= i; x++){
						for(int y =1; y<=j; y++){
							if(a[x][y] == '1') a[x][y] = '0';
							else a[x][y] = '1';
//							cout<<a[x][y]<<" ";
						}
//						cout<<'\n';
					}
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
