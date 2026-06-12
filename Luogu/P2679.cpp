#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
inline int add(ll &a,ll b){
	return a=(a+b>=mod?a+b-mod:a+b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b;
	int n,m,k;
	cin>>n>>m>>k>>a>>b;
	//dp[0/1][i][j][k]表示第i位选了/没选时，a的前i个分k段组成b的前j个
	a=' '+a;
	b=' '+b;
	vector<vector<vector<ll>>>dp(2,vector<vector<ll>>(m+1,vector<ll>(k+1,0)));
	vector<vector<vector<ll>>>tmp=dp;
	for(int i=1;i<=n;i++){
		dp[0][0][0]=1;
		tmp=vector<vector<vector<ll>>>(2,vector<vector<ll>>(m+1,vector<ll>(k+1,0)));
		for(int j=1;j<=m;j++){
			for(int s=1;s<=k;s++){
				if(a[i]==b[j]){
					add(tmp[1][j][s],dp[1][j-1][s-1]);
					add(tmp[1][j][s],dp[1][j-1][s]);
					add(tmp[1][j][s],dp[0][j-1][s-1]);
					add(tmp[0][j][s],dp[0][j][s]);
					add(tmp[0][j][s],dp[1][j][s]);
				}
				else{
					add(tmp[0][j][s],dp[0][j][s]);
					add(tmp[0][j][s],dp[1][j][s]);
				}
			}
		}
		dp=tmp;
	}
	cout<<(dp[1][m][k]+dp[0][m][k])%mod;
	return 0;
}
