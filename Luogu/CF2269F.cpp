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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int>st;
	vector<int>nge(n+1,0);
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<a[i]){
			nge[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	vector<ll>dp(n+1,0),ls(n+1,0);
	ll ans=1ll*n*(n-1)/2;
	for(int i=n;i>=1;i--){
		if(nge[i]==0){
			dp[i]=0;
			ls[i]=i;
		}
		else{
			ls[i]=ls[nge[i]];
			dp[i]=dp[nge[i]]+ls[i]-nge[i]+1+2*(nge[i]-i-1);
		}
		ans+=dp[i];
		//debug(dp[i]);
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
