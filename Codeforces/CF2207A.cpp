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
	for(int i=1;i+2<=n;){
		if(s[i]=='1'&&s[i+2]=='1'){
			s[i+1]='1';
			i+=2;
		}
		else i++;
	}
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)c1+=(s[i]=='1');
	for(int i=1;i+2<=n;){
		if(s[i]=='1'&&s[i+2]=='1'){
			s[i+1]='0';
			i+=2;
		}
		else i++;
	}
	for(int i=1;i<=n;i++)c2+=(s[i]=='1');
	cout<<c2<<' '<<c1<<'\n';
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
