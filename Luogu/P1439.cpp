#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	vector<int>a(n+1),b(n+1),dp(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=dp[b[i]];
	}
	dp.assign(1,0);
	for(int i=1;i<=n;i++){
		auto it=lower_bound(dp.begin(),dp.end(),b[i]);
		if(it==dp.end())dp.push_back(b[i]);
		else *it=b[i];
	}
	cout<<dp.size()-1;
	return 0;
}
