#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
const ll mod=1e9+7;
bool inr(int x,int y,int n,int m){
	return x<=n&&x>=1&&y<=m&&y>=1;
}
int main(){
	int dbl=0;
	int dc=0;
	int n,m;
	cin>>n>>m;
	vector<int>dx={0,0,1,-1},dy={1,-1,0,0};
	vector<vector<char>>a(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				for(int k=0;k<=3;k++){
					int x=i+dx[k],y=j+dy[k];
					if(inr(x,y,n,m)&&a[x][y]=='.')a[x][y]='b';
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				for(int k=0;k<=3;k++){
					int x=i+dx[k],y=j+dy[k];
					if(inr(x,y,n,m)&&a[x][y]=='b'){
						queue<pii>q;
						a[x][y]='a';
						q.push({x,y});
						while(!q.empty()){
							int x_=q.front().first,y_=q.front().second;
							q.pop();
							for(int k=0;k<=3;k++){
								int xx=x_+dx[k],yy=y_+dy[k];
								if(inr(xx,yy,n,m)&&a[xx][yy]=='b'){
									a[xx][yy]='a';
									q.push({xx,yy});
								}
							}
						}
					}						
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='b'){
				queue<pii>q;
				a[i][j]='d';dbl++;
				q.push({i,j});
				while(!q.empty()){
					int x_=q.front().first,y_=q.front().second;
					q.pop();
					for(int k=0;k<=3;k++){
						int xx=x_+dx[k],yy=y_+dy[k];
						if(inr(xx,yy,n,m)&&a[xx][yy]=='b'){
							a[xx][yy]='d';dbl++;
							q.push({xx,yy});
						}
					}
				}
				dc++;
			}
		}
	}
	cout<<(dc<=1?"yes":"no");
}
