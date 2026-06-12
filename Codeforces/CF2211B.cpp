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
	int x,y;
	cin>>x>>y;
	int d=abs(x-y);
	int ans=1;
	for(int i=2;i<=d;i++)
		ans+=(d%i==0);
	cout<<ans<<'\n';
	for(int i=1;i<=x;i++)cout<<"1 ";
	for(int i=1;i<=y;i++)cout<<"-1 ";
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
