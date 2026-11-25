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
	vector<int>l(n+1),r(n+1);
	vector<vector<int>>cnt(2*n+1,vector<int>(2*n+1,0));
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		cnt[l[i]][r[i]]++;
	}
	vector<int>dp(2*n+1,0);
	for(int i=1;i<=2*n;i++){
		vector<int>suf(i+1,0);
		for(int j=i-1;j>=1;j--)
			suf[j]=suf[j+1]+cnt[j][i];
		dp[i]=dp[i-1]+cnt[i][i];
		for(int j=i-1;j>=1;j--){
			int tmp=0;
			int pre=0;
			if(cnt[j][i]){
				for(int k=j+1;k<=i-1;k++){
					pre+=cnt[j][k];
					tmp=max(tmp,pre+suf[k]);
				}
			}
			dp[i]=max(dp[i],dp[j]+cnt[j][i]+tmp+cnt[i][i]);
		}
	}	
	cout<<dp[2*n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
