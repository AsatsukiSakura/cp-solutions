#include<bits/stdc++.h>
using namespace std;
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
void solve(int n,int m){
	int u,v;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		root[find(v)]=find(u);
	}
	int cnt=-1;
	for(int i=1;i<=n;i++){
		if(find(i)==i)
			cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	int n,m;
	root.resize(1001);
	while(1){
		cin>>n;
		if(n==0)break;
		cin>>m;
		solve(n,m);
	}
	return 0;
}
