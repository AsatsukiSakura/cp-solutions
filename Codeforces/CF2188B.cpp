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
	cin>>n>>s;s=' '+s;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')cnt++;
		else{
			ans++;
			if(cnt==i-1)
				ans+=(cnt+1)/3;
			else ans+=cnt/3;
			cnt=0;
		}
	}
	if(cnt==n){
		ans=(cnt+2)/3;
	}
	else ans+=(cnt+1)/3;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
