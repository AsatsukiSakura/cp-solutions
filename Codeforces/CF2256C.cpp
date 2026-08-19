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
	int n,k;
	int ans[2]={0,0};
	string s;
	cin>>n>>k>>s;
	s=' '+s;
	for(int i=1;i<=2*n;i++){
		if(s[i]-'0'){
			ans[i&1 ^(s[i%(2*n)+1]-'0')]++;
		}
	}
	cout<<ans[1]<<' '<<ans[0]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
