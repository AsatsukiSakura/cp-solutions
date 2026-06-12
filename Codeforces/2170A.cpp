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
void solve(){
	int n;
	cin>>n;
	int a[n+5][n+5];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=(i-1)*n+j;
		}
	}
	int ans=-inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i+1][j]);
		}
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
