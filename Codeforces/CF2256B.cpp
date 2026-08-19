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
	string s;
	cin>>n>>s;
	s=' '+s;
	set<int>o,e;
	for(int i=1;i<=n;i+=2)
		if(s[i]!='?')	
			o.insert(((i+1)/2)&1 ^(s[i]-'0'));
	for(int i=2;i<=n;i+=2)
		if(s[i]!='?')	
			e.insert((i/2)&1 ^(s[i]-'0'));
	cout<<(2-o.size())*(2-e.size())<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
