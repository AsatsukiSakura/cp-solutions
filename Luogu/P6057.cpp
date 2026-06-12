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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int>w(n+1,0);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		w[u]++;
		w[v]++;
	}
	ll ans=2ll*n*(n-1)*(n-2)/3;
	for(int i=1;i<=n;i++){
		ans-=1ll*(w[i])*(n-w[i]);
	}
	ans/=2;
	cout<<ans;
	return 0;
}
