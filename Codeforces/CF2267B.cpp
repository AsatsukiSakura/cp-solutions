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
	vector<int>c(101,0);
	int mv=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		c[x]++;
		mv=max(mv,x);
	}
	vector<int>ans(n+1,0);
	int idx=0;
	while(1){
		int cur=c[mv];
		for(int i=mv;i>=1;i--){
			for(int j=1;j<=min(cur,c[i]);j++){
				++idx;
				ans[idx]=i;
			}
			c[i]-=min(cur,c[i]);
		}
		while(c[mv]==0&&mv!=0)mv--;
		if(mv==0)break;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
