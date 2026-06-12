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
	int n;
	pii a,b;
	cin>>n;
	cin>>a.first>>a.second;
	cin>>b.first>>b.second;
	/*
	离散化x
	记录同一个x上 y的最大最小值
	dp[0/1][i]
	*/
	vector<int>x(n+1);
	vector<pii>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
		p[i].first=x[i];
	}
	sort(x.begin()+1,x.end());
	x.erase(unique(x.begin()+1,x.end()),x.end());
	int l=x.size()-1;
	for(int i=1;i<=n;i++){
		p[i].first=lower_bound(x.begin()+1,x.end(),p[i].first)-x.begin();
		cin>>p[i].second;
	}
	sort(p.begin()+1,p.end());
	vector<int>mn(l+1,inf),mx(l+1,0),dis(l+1);
	for(int i=1;i<=n;i++){
		mn[p[i].first]=min(mn[p[i].first],p[i].second);
		mx[p[i].first]=max(mx[p[i].first],p[i].second);
	}
	for(int i=1;i<=l;i++){
		dis[i]=mx[i]-mn[i];
	}
	vector<vector<ll>>dp(2,vector<ll>(l+1,inf*inf));
	dp[0][1]=abs(mx[1]-a.second)+dis[1];
	dp[1][1]=abs(mn[1]-a.second)+dis[1];
	//0low1high
	for(int i=2;i<=l;i++){
		dp[0][i]=min(dp[0][i],dp[0][i-1]+abs(mx[i]-mn[i-1])+dis[i]);
		dp[0][i]=min(dp[0][i],dp[1][i-1]+abs(mx[i]-mx[i-1])+dis[i]);
		dp[1][i]=min(dp[1][i],dp[0][i-1]+abs(mn[i]-mn[i-1])+dis[i]);
		dp[1][i]=min(dp[1][i],dp[1][i-1]+abs(mn[i]-mx[i-1])+dis[i]);
	}
	ll ans=min(dp[1][l]+abs(b.second-mx[l]),dp[0][l]+abs(b.second-mn[l]));
	ans+=(b.first-a.first);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
