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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=2e5;
	vector<int>d(n+1,0);
	for(int i=1;i<=n;i++){
		int tmp=i;
		while(tmp)tmp/=3,d[i]++;
	}
	vector<ll>s(n+1);
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i];
	}
	int t;cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<d[l]+s[r]-s[l-1]<<'\n';
	}
	return 0;
}
