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
const vector<ll>mod={998244353,(ll)1e9+7};
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=r*b%mod[0];
		}
		b=b*b%mod[0];
		p>>=1;
	}
	return r;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<bool>>a(n+2,vector<bool>(m+2));
	vector<vector<ll>>w[2],dp[2],pd[2],h[2];
	w[0]=w[1]=vector<vector<ll>>(n+2,vector<ll>(m+2,0));
	dp[0]=dp[1]=vector<vector<ll>>(n+2,vector<ll>(m+2,0));
	pd[0]=pd[1]=vector<vector<ll>>(n+2,vector<ll>(m+2,0));
	h[0]=h[1]=vector<vector<ll>>(n+2,vector<ll>(m+2,0));
	mt19937 rng(time(0));
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			a[i][j]=s[j-1]-'0';
		}
	}
	map<pll,int>mp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			w[0][i][j]=rng()%(mod[0]-1)+1;
			w[1][i][j]=rng()%(mod[0]-1)+1;
		}
	for(int k=0;k<=1;k++)
		dp[k][1][1]=pd[k][n][m]=1;
	for(int i=1;i<=n;i++)
		for(int j=1+1/i;j<=m;j++)
			for(int k=0;k<=1;k++)
				if(a[i][j])
					dp[k][i][j]=(dp[k][i-1][j]*w[0][i-1][j]%mod[k]
								+dp[k][i][j-1]*w[1][i][j-1]%mod[k])%mod[k];
				else dp[k][i][j]=0;
	for(int i=n;i>=1;i--)
		for(int j=m-1/(n+1-i);j>=1;j--)
			for(int k=0;k<=1;k++)
				if(a[i][j])
				pd[k][i][j]=(pd[k][i+1][j]*w[0][i][j]%mod[k]
							+pd[k][i][j+1]*w[1][i][j]%mod[k])%mod[k];
				else pd[k][i][j]=0;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			for(int k=0;k<=1;k++)
				h[k][i][j]=dp[k][i][j]*pd[k][i][j]%mod[k];
			mp[{h[0][i][j],h[1][i][j]}]++;
		}
	ll ans=0;
	for(auto[p,cnt]:mp)
		ans=(ans+qp(2,cnt)+mod[0]-1)%mod[0];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
