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
vector<int>spf;
vector<int>pr;
void sieve(int n){
	spf.resize(n+1);
	iota(spf.begin(),spf.end(),0);
	for(int i=2;i<=n;i++){
		if(spf[i]==i){
			pr.push_back(i);
		}
		for(int p:pr){
			if(i*p>n)break;
			spf[i*p]=p;
			if(i%p==0) break;
		}
	}
}
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>dp(n+1,inf);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		if(i<=k)dp[i]=0;
		else{
			int ii=i;
			while(ii!=1){
				int p=spf[ii];
				dp[i]=min(dp[i],1+p*dp[i/p]);
				while(ii%p==0)ii/=p;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=dp[a[i]];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(2e5);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
