#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
vector<ll>fac(1e6+1,1);
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1)
			r=r*b%mod;
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
ll C(ll n,ll k){
	if(n==-1)return 1;
	return fac[n]*qp(fac[k],mod-2)%mod*qp(fac[n-k],mod-2)%mod;
}
void solve(){
	int n;
	string s;
	cin>>n>>s;
	s=' '+s;
	vector<int>a(4,-1);
	for(int i=1;i<=n;i++){
		a[s[i]-'0']++;
		if(i==n || s[i+1]!=s[i])
			a[2+s[i]-'0']++;
	}
	cout<<C(a[0],a[2])*C(a[1],a[3])%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=1e6;i++)fac[i]=fac[i-1]*i%mod;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
