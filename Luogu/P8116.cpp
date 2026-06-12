#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	int b,k;
	cin>>b>>k;
	k--;
	int bb=b;
	vector<int>cnt(1e5+1,0);
	for(int i=2;i*i<=bb;i++){
		while(bb%i==0){
			cnt[i]++;
			bb/=i;
		}
	}
	cnt[bb]++;
	ll ans=1;
	for(int i=2;i<=b;i++){
		ans*=(1ll+1ll*k*cnt[i]);
		ans%=mod;
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
