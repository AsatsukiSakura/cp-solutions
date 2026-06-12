#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n,t,u,v,q;
	cin>>n>>m;
	vector<int>sum(n+1,0),in(n+1,0),w(n+1,0);
	int total=0,totaln=0;
	for(int i=1;i<=n;i++){
		w[i]=i*i*i+114*i*i-514*i+1919810;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		sum[v]+=w[u];in[v]+=w[u];
	}
	for(int i=1;i<=n;i++){
		total+=sum[i];totaln+=w[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>t;
		if(t==1){
			cin>>u>>v;
			in[v]-=w[u];total-=w[u];}
		if(t==2){
			cin>>u;
			total-=in[u];in[u]=0;}
		if(t==3){
			cin>>u>>v;
			in[v]+=w[u];total+=w[u];}
		if(t==4){
			cin>>u;
			total+=(sum[u]-in[u]);in[u]=sum[u];}
		cout<<(total==totaln?"YES":"NO")<<'\n';
	}
	return 0;
}
