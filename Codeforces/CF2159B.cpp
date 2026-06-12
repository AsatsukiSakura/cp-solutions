#include<bits/stdc++.h>
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int n,m;
	bool trans;
	cin>>n>>m;
	vector<vector<int>>p,g;
	string str;
	if(n>m){
		trans=true;
		p.resize(m+1,vector<int>(n+1));
		g.resize(m+1,vector<int>(n+1,inf));
		for(int i=1;i<=n;i++){
			cin>>str;
			for(int j=1;j<=m;j++){
				p[j][i]=str[j-1]-'0';
			}
		}
		swap(m,n);
	}
	else{
		trans=false;	
		p.resize(n+1,vector<int>(m+1));
		g.resize(n+1,vector<int>(m+1,inf));
		for(int i=1;i<=n;i++){
			cin>>str;
			for(int j=1;j<=m;j++){
				p[i][j]=str[j-1]-'0';
			}
		}
	}
	for(int u=1;u<=n-1;u++){
		for(int d=u+1;d<=n;d++){
			int l=1;
			for(l=1;l<=m-1;l++)
				if(p[u][l]==1&&p[d][l]==1)
					break;
			int r=l+1;
			while(r<=m){
				if(p[u][r]==1&&p[d][r]==1){
					for(int j=l;j<=r;j++)
						g[d][j]=min(g[d][j],(d-u+1)*(r-l+1));
					l=r;
				}
				r++;
			}
		}
		for(int i=n-1;i>=u;i--){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i+1][j]);
			}
		}
	}
	if(trans){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++)
				cout<<(g[j][i]==inf?0:g[j][i])<<' ';
			cout<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<(g[i][j]==inf?0:g[i][j])<<' ';
			cout<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
