#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,sum;
	cin>>n>>m;
	vector<int>p(m+1);
	vector<int>a(n),b(n),c(n);
	vector<ll>tot(n+1,0);
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=m-1;i++){
		int x=min(p[i],p[i+1]);
		int y=max(p[i],p[i+1]);
		tot[x]++;tot[y]--;
	}
	for(int i=1;i<=n-1;i++){
		tot[i]+=tot[i-1];
	}
	ll ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=min(1ll*tot[i]*a[i],c[i]+1ll*tot[i]*b[i]);
	}
	cout<<ans;
	return 0;
}
