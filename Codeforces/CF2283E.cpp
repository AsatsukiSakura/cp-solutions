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
vector<ll>bell(5001,0);
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	vector<int>ps;
	int sgl=0;
	int tmp=0,zc=0,oc=0;
	int i=1;
	while(i<=n){
		int j=i;
		while(j+1<=n&&s[j+1]!=s[j])j++;
		int len=j-i+1;
		if(len>=2){sgl+=len;
		ps.push_back(len);}
		else{
			if(s[i]=='0')zc++;
			else oc++;
		}
		i=j+1;
	}
	vector<ll>pt(n+1,0);
	if(n>=2)pt[2]=1;
	if(n>=3)pt[3]=1;
	for(int i=4;i<=n;i++)pt[i]=(pt[i-2]+pt[i-3])%mod;
	ll ans=1;
	ans=ans*bell[zc]%mod;
	ans=ans*bell[oc]%mod;
	for(int len:ps)ans=ans*pt[len]%mod;
	cout<<n+sgl<<' '<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>>C(5001,vector<ll>(5001,0));
	for(int i=0;i<=5000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	bell[0]=1;
	for(int i=1;i<=5000;i++){
		for(int j=0;j<=i-1;j++){
			bell[i]=(bell[i]+C[i-1][j]*bell[j]%mod)%mod;
		}
	}
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
