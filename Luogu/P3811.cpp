#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,p;	
	cin>>n>>p;
	vector<ll>inv(n+1,0);
	cout<<(inv[1]=1)<<'\n';
	for(int i=2;i<=n;i++){
		inv[i]=(1ll*(p-p/i)*inv[p%i])%p;
		cout<<inv[i]<<'\n';
	}
	return 0;
}
