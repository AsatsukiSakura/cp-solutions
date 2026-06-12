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
	int n,m;
	cin>>n>>m;
	vector<pair<pii,int>>a(m+1);
	for(int i=1;i<=m;i++){
		cin>>a[i].second>>a[i].first.first>>a[i].first.second;
	}
	vector<int>dp(m+1,1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i-1;j++){
			int dist=abs(a[i].first.first-a[j].first.first)+abs(a[i].first.second-a[j].first.second);
			if(dist<=a[i].second-a[j].second){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<*max_element(dp.begin(),dp.end());
	return 0;
}
