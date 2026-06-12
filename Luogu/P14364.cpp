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
ll fact(int n){
	if(n==1)return 1;
	else return 1ll*n*fact(n-1)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;s=' '+s;
	vector<int>c(n+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(0){
		int total1=0;
		for(int i=1;i<=n;i++){
			total1+=(s[i]=='1');
		}
		if(total1<m){
			cout<<0;return 0;
		}
		if(total1==n){
			cout<<fact(n);
		}
	}
	else
	{
		vector<vector<ll>>dp(1<<n,vector<ll>(n+1,0));
		dp[0][0]=1;
		for(int mask=0;mask<=(1<<n)-2;mask++){
			int day=__builtin_popcount(mask);
			for(int i=0;i<=n;i++){
				if(dp[mask][i]==0)continue;
				int reject=day-i;
				for(int j=1;j<=n;j++){
					if(mask&(1<<(j-1)))continue;
					if(c[j]>reject && s[day+1]=='1' && i<n)
						dp[mask|(1<<(j-1))][i+1]=(dp[mask|(1<<(j-1))][i+1]+dp[mask][i])%mod;
					else
						dp[mask|(1<<(j-1))][i]=(dp[mask|(1<<(j-1))][i]+dp[mask][i])%mod;
				}
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++){
			ans=(ans+dp[(1<<n)-1][i])%mod;
		}
		cout<<ans;
	}
	return 0;
}
/*
8 6
11110011
1 2 3 4 0 1 2 3

12 8
111110101011
1 2 3 4 0 1 3 4 0 2 5 6

18 8
111001101111110101
1 2 3 4 0 2 3 4 1 2 2 1 3 4 0 2 5 6

22 10
1110011011111101011111
1 2 3 4 0 2 3 4 1 2 2 1 3 4 0 2 5 6 2 3 3 4
*/
