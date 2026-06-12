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
void solve(){
	int n;cin>>n;
	map<int,int>m;m[0]=1;
	vector<int>sum(n+1);sum[0]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum[i]=sum[i-1]+a;
		m[sum[i]]++;
		ans=max(ans,m[sum[i]]-1);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
