#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,d;
	edge(int u,int v,int d){
		this->u=u;
		this->v=v;
		this->d=d;
	}
};
vector<int>root;
void init(int n){
	for(int i=1;i<=n;i++)
		root[i]=i;
}
int find(int x){
	if(root[x]==x)
		return x;
	return root[x]=find(root[x]);
}
bool operator<(edge x,edge y) {return x.d<y.d;}
int main(){
	int n,m,x,y,z;
	cin>>n>>m;
	root.resize(n+1);
	init(n);
	vector<edge>edges;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		edges.push_back(edge(x,y,z));
	}
	sort(edges.begin(),edges.end());
	int connected=0,ans=0;
	for(edge e:edges){
		if(find(e.u)!=find(e.v)){
			root[find(e.v)]=find(e.u);
			connected++;
			ans+=e.d;
		}
	}
	if(connected==n-1)cout<<ans;
	else cout<<"orz";
	return 0;
}
