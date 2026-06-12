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
	int t,k;
	cin>>t>>k;
	int n=2000;
	vector<vector<int>>c(n+1,vector<int>(n+1,0));
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
		}
	}
	vector<vector<int>>s(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+(j<=i&&c[i][j]==0);
		}
	}
	for(int i=1;i<=t;i++){
		int n,m;
		cin>>n>>m;
		cout<<s[n][m]<<endl;
	}
	return 0;
}
