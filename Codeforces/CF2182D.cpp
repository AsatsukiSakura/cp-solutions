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
ll fact[51];
ll qp(ll base,ll x){
	ll res=1;
	while(x){
		if(x&1){
			res*=base;
			res%=mod;
		}
		base*=base;
		base%=mod;
		x>>=1;
	}
	return res;
}
ll comb(ll x,ll k){
	if(k<0||k>x)return 0;
	return ((1ll*fact[x]*qp(fact[k],mod-2))%mod*qp(fact[x-k],mod-2))%mod;
}
void solve(){
	int n;
	cin>>n;
	ll sum=0;
	vector<int>a(n+1);
	for(int i=0;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll k=sum/n;
	ll r=sum%n;
	if(*max_element(a.begin()+1,a.end())>k+1){
		cout<<"0\n";
		return;
	}
	int ks=0;
	for(int i=1;i<=n;i++){
		ks+=(a[i]<=k);
	}
	cout<<((comb(ks,n-r)*fact[n-r])%mod*fact[r])%mod<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fact[0]=1;
	for(int i=1;i<=50;i++){
		fact[i]=(1ll*i*fact[i-1])%mod;
	}
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
