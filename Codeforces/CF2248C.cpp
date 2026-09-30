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
	cin>>n;
	vector<int>a(2*n+1);
	vector<pii>r(n+1,{0,0});
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(r[a[i]].first)r[a[i]].second=i;
		else r[a[i]].first=i;
	}
	auto cmp=[](pii a,pii b){
		return a.second<b.second;
	};
	sort(r.begin()+1,r.end(),cmp);
	vector<ll>dp(n+1,0);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int j=upper_bound(r.begin()+1,r.end(),pii{0,r[i].first-1},cmp)-r.begin()-1;
		ll l=r[i].second-r[i].first+1;
		dp[i]=max(dp[i],dp[j]+l*l-l);
	}
	cout<<*max_element(dp.begin()+1,dp.end())+2*n<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
