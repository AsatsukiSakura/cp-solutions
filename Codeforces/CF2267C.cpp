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
	int n,x;
	cin>>n>>x;
	vector<int>pr;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int tmp=x;
	for(int i=2;i*i<=tmp;i++){
		if(tmp%i==0)pr.push_back(i);
		while(tmp%i==0)tmp/=i;
	}
	if(tmp!=1)pr.push_back(tmp);
	ll ans=0;
	for(int p:pr){
		ll sum=0;
		for(int i=1;i<=n;i++){
		if(a[i]%p==0)	sum+=a[i];
		}
		ans=max(ans,sum);
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
