#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
void solve(){
	int i,dp[MAXN],n,a[MAXN];
	cin>>n;
	vector<queue<int>> q(n+1);
	dp[0]=0;
	for(i=1;i<=n;i++){		
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		dp[i]=dp[i-1];
		q[a[i]].push(i);
		if(q[a[i]].size()>a[i])	q[a[i]].pop();
		if(q[a[i]].size()==a[i]) dp[i]=max(dp[i],a[i]+dp[q[a[i]].front()-1]);
	}
	cout<<dp[n]<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)	solve();
	return 0;
}
