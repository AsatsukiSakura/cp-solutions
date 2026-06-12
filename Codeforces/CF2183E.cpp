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
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>div(m+1);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j+=i){
			if(j+i<=m)div[j].push_back(i);
		}
	}
	vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
	if(a[1]!=1&&a[1]!=0){
		cout<<"0\n";
		return;
	}
	dp[1][1]=1;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==0)continue;
			for(int p:div[j]){
				if(a[i+1]==0||a[i+1]==j+p){
					dp[i+1][j+p]+=dp[i][j];
					dp[i+1][j+p]%=mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
