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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	ll r=0,rc=0,rcx=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='r')r=i;
		if(s[i]=='c')rc=r;
		if(s[i]=='x')rcx=rc;
		ans+=rcx;
	}
	cout<<ans;
	return 0;
}
