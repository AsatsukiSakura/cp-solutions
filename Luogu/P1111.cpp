#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int root[1005];
int n,m;
struct edge{
	int vertex,time;
};
vector<vector<edge> >adj(1005);
int find(int x){
	if(root[x]==x)
		return x;
	return root[x]=find(root[x]);
}
bool check(int k){
	for(int i=1;i<=n;i++)	
		root[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=0;j<adj[i].size();j++)
			if(adj[i][j].time<=k)
				if(find(adj[i][j].vertex)!=find(i))
					root[find(adj[i][j].vertex)]=find(i);
	for(int i=1;i<=n;i++)
		if(find(i)!=find(1))
			return false;
	return true;
}
int binaryanswer(int l,int h){
	int mid=(l+h)/2;
	if(l>h)	return l;
	if(check(mid))	return binaryanswer(l,mid-1);
	else return binaryanswer(mid+1,h);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		edge e;
		e.time=t;e.vertex=v;
		adj[u].push_back(e);
		e.vertex=u;
		adj[v].push_back(e);
	}
	int ans=binaryanswer(0,inf);
	if(ans>=inf)	cout<<-1;
	else cout<<ans; 
	return 0;
} 
