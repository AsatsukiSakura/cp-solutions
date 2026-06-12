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
ll phi(ll x){
	ll r=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			r/=i;
			r*=(i-1);
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1){r/=x;r*=(x-1);}
	return r;
}
void solve(){
	int n;
	cin>>n;
	ll ans=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ans+=phi(i)*qp(n,n/i);
			ans%=mod;
			if(i*i!=n){
				ans+=phi(n/i)*qp(n,i);
				ans%=mod;
			}
		}
	}
	cout<<ans*qp(n,mod-2)%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
