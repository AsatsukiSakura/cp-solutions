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
	string s;
	cin>>s;
	s=' '+s;
	if(n&1){
		if(s[1]=='b'){cout<<"NO\n";return;}
		for(int i=2;i<=n;i+=2){
			if(s[i]==s[i+1]&&s[i]!='?'){
				cout<<"NO\n";return;
			}
		}
		cout<<"YES\n";return;
	}
	else{
		for(int i=1;i<=n;i+=2){
			if(s[i]==s[i+1]&&s[i]!='?'){
				cout<<"NO\n";return;
			}
		}
		cout<<"YES\n";return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
