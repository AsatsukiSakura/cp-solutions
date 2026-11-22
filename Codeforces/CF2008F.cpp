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
	int n;
	cin>>n;
	ll sum=0;
	vector<int>a(n+1);
	auto add=[&](ll &a,const ll &b){
		a=(a+b)%mod;
	};
	for(int i=1;i<=n;i++)
		{cin>>a[i];add(sum,a[i]);}
	ll sq=0;
	for(int i=1;i<=n;i++){
		add(sq,1ll*a[i]*sum%mod);
		add(sq,mod-1ll*a[i]*a[i]%mod);
	}
	auto qp=[&](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)r=r*b%mod;
			p>>=1;
			b=b*b%mod;
		}
		return r;
	};
	cout<<sq*qp(1ll*n*(n-1)%mod,mod-2)%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
