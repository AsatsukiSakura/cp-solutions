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
inline void add(int &a,int b){
	a=(a+b>=mod?a+b-mod:a+b);
}
int main(){
	int n,m;
	string s;
	cin>>n>>m>>s;
	vector<int>c(n+1),a(n+1,0),pre(n+1,0);
	vector<ll>fact(n+1,1);
	vector<vector<ll>>comb(n+1,vector<ll>(n+1,0));
	vector<vector<ll>>perm(n+1,vector<ll>(n+1,0));
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[c[i]]++;
	}
	pre[0]=a[0];
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	fact[0]=perm[0][0]=comb[0][0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=1ll*i*fact[i-1]%mod;
		perm[i][0]=comb[i][0]=1;//操你妈了个逼
		for(int j=1;j<=i;j++){
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
			perm[i][j]=(1ll*comb[i][j]*fact[j])%mod;
		}
	}
	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
	dp[0][0][0]=1;
	// 第i天 拒绝了j人 i个人其中有k个不耐烦的
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=min(pre[j],i);k++){//延迟计算对排列数的贡献
				//也就是说 到了j+1的时候在定死这些耐心不足的人 其余的人属于“自由流动”状态
				if(s[i]=='1'){
					if(n-pre[j]>i-k){
						add(dp[i+1][j][k],dp[i][j][k]);
					}
					for(int t=0;t<=min(a[j+1],i-k);t++){
						add(dp[i+1][j+1][k+t+1],
						1ll*comb[a[j+1]][t]*perm[i-k][t]%mod*(pre[j]-k)%mod*dp[i][j][k]%mod);
					}
				}
				else{
					for(int t=0;t<=min(a[j+1],i-k);t++){
						if(n-pre[j+1]>i-k-t){
							add(dp[i+1][j+1][k+t],
							1ll*comb[a[j+1]][t]*perm[i-k][t]%mod*dp[i][j][k]%mod);
						}
						add(dp[i+1][j+1][k+t+1],
						1ll*comb[a[j+1]][t]*perm[i-k][t]%mod*(pre[j+1]-k-t)%mod*dp[i][j][k]%mod);
						//他妈的 我是铸币
						//忘记初始化perm[i][0]了 导致要乘1的地方乘的全是0
						//调了我一个小时啊我操了
					}
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n-m;j++){
		add(ans,1ll*dp[n][j][pre[j]]*fact[n-pre[j]]%mod);
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 1
11
1 0

3 2
110
1 1 0 dp[1][0][0]->dp[2][0][0]->dp[3][1][3]
*/ 
