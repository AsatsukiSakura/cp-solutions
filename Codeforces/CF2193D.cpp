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
	vector<int>a(n+1),b(n+1);
	/*
	枚举通关层数k
	计算需要剑的数量s
	考虑第s把剑就是x
	*/
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end(),greater<int>());
	vector<ll>s(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s[i]=s[i-1]+b[i];
	}
	ll ans=0;
	for(int k=1;k<=n;k++){
		if(s[k]>n)break;
		//x=a[s[k]]
		ans=max(ans,1ll*k*a[s[k]]);
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
