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
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<vector<vector<ll>>>dp(3,vector<vector<ll>>(8,vector<ll>(n+1,0)));
	dp[0][0][n]=1;
	auto add=[](ll &a,const ll &b){
		a=(a+b)%mod;
	};
	sort(a.begin()+1,a.end());
	for(int i=n;i>=1;i--){
		int delta=a[i]-a[i-1];
		for(int j=0;j<=2;j++){
			for(int mask=0;mask<=7;mask++){
				int nmask=0;
				if(delta<3)nmask=(mask<<delta)&7;
				add(dp[j][nmask][i-1],dp[j][mask][i]);
				int f=(mask!=3&&mask!=5&&mask!=6);
				if(j+f<=2){
					if(delta<=3) nmask|=1<<(delta-1);
					add(dp[j+f][nmask][i-1],dp[j][mask][i]);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=2;i++){
		for(int mask=0;mask<=7;mask++)
			add(ans,dp[i][mask][0]);
	}
	add(ans,mod-1);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
