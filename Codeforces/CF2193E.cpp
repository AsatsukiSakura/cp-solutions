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
	vector<int>dp(n+1,inf);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]]=1;
	}
	sort(a.begin()+1,a.end());
	vector<vector<int>>facs(n+1);
	for(int d=2;d<=n/2;d++){
		//存储不是自身也不是1的因数
		for(int i=2*d;i<=n;i+=d){
			facs[i].push_back(d);
		}
	}
	for(int i=4;i<=n;i++){
		for(int d:facs[i]){
			dp[i]=min(dp[i],dp[i/d]+dp[d]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<(dp[i]==inf?-1:dp[i])<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
