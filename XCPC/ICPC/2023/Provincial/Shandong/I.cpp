#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll mod1=998244353;
const ll mod2=1000000007;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p,ll mod){
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
pll read(string s){
	ll r1=0,r2=0;
	for(char c:s){
		r1=(r1*10+c-'0')%mod1;
		r2=(r2*10+c-'0')%mod2;
	}
	return {r1,r2};
}
void solve(){
	string s;
	cin>>s;
	ll x1=read(s).first;
	ll x2=read(s).second;
	double lx;
	if(x1==x2)	lx=log10(x1);
	else lx=(s.size()-1)+log10(s[0]-'0'+(s[1]-'0')*1e-1+(s[2]-'0')*1e-2+(s[3]-'0')*1e-3);
	double f=0;
	int n=1;
	for(;;n++){
		f+=log10(n);
		if(f>lx-1e-3)break;
	}
	ll f1=1,f2=1;
	for(int i=1;i<=n;i++){
		f1=f1*i%mod1;
		f2=f2*i%mod2;
	}
	for(int i=1;i<=n-1;i++){
		ll r1=f1*qp(i,mod1-2,mod1)%mod1;
		ll r2=f2*qp(i,mod2-2,mod2)%mod2;
		if(r1==x1&&r2==x2){
			cout<<n<<' '<<i<<'\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	while(t--)solve();
	return 0;
}
