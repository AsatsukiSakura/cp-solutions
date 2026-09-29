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
	char c;
	cin>>n>>c;
	string s;
	cin>>s;
	s=' '+s;
	int a=0;
	for(int i=1,j=n;i<=j;i++,j--){
		if(s[i]==s[j]) continue;
		else if(s[i]==c||c==s[j]) a++;
		else a++,a++;
	}
	cout<<a<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
