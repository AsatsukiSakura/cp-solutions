#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,a,b;
	cin>>n>>a>>b;
	vector<int>dis(n+1,inf),k(n+1);
	queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	q.push(a);dis[a]=0;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top+k[top]<=n &&dis[top+k[top]]==inf){
			q.push(top+k[top]);dis[top+k[top]]=dis[top]+1;
		}
		if(top-k[top]>=1 &&dis[top-k[top]]==inf){
			q.push(top-k[top]);dis[top-k[top]]=dis[top]+1;
		}
	}
	cout<<(dis[b]==inf?-1:dis[b]);
	return 0;
}
