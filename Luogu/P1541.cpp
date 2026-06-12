#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int dp[50][50][50][50];
	memset(dp,0,sizeof(dp));
	int n,m,b;
	cin>>n>>m;
	vector<int>a(n+1),cnt(5,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b;
		cnt[b]++;
	}
	dp[0][0][0][0]=a[1];
	for(int q=0;q<=cnt[1];q++){
		for(int w=0;w<=cnt[2];w++){
			for(int e=0;e<=cnt[3];e++){
				for(int r=0;r<=cnt[4];r++){
					int cur=1+q+2*w+3*e+4*r;
					if(cur<=n){
						if(q!=0)	dp[q][w][e][r]=max(dp[q][w][e][r],dp[q-1][w][e][r]+a[cur]);
						if(w!=0)	dp[q][w][e][r]=max(dp[q][w][e][r],dp[q][w-1][e][r]+a[cur]);
						if(e!=0)	dp[q][w][e][r]=max(dp[q][w][e][r],dp[q][w][e-1][r]+a[cur]);
						if(r!=0)	dp[q][w][e][r]=max(dp[q][w][e][r],dp[q][w][e][r-1]+a[cur]);
					}
				}
			}
		}		
	}
	cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	return 0;
}
