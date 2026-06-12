#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
struct DSU{
	vector<int>root;
	int n;
	DSU(int n){
		this->n=n;
		root.resize(n+1);
		iota(root.begin(),root.end(),0);
	}
	int find(int x){
		if(root[x]==x)
			return x;
		else return root[x]=find(root[x]);
	}
	void merge(int x,int y){
		root[find(y)]=find(x);
	}
};
struct Edge{
	int u,v;
	ll w;
	Edge(int uu,int vv,ll ww){
		u=uu;v=vv;w=ww;
	}
	bool operator<(const Edge &other)const{
		return this->w<other.w;
	}
};
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n,k;
	cin>>n>>m>>k;
	vector<Edge>edges;
	vector<int>cost(k+1);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		edges.push_back(Edge(u,v,w));
	}
	DSU dsu(n+k);
	vector<Edge>MST;
	sort(edges.begin(),edges.end());
	for(Edge e:edges){
		if(dsu.find(e.u)!=dsu.find(e.v)){
			dsu.merge(e.u,e.v);
			MST.push_back(e);
		}
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			ll w;cin>>w;
			MST.push_back(Edge(n+i,j,w));
		}
	}
	sort(MST.begin(),MST.end());
	vector<bool>choose;
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		iota(dsu.root.begin(),dsu.root.end(),0);
		ll mincost=0;
		choose.assign(k+1,false);
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				choose[j]=true;
				mincost+=cost[j];
			}
		}
		for(Edge e:MST){
			if(dsu.find(e.u)!=dsu.find(e.v))
				if((e.u<=n || choose[e.u-n])&&(e.v<=n || choose[e.v-n])){
					dsu.merge(e.u,e.v);
					mincost+=e.w;
				}
		}
		ans=min(mincost,ans);
	}
	cout<<ans;
	return 0;
}
