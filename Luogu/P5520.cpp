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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int type,n,m,p;
	cin>>type>>n>>m>>p;
	ll ans=1;
	for(int i=n-2*m+2;i<=n-m+1;i++){
		ans*=i;
		ans%=p;
	}
	cout<<ans;
	return 0;
}
