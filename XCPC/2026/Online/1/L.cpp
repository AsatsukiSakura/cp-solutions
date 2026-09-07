#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const pll mod={985661441,998244353};
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<string>s(n+1);
	for(int i=1;i<=n;i++)cin>>s[i];
	vector<ll>ans(n+1,0);
	map<pll,int>cnt;
	vector<ll>f(n+1,0);
	const ll base=131;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+i;
		pll h={0,0};
		for(int j=0;j<s[i].size();j++){
			h.first=(base*h.first+s[i][j])%mod.first;
			h.second=(base*h.second+s[i][j])%mod.second;
			cnt[h]++;
			if(j+1>ans[cnt[h]]){
				f[i]-=ans[cnt[h]]^cnt[h];
				ans[cnt[h]]=j+1;
				f[i]+=ans[cnt[h]]^cnt[h];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<f[i]<<'\n';
	}
	return 0;
}
