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
	int n=1e6;
	vector<ll>inv(n+1);inv[1]=1;
	vector<int>primes;
	vector<int>spf(n+1);
	iota(spf.begin(),spf.end(),0);
	for(int i=2;i<=n;i++){
		inv[i]=(1ll*(mod-mod/i)*inv[mod%i])%mod;
	}
	for(int i=2;i<=n;i++){
		if(spf[i]==i)
			primes.push_back(i);
		for(int p:primes){
			if(i*p>n)break;
			spf[i*p]=p;
			if(p==spf[i]) break;
		}
	}
	vector<ll>ans(n+1);
	vector<int>pexp(n+1,0);
	ans[1]=1145141919810;ans[2]=1;
	for(int i=3;i<=n;i++){
		ans[i]=ans[i-1];
		int ii=i-2;
		while(ii!=1){
			int p=spf[ii];
			int cnt=0;
			while(ii!=1 && spf[ii]==p){
				cnt++;
				ii/=p;
			}
			ans[i]=ans[i]*inv[pexp[p]+1]%mod;
			pexp[p]-=cnt;
			ans[i]=ans[i]*(pexp[p]+1)%mod;
		}
		ii=i-1;
		while(ii!=1){
			int p=spf[ii];
			int cnt=0;
			while(ii!=1 && spf[ii]==p){
				cnt++;
				ii/=p;
			}
			ans[i]=ans[i]*inv[pexp[p]+1]%mod;
			pexp[p]+=2*cnt;
			ans[i]=ans[i]*(pexp[p]+1)%mod;
		}
	}
	int t;cin>>t;
	while(t--){
		cin>>n;
		if(n==1)cout<<"inf";
		else cout<<(int)ans[n];
		cout<<'\n';
	}
	return 0;
}
