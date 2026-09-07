#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+100);
	vector<int>in(n+100,0);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		vector<int>a(r-l+100);
		for(int j=1;j<=r-l+1;j++){
			cin>>a[j];
			if(j!=1){adj[a[j-1]].push_back(a[j]);
				in[a[j]]++;}
		}
	}
	//for(int i=1;i<=n;i++)cout<<"d"<<in[i]<<"e"<<adj[i].size()<<endl;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=1;i<=n;i++)if(in[i]==0){
		pq.push(i);
	}
	vector<int>p(n+1,0);
	int cnt=0;
	while(!pq.empty()){
		cnt++;
		int u=pq.top();	
		//cout<<"u"<<u;
		pq.pop();
		p[u]=cnt;
		for(int v:adj[u]){
			in[v]--;
			if(in[v]==0)pq.push(v);
		}
	}
	if(cnt<n)cout<<"-1\n";
	else {
		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)solve();
}
