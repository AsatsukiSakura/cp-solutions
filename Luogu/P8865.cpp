//NOIP2022种花
#include<bits/stdc++.h>
using ll=long long;
const ll mod=998244353;
using namespace std;
void solve(){
	ll n,m,c,f,cntc;
	ll plant[1005][1005];
	ll countr[1005][1005],countd[1005][1005],countu[1005][1005];
	string s;
	cin>>n>>m>>c>>f;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<=m-1;j++)
			plant[i][j+1]=s[j]-'0';
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(plant[i][j]==1)	countr[i][j]=0;
			else if(j==m)	countr[i][j]=1;
			else countr[i][j]=countr[i][j+1]+1;
			countr[i][j]%=mod;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(plant[i][j]==1)	countd[i][j]=0;
			else if(i==n)	countd[i][j]=1;
			else countd[i][j]=countd[i+1][j]+1;
			countd[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(plant[i][j]==1)	countu[i][j]=0;
			else if(i==1)	countu[i][j]=countr[i][j]-1;
			else countu[i][j]=countu[i-1][j]+countr[i][j]-1;
			countu[i][j]%=mod;
		}
	}
	ll ansf=0,ansc=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			if(plant[i-1][j]==0 && plant[i][j]==0){
				cntc=((countr[i][j+1]%mod)*countu[i-2][j])%mod;
				ansc+=cntc;
				ansc%=mod;
				if(i!=n)
					ansf+=(ansc*(countd[i+1][j]%mod))%mod;
				ansf%=mod;
			}
		}
	}
	cout<<(c*ansc%mod)<<' '<<(f*ansf%mod)<<endl;
}
int main(){
	int t,id;cin>>t>>id;
	while(t--)	solve();
	return 0;
}
