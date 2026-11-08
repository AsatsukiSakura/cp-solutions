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
	struct item{
		double p;
		ll v,w;
	};
	vector<item>a(n+1);
	vector<vector<double>>dp(n+1,vector<double>(m+1,0.00));
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].v>>a[i].w;
		a[i].p/=100.0000;
	}
	sort(a.begin()+1,a.end(),[](item x,item y){
		return x.v<y.v;
	});
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			if(j>=a[i].w)dp[i][j]=max(dp[i-1][j],a[i].p*a[i].v+(1.00-a[i].p)*dp[i-1][j-a[i].w]);
			//debug(i),debug(j),debug(dp[i][j])<<endl;
			else dp[i][j]=dp[i-1][j];
		}
		
	}//debug(dp[4][1])<<endl;
	cout<<fixed<<setprecision(8)<<*max_element(dp[n].begin(),dp[n].end())<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
