#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=19260817;
const ll inf=0x3f3f3f3f;
ll qp(ll base,ll p){
	ll res=1;
	while(p){
		if(p&1){
			res*=base;
			res%=mod;
		}
		base*=base;
		base%=mod;
		p>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<ll>cnt(k+1,0),dp(k+1,0);
	vector<ll>t1=cnt,t2=dp;
	for(int i=1;i<=n;i++){
		t1.assign(k+1,0);
		t2.assign(k+1,0);
		t1[0]=1;
		t2[0]=1;
		for(int j=1;j<=k;j++){
			t1[j]=(cnt[j]+t1[j-1])%mod;
			t2[j]=(dp[j]+(a[i]*t2[j-1])%mod)%mod;
		}
		cnt=t1;dp=t2;
	}
	cout<<(dp[k]*qp(cnt[k],mod-2))%mod;
	return 0;
}
//300*8*4=32*300 B=10kB
