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
	int n;
	cin>>n;
	vector<int>a(n+1,0);
	priority_queue<int>pq;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pq.push(x);
	}
	ll l=1,r=n+30;
	while(l<=r){
		auto pqq=pq;
		int m=(l+r)/2;
		for(int i=m-1;i>=0;i--){
			int x=pqq.top();
			pqq.pop();
			if(x<=0)break;
			if(i>=30)pqq.push(-inf);
			else pqq.push(x-(1<<i));
		}
		if(pqq.top()<=0)r=m-1;
		else l=m+1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
