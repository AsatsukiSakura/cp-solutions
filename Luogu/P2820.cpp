#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
struct edge{
	int u,v,d;
	edge(int u,int v,int d){
		this->u=u;
		this->v=v;
		this->d=d;
	}
};
vector<int>root;
vector<edge>edges;
void init(int n){
	root.resize(n+1);
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
}
int find(int x){
	if(x==root[x])
		return x;
	return root[x]=find(root[x]);
}
bool operator<(edge x,edge y){
	return x.d<y.d;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n,u,v,w,total=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		total+=w;
		edges.push_back(edge(u,v,w));
	}
	init(n);
	sort(edges.begin(),edges.end());
	int ans=0;
	for(edge e:edges){
		if(find(e.u)!=find(e.v)){
			root[find(e.u)]=find(e.v);
			ans+=e.d;
		}
	}
	cout<<total-ans;
	return 0;
}
