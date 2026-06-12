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
	int c[5],n;
	cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
	ll dp[100001]={0};
	dp[0]=1;
	for(int j=1;j<=4;j++){
		for(int k=c[j];k<=100000;k++){
			dp[k]+=dp[k-c[j]];
		}
	}
	for(int i=1;i<=n;i++){
		int d[5],s;
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;		
		ll ans=0;
		for(int j=0;j<=15;j++){
			int cnt=0;
			ll s_=s;
			for(int k=1;k<=4;k++){
				if(j&(1<<(k-1))){
					cnt++;
					s_-=1ll*c[k]*(d[k]+1);
				}
			}
			if(s_>=0)ans+=(cnt&1?-1:1)*dp[s_];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
