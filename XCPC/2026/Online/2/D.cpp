#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
#define debug(x) cerr<<#x<<'='<<x<<' '
#define int long long
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r=r*b%mod;
		}
		b=b*b%mod;
		p>>=1;
	}
	return r;
}
struct ux{
	int u;
	int x;
	bool operator==(const ux &uxx)const{
		return uxx.u==u && uxx.x==x;
	};
};
bool isson(int a,int b){
	while(b>a){
		b>>=1;
	}
	if(b<a)return false;
	else return true;
}
signed main(){
	vector<ll>fact(1000001,1),invf(1000001,1);
	for(int i=1;i<=1000000;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	invf[1000000]=qp(fact[1000000],mod-2);
	for(int i=999999;i>=0;i--){
		invf[i]=invf[i+1]*(i+1)%mod;
	}
	int nn,n,q;
	cin>>nn>>q;
	n=1ll<<(nn+1);
	auto A=[&](ll n,ll k)->ll{
		if(n<0)return 0;
		if(k<0 || k>n)return 0;
		else return fact[n]*invf[n-k]%mod;
	};
	vector<ux>b(q+1);
	vector<int>r(n+1,inf);
	for(int i=1;i<=q;i++){
		cin>>b[i].u>>b[i].x;
		r[b[i].u]=b[i].x;
	}
	auto cmp=[](ux ux1,ux ux2){
		if(ux1.x!=ux2.x){
			return ux1.x<ux2.x;
		}else return ux1.u>ux2.u;
	};
	for(int i=1;i<=q;i++){
		int ix=b[i].x;
		for(int j=b[i].u;j>=1;j>>=1){
			if(r[j]<ix){cout<<"0\n";return 0;}
		}
	}
	if(r[1]!=inf && r[1]!=(n+1)/2){cout<<"0";return 0;}
	b.push_back({1,(1<<nn)});
	sort(b.begin()+1,b.end(),cmp);
	b[0]={-inf,-inf};
	b.erase(unique(b.begin(),b.end()),b.end());
	q=b.size()-1;
	int placed=0;
	vector<int>xx(n+1,0);
	vector<int>lft(n+1,0);
	//vector<ll>dp(n+1,1);
	ll ans=1;
	for(int i=1;i<=q;i++){
		lft[b[i].u]=(1<<(nn-__lg(b[i].u)));
	}
	for(int i=1;i<=q;i++){
		ll cur=1;
		int sons=(1<<(nn-__lg(b[i].u)));
		if(xx[b[i].x]==0){
			xx[b[i].x]=b[i].u;
			cur*=A(b[i].x-1-placed,lft[b[i].u]-1);
			cur%=mod;
			cur*=lft[b[i].u];
			cur%=mod;
			placed+=lft[b[i].u];
			//往上推，
			for(int j=b[i].u;j>=1;j>>=1){
				if(j!=b[i].u){
					//dp[j]=dp[j]*cur%mod;
					lft[j]-=lft[b[i].u];
				}
			}
			lft[b[i].u]=0;
		}
		else{
			if(isson(b[i].u,xx[b[i].x])){
				xx[b[i].x]=b[i].u;
				cur*=A(b[i].x-placed,lft[b[i].u]);
				cur%=mod;
				placed+=lft[b[i].u];
				for(int j=b[i].u;j>=1;j>>=1){
					if(j!=b[i].u){
//						dp[j]=dp[j]*cur%mod;
						lft[j]-=lft[b[i].u];
					}
				}
				lft[b[i].u]=0;
			}
			else {cout<<"0";return 0;}
		}
		ans=ans*cur%mod;
	}
	cout<<ans;
}
