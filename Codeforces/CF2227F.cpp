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
	vector<int>a(n+1);
	vector<ll>cnt(n+2,0);
	ll itp=0,tdis=0,mx;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[1]++;
		cnt[a[i]+1]--;
		itp+=(ll)a[i]*i;
	}
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
	}
	for(int i=1;i<=n;i++){
		tdis+=(2ll*n-cnt[i]+1)*cnt[i]/2;
	}
	tdis-=itp;
	mx=tdis;
	for(int i=1;i<=n;i++){
		if(a[i])mx=max(mx,tdis+i-(n-cnt[a[i]]+1));
	}
	cout<<mx<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
