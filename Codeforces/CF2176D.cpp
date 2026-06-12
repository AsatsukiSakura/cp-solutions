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
	vector<ll>a(n+1);
	vector<pair<ll,int>>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]={a[i],i};
	}
	sort(p.begin()+1,p.end());
	int mn=*min_element(a.begin()+1,a.end());
	vector<vector<int>>adj(n+1);		
	vector<map<ll,ll>>dp(n+1);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(a[v]>a[u]){
			adj[u].push_back(v);
		}
		dp[v][a[u]+a[v]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int u=p[i].second;
		for(auto[val,cnt]:dp[u]){
			ans+=cnt;
			ans%=mod;
		}
		for(auto v:adj[u]){			
			if(dp[u].count(a[v])){
				dp[v][a[u]+a[v]]+=dp[u][a[v]];
			}
			dp[v][a[u]+a[v]]%=mod;
		}
	}
	cout<<ans%mod<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
