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
void solve(){
	int n,m;
	cin>>n>>m;
	vector mt(n,vector<int>(n));
	while(m--){
		int o,i,j;
		cin>>o>>i>>j;
		i--;j--;
		mt[i][j]=mt[j][i]=o;
	}
	vector<int>pos,neg;
	for(int i=0;i<n;i++){
		if(mt[i][i]==1)pos.push_back(i);
		else neg.push_back(i);
	}
	vector<vector<int>>adj(n);
	for(int i:pos)for(int j:neg){
		if(mt[i][j]==1)adj[j].push_back(i);
		else adj[i].push_back(j);
	}
	vector<int>in(n);
	for(int u=0;u<n;u++)
		for(int v:adj[u])in[v]++;
	queue<int>q;
	for(int u=0;u<n;u++)
		if(!in[u])q.push(u);
	vector<int>val(n);
	int ord=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		ord++;
		if(mt[u][u]==1)val[u]=ord;
		else val[u]=-ord;
		for(int v:adj[u])
			if(!--in[v])q.push(v);
	}
	if(ord<n){cout<<"NO\n";return;}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			if(mt[i][j]==1&&val[i]+val[j]<0){cout<<"NO\n";return;}
			if(mt[i][j]==2&&val[i]+val[j]>=0){cout<<"NO\n";return;}
		}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
		cout<<val[i]<<(i+1==n?'\n':' ');
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
