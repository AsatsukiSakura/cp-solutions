#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans=0,n,i,a,b;
	priority_queue<int,vector<int>,greater<int>> pq;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		pq.push(a);
	}
	while(pq.size()>=2){
		a=pq.top();pq.pop();
		b=pq.top();pq.pop();
		ans+=(a+b);pq.push(a+b);
	}
	cout<<ans;
	return 0;
}
