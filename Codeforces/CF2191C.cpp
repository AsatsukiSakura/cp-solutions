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
	int c0=0;
	for(int i=1;i<=n;i++)
		c0+=(s[i]=='0');
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if((i<=c0&&s[i]=='1')||(i>=c0+1&&s[i]=='0')){
			ans.push_back(i);
		}
	}
	if(ans.size()){
		cout<<"Alice\n"<<ans.size()<<'\n';
		for(int i:ans)cout<<i<<' ';
		cout<<'\n';
	}
	else cout<<"Bob\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
