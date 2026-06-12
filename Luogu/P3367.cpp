#include<bits/stdc++.h>
using namespace std;
vector<int>root;
int n,m,x,y,z;
void init(){
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
}
int find(int x){
	if(root[x]==x)
		return x;
	return root[x]=find(root[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	root.resize(n+1);
	init();
	for(int i=1;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1)
			root[find(y)]=find(x);
		if(z==2)
			cout<<((find(x)==find(y))?'Y':'N')<<endl;
	}
}
