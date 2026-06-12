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
	ll h;
	cin>>n>>h;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<ll>>mxh(n+1,vector<ll>(n+1,0));
	for(int i=1;i<=n;i++){
		mxh[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			mxh[i][j]=max(mxh[i][j-1],a[j]);
		}
	}
	vector<vector<ll>>wsum(n+1,vector<ll>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int c=1;c<=n;c++){
			wsum[i][c]=wsum[i][c-1]+h-(c>=i?mxh[i][c]:mxh[c][i]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,wsum[i][n]);
		int k=i;
		for(int j=i+1;j<=n;j++){
			while(k<j &&mxh[i][k+1]<=mxh[k+1][j])k++;
			ans=max(ans,wsum[i][k]+wsum[j][n]-wsum[j][k]);
		}
		
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
