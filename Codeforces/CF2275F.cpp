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
const ll pod=985661441;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
vector<int>primes;
vector<int>spf(1e6+1);
ll qp(ll b,ll p,ll z){
	ll r=1;
	while(p){
		if(p&1)
			r=r*b%z;
		b=b*b%z;
		p>>=1;
	}
	return r;
}
void solve(){
	int n;
	cin>>n;
	vector<ll>a(n+1);
	map<int,int>c;
	ll h1=1,h2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int p:primes){
			if(1ll*p*p>a[i])break;
			while(a[i]%(p*p)==0)a[i]/=(p*p);
		}
		c[a[i]]++;
	}
	map<int,int>cp;
	ll ans=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x!=1){
			cp[spf[x]]++;
			if(cp[spf[x]]&1){
				h1=h1*spf[x]%mod;
				h2=h2*spf[x]%pod;
			}
			else{
				h1=h1*qp(spf[x],mod-2,mod)%mod;
				h2=h2*qp(spf[x],pod-2,pod)%pod;
			}
			x/=spf[x];
		}
			if(h1==h2 && h1<=1000000 )ans+=c[h1];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=1e6;
	iota(spf.begin(),spf.end(),0);
	for(int i=2;i<=n;i++){
		if(spf[i]==i)
			primes.push_back(i);
		for(int p:primes){
			if(i*p>n)break;
			spf[i*p]=p;
			if(p==spf[i]) break;
		}
	}
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
