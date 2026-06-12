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
	if(s.find(")(")==string::npos){
		cout<<"-1\n";return;
	}
	for(int i=s.find(")(")+2;i<=n;i++){
		if(s[i]=='('){
			cout<<n-2<<'\n';
			return;
		}
	}
	cout<<"-1\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
