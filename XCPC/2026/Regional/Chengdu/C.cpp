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
#define int long long
vector<vector<vector<ll>>>pre(101,vector<vector<ll>>(101,vector<ll>(5000,0)));
void solve(){
	int n,m;
	cin>>n>>m;
	/*
	考虑转换视角？dp[i][j]
	注意到d[i]固定有且仅有末尾会影响到下一段的前缀和
	pre[L][cnt][W]为长度为L，cnt个1，独立贡献为W时对前缀和的方案数
	*/
	vector<vector<ll>>dp(m+1,vector<ll>(n+1,0));
	vector<pii>c(m+1,{1,0});
	for(int i=1;i<=m;i++){
		cin>>c[i].first>>c[i].second;
	}
	dp[0][0]=1;
	for(int i=0;i<=m-1;i++){
		int len=c[i+1].first-c[i].first;
		int dif=c[i+1].second-c[i].second;
		for(int j=n+1;j>=0;j--){
			for(int k=0;k<=len&&j+k<=n;k++){
				//O(sigma(ML)*n)=O(n^2)
				if(dif-len*j<=4999&&dif-len*j>=0){
					dp[i+1][j+k]+=(dp[i][j]*pre[len][k][dif-len*j])%mod;
					dp[i+1][j+k]%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+dp[m][i])%mod;
	auto qp=[&](ll b,ll p){
		ll r=1;
		while(p){
			if(p&1)r=r*b%mod;
			p>>=1;
			b=b*b%mod;
		}
		return r;
	};
	cout<<ans*qp(2,n-c[m].first)%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pre[0][0][0]=1;
	for(int i=1;i<=100;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=4999;k++){
				pre[i][j][k]=(pre[i][j][k]+pre[i-1][j][k])%mod;
				if(j!=0&&k>=i)	pre[i][j][k]=(pre[i][j][k]+pre[i-1][j-1][k-i])%mod;
			}
		}
	}
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
//1000000000000000000 200000000000000001 1000000000000000000 1000000000000000000
