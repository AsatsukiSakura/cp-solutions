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
	string ss=s;
	sort(ss.begin()+1,ss.end());
	if(ss==s){cout<<"0\n";return;}
	int c0=0,f1=inf;
	for(int i=1;i<=n;i++){
		c0+=(s[i]=='0');
		if(s[i]=='1')f1=min(f1,i);
	}
	if(f1==1){cout<<c0<<'\n';return;}
	int c00=0,ans=inf;
	for(int i=1;i<=n;i++){
		c00+=(s[i]=='0');
		if(i+1>=f1){
			ans=min(i-c00+c0-c00,ans);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
