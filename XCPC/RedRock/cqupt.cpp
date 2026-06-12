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
struct edge{
	int to,w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m>>q;
	vector<int>dist(n+2*m+1,inf);
	dist[1]=0;
	vector<vector<edge>>adj(n+2*m+1);
	for(int i=1;i<=m;i++){
		int an,bn;
		cin>>an;
		vector<int>a(an+1);
		for(int j=1;j<=an;j++){
			cin>>a[j];
			adj[a[j]].push_back({n+1,0});
			adj[n+2].push_back({a[j],1});
		}
		cin>>bn;
		vector<int>b(bn+1);
		for(int j=1;j<=bn;j++){
			cin>>b[j];
			adj[b[j]].push_back({n+2,0});
			adj[n+1].push_back({b[j],1});
		}
		++n,n++;
	}
	deque<int>dq;
	dq.push_back(1);
	while(!dq.empty()){
		int u=dq.front();
		dq.pop_front();
		for(edge e:adj[u]){
			if(dist[e.to]==inf){
				dist[e.to]=dist[u]+e.w;
				if(e.w)dq.push_back(e.to);
				else dq.push_front(e.to);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		cout<<(dist[x]==inf?-1:dist[x])<<'\n';
	}
	return 0;
}
/*
10 4 10
1 1
1 2
3 2 3 4
2 5 6
2 3 5
1 7
1 7
2 8 9
1
2
3
4
5
6
7
8
9
10
9 2 9
5 1 2 3 4 5
1 6
3 5 8 9
1 7
1 2 3 4 5 6 7 8 9
*/
