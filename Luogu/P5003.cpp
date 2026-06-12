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
	int m,n;
	cin>>m>>n;
	vector<vector<int>>grid(m+1,vector<int>(n+1));
	vector<vector<int>>mindp[2];
	mindp[0]=mindp[1]=vector<vector<int>>(m+1,vector<int>(n+1,inf));
	vector<vector<int>>maxdp[2];
	maxdp[0]=maxdp[1]=vector<vector<int>>(m+1,vector<int>(n+1,-inf));
	for(int i=1;i<=m;i++){
		string s;
		cin>>s;
		for(int j=0;j<=n-1;j++){
			grid[i][j+1]=(s[j]=='#'?1:0);
		}
	}
	if(grid[1][1]){
		cout<<-1;
		return 0;
	}
	mindp[0][1][1]=0;
	mindp[1][1][1]=0;
	maxdp[0][1][1]=-1;
	maxdp[1][1][1]=-1;
	for(int i=1;i<=m;i++){
		for(int j=1+(1/i);j<=n;j++){
			if(grid[i][j]){
				mindp[0][i][j]=mindp[1][i][j]=inf;
				maxdp[0][i][j]=maxdp[1][i][j]=-inf;
				continue;
			}
			maxdp[0][i][j]=max(maxdp[0][i-1][j],maxdp[1][i][j-1]+1);
			maxdp[1][i][j]=max(maxdp[0][i-1][j]+1,maxdp[1][i][j-1]);
			mindp[0][i][j]=min(mindp[0][i-1][j],mindp[1][i][j-1]+1);
			mindp[1][i][j]=min(mindp[0][i-1][j]+1,mindp[1][i][j-1]);
		}
	}
	
	if(mindp[0][m][n]!=inf){
		cout<<max(maxdp[0][m][n],maxdp[1][m][n])<<' '<<min(mindp[0][m][n],mindp[1][m][n]);
	}
	else cout<<-1;
	return 0;
}
