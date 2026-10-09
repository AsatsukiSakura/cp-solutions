#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n,m;
	cin>>n>>m;
	auto f=[&](int i,int j){
		if(i<1 || j<1 || i>n || j>m) return 0;
		return (i-1)*m+j;
	};
	vector<ll>a(n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[f(i,j)];
			a[f(i,j)]=(a[f(i,j)]+mod)%mod;
		}
	}
	vector<ll>ul(n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ll val=((i&1)&&(j&1))?a[f(i,j)]:0;
			ul[f(i,j)]=(ul[f(i,j-1)]+ul[f(i-1,j)]-ul[f(i-1,j-1)]+val+mod)%mod;
		}
	}
	vector<ll>ur(n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			ll val=((i&1)&&((m-j+1)&1))?a[f(i,j)]:0;
			ur[f(i,j)]=(ur[f(i,j+1)]+ur[f(i-1,j)]-ur[f(i-1,j+1)]+val+mod)%mod;
		}
	}
	vector<ll>dl(n*m+1);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			ll val=(((n-i+1)&1)&&(j&1))?a[f(i,j)]:0;
			dl[f(i,j)]=(dl[f(i,j-1)]+dl[f(i+1,j)]-dl[f(i+1,j-1)]+val+mod)%mod;
		}
	}
	vector<ll>dr(n*m+1);
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			ll val=(((n-i+1)&1)&&((m-j+1)&1))?a[f(i,j)]:0;
			dr[f(i,j)]=(dr[f(i,j+1)]+dr[f(i+1,j)]-dr[f(i+1,j+1)]+val+mod)%mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(((n-i+1)&1)&&((m-j+1)&1))ans+=a[f(i,j)]*ul[f(i,j)]%mod,ans%=mod;
			if(((n-i+1)&1)&&(j&1))ans+=a[f(i,j)]*ur[f(i,j+1)]%mod,ans%=mod;
			if((i&1)&&((m-j+1)&1))ans+=a[f(i,j)]*dl[f(i+1,j)]%mod,ans%=mod;
			if((i&1)&&(j&1))ans+=a[f(i,j)]*dr[f(i+1,j+1)]%mod,ans%=mod;
		}
	}
	if((n+m)&1)ans=ans*(mod-1)%mod;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
