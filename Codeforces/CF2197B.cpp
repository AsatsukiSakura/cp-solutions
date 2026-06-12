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
	vector<int>a(n+1),p(n+1);
	vector<int>amin(n+1,inf),amax(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amin[a[i]]=min(amin[a[i]],i);
		amax[a[i]]=max(amax[a[i]],i);
	}
	int idx=0;
//	debug(amin[2]);debug(amin[4]);
	for(int i=1;i<=n;i++){
		if(idx>amin[p[i]]){
		//	debug(p[i]);
			cout<<"NO\n";
			return;
		}
		idx=max(idx,amax[p[i]]);
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
