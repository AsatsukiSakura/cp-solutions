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
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	int cnt=0;
	if(s[1]=='u')s[1]='s',cnt++;
	if(s[n]=='u')s[n]='s',cnt++;
	int len=0;
	for(int i=2;i<=n;i++){
		if(s[i]=='u')len++;
		else{cnt+=len/2;len=0;}	
	}
	cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
