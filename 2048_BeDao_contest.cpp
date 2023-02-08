#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string s;
ll ans=0,a[100001]={};
void kkk(){
    ll n=0;
    for (ll i=0;i<s.size();i++)
        n=n*10+int(s[i])-48;
    if (n%2048==0) ans++;
}
void Try(ll x){
    if (x==s.size()){
        kkk();
        return;
    }
    if (a[x]==0){
        Try(x+1);
        return;
    }
    for (ll i=0;i<=9;i++){
        s[x]=char(i+48);
        Try(x+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for (ll i=0;i<s.size();i++)
        if (s[i]=='?') a[i]=1;
    Try(0);
    cout<<ans;
}
