#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int single=0;
	vector<bool>val(n+1,0);
	vector<vector<int>>adj(n+1);
	bool fans=1;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		val[x]=1;
	}
	bool q=1;
	for(int i=1;i<=n;i++){
	q&=val[i];}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<bool>>vis(2,vector<bool>(n+1,0));
	for(int i=1;i<=n;i++){
		queue<pii>q;
		if(!(vis[0][i]||vis[1][i])){
			vector<vector<int>>dis(2,vector<int>(n+1,inf));
			vector<int>comp(1,i);
			dis[0][i]=0;		
			q.push({0,i});
			while(!q.empty()){
				int p=q.front().first;
				int u=q.front().second;
				q.pop();
				for(int v:adj[u]){
					if(!vis[p^1][v]){
						dis[p^1][v]=min(dis[p^1][v],dis[p][u]+1);
						comp.push_back(v);
						vis[p^1][v]=1;
						q.push({p^1,v});
					}
				}
			}
			//≈–∂®2∑÷Õº
			if(comp.size()==1){
				single++;//dandian
			}
			else if(dis[0][i]!=inf&&dis[1][i]!=inf){//non-bip
				bool st=0;
				for(int u:comp){
					st|=val[u];
				}
				fans&=st;
			}
			else{
				bool odd=0,even=0;
				for(int u:comp){
					if(dis[0][u]!=inf)
					even|=val[u];
					if(dis[1][u]!=inf)
					odd|=val[u];
				}
				fans&=(odd&even);
			}
		}
	}
	if(single){
		cout<<(q?"Yes":"No");
	}
	else{
		cout<<(fans?"Yes":"No");
	}
}
/*
13 12 13
1 8 4 13 2 3  6 5 7 11 9 10 12
1 2
1 4
2 3
4 3
2 6
3 5
7 8
8 10
11 10
9 8
12 9
9 7

*/
