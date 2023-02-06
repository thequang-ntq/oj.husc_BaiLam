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
//priority_queue, queue
//deque max_min tinh tien
//khi cho mot value vao hang doi uu tien, so sanh phan tu cuoi hang doi voi value chuan bi them vao, neu cuoi nho hon hoac bang them thi bo cho toi khi lon hon
//khi moi them value moi vao, so sanh khoang cach voi phan tu o dau hang doi va xoa cho den khi khoang cach nho hon hoac bang d
//cuoi cung so sanh gia tri value moi them vao do voi gia tri value o dau hang doi, neu gap doi hoac hon thi ben trai duong thang da ok
//tuong tu, lam nguoc lai cho ben phai
//sau tat ca, xet trong hang doi, duyet tuan tu, neu co a[i-1] va a[i] va a[i+1] thoa dk thi cong cnt++
struct point{
	ll position;
	ll value;
};
vector<point>vec;
bool cmp(point a, point b){
	return a.position < b.position;
}
point Queue[maxn];
ll lefts, rights;
bool vis[maxn], reverse_vis[maxn];
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
		ll n,d; cin>>n>>d;
		map<ll,ll>mp;
		ll cnt =0;
		for(int i=0; i<n; i++){
			ll x, val; cin>>x>>val;
			vec.push_back({x,val});
		}
		sort(begin(vec), end(vec), cmp);
		lefts = 1, rights = 0;
		memset(vis,false,sizeof(vis));
		memset(reverse_vis,false,sizeof(reverse_vis));
		memset(Queue, 0, sizeof(Queue));
		for(int i=0; i<n; i++){
			while(lefts <= rights && Queue[rights].value < vec[i].value ){
				rights--;
			}
			rights++;
			Queue[rights] = vec[i];
			while(lefts <= rights && Queue[lefts].position < vec[i].position - d){
				lefts++;
			}
			if(Queue[lefts].value >= vec[i].value*2){
				vis[i] = true;
//				cout<<i<<'\n';			
			}
		}
		memset(Queue, 0, sizeof(Queue));
		lefts = 1, rights = 0;
		for(int i=n-1; i>=0; i--){
			while(lefts <= rights && Queue[rights].value < vec[i].value ){
				rights--;
			}
			rights++;
			Queue[rights] = vec[i];
			while(lefts <= rights && Queue[lefts].position > vec[i].position + d){
				lefts++;
			}
			if(Queue[lefts].value >= vec[i].value*2){
				reverse_vis[i] = true;			
//				cout<<i<<'\n';
			}
		}
		for(int i=0; i<n; i++){
			if(vis[i] && reverse_vis[i]){
				cnt++;
			}
//			cout<<vis[i] <<" "<< reverse_vis[i]<< '\n';
		}
		cout<<cnt;
	}
	return 0;
}
