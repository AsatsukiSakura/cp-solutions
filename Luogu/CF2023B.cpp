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
struct Edge{
	ll w;
	int to;
	Edge(int x,ll y){to=x;w=y;}
	bool operator>(const Edge &other)const
		{return this->w>other.w;}
};
void solve(){
	int n;
	cin>>n;
	vector<vector<Edge>>adj(n+1);
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		if(i!=1)adj[i].push_back({i-1,0});
		if(b[i]>i)adj[i].push_back({b[i],a[i]});
	}
	priority_queue<Edge,vector<Edge>,greater<Edge>>pq;
	vector<ll>dist(n+1,inf<<30);
	dist[1]=0;
	vector<bool>finale(n+1,0);
	pq.push({1,0});
	while(!pq.empty()){
		Edge e=pq.top();
		pq.pop();
		if(finale[e.to])continue;
		finale[e.to]=1;
		for(Edge cur:adj[e.to]){
			if(finale[cur.to])continue;
			dist[cur.to]=min(dist[e.to]+cur.w,dist[cur.to]);
			pq.push({cur.to,dist[cur.to]});
		}
	}
	vector<ll>sum(n+1,0);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		sum[i]-=dist[i];
	cout<<*max_element(sum.begin()+1,sum.end())<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
