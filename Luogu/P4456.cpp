#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=unsigned long long;
using pii=pair<int,int>;
ll mod;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r*=b;
			r%=mod;
		}
		b*=b;
		b%=mod;
		p>>=1;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,a,b;
	cin>>n>>a>>b>>mod;
	vector<ll>fact(n+2,1),inv(n+2);
	for(int i=1;i<=n+1;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	
	inv[n+1]=qp(fact[n+1],mod-2);
	for(int i=n;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	ll ans=0;
	for(int i=0;i<=(n+1)/2;i++){
		ans+=fact[n+1-i]*inv[i]%mod*inv[n+1-2*i]%mod*qp(n-i,a)%mod*qp(i,b)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
