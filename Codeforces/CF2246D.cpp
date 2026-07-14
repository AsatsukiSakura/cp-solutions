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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>p2(n+1);
	for(int i=1;i<=n;i++){
		p2[i]=a[i];
		while((p2[i]&-p2[i])!=p2[i]){
			p2[i]+=(p2[i]&-p2[i]);
		}
		int cost=__builtin_popcount(a[i]);
		vector<int>ans(2);
		for(int r=1;r<=2;r++){
			
			for(int j=a[i];j<=max(a[i]+20,p2[i]-(r&1));j++){
				cost=min(cost,j-a[i]+__builtin_popcount(j));
			}
			ans[r&1]+=cost;
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
