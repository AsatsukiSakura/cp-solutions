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
	int k;
	string n;
	cin>>k>>n;
	n=' '+n;
	int ans=0;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=k;i>=1;i--){
		if((k-i)&1){
			pq.push(n[i]-'0');
			ans+=10*(n[i]-'0');
		}else{
			ans+=n[i]-'0';
			if(!pq.empty()&&pq.top()<=n[i]-'0'){
				ans-=pq.top()*9;
				ans+=(n[i]-'0')*9;
				pq.pop();
				pq.push(n[i]-'0');
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
