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
	int x,y,m;
	cin>>x>>y>>m;
	int ans=x+y;
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=m;i++){
		if(x+y==0)
			break;
		if(s[i]=='+'){
			if(y)y++;
			else x--,y++;
		}else{
			if(y>1)y--,x++;
			else if(x)x--;
			else y--,x++;
		}
		ans=max(ans,x+y);
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
