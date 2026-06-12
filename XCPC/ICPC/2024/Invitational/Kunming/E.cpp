#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int n;
	ll k;
	cin>>n>>k;
	vector<ll>a(n+1),b(n+1);
	/*??
	??gcd?????? ????
	???????????????????
	????? ??????
	??st???*/
	vector<int>pdx,sdx;
	pdx.push_back(1);
	sdx.push_back(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+k;
	}
	vector<ll>pg(n+1),sg(n+1);
	pg[1]=a[1];
	for(int i=2;i<=n;i++){
		pg[i]=gcd(a[i],pg[i-1]);
		if(pg[i]!=pg[i-1])pdx.push_back(i);
	}
	ll ans=pg[n];
	sg[n]=a[n];
	for(int i=n-1;i>=1;i--){
		sg[i]=gcd(a[i],sg[i+1]);
		if(sg[i]!=sg[i+1])sdx.push_back(i);
	}
	sort(sdx.begin(),sdx.end());
	vector<vector<ll>>st(log2(n)+1,vector<ll>(n+1));
	for(int i=1;i<=n;i++){
		st[0][i]=b[i];
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
//	debug(pg[1]),debug(sg[1]),debug(st[1][2]);
	for(int i:pdx){
		for(int j:sdx){
			if(j<i)continue;
			int p=log2(j-i+1);
			ll g=gcd(st[p][i],st[p][j-(1<<p)+1]);
			if(i!=1)g=gcd(g,pg[i-1]);
			if(j!=n)g=gcd(g,sg[j+1]);
			ans=max(g,ans);
	
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
}
/*
1
6 2
5 3 13 8 10 555
*/
