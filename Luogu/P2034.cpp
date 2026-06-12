#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<ll>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto sum=a;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
	}
	vector<vector<ll>>dp(2,vector<ll>(n+1,0));
	deque<int>dq;
	dq.push_back(0);
	for(int i=1;i<=n;i++){
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
		while(!dq.empty()&&dp[0][dq.back()]-sum[dq.back()]<dp[0][i-1]-sum[i-1]){
			dq.pop_back();
		}
		while(!dq.empty()&&dq.front()<i-k){
			dq.pop_front();
		}
		dq.push_back(i-1);
		
		dp[1][i]=dp[0][dq.front()]-sum[dq.front()]+sum[i];
		cerr<<dp[0][i]<<' '<<dp[1][i]<<endl;
		
	}
	cout<<max(dp[1][n],dp[0][n]);
	return 0;
}
