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
ll qp(ll base,int p){
	ll res=1;
	while(p!=0){
		if(p&1){
			res*=base;
			res%=mod;
		}
		p>>=1;
		base*=base;
		base%=mod;
	}
	return res;
}
ll gp[25],invg[25];
void init() {
	for(int i=1;i<=23;i++){
		gp[i]=qp(3,(mod-1)>>i);
		invg[i]=qp(gp[i],mod-2);
	}
}
void NTT(vector<ll> &x,int dir){
	int n=x.size();
	if(n==1)return;
	int half=n/2;
	vector<ll> even(half),odd(half);
	for(int i=0;i<half;i++){
		even[i]=x[2*i];
		odd[i]=x[2*i+1];
	}
	NTT(even,dir);
	NTT(odd,dir);
	ll omegai=1,omega=gp[__builtin_ctz(n)];
	if(dir==-1)omega=invg[__builtin_ctz(n)];
	for(int i=0;i<x.size()/2;i++){
		x[i]=(even[i]+odd[i]*omegai)%mod;
		x[i+half]=((even[i]-odd[i]*omegai)%mod+mod)%mod;
		omegai*=omega;	
		omegai%=mod;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int n,m;
	cin>>n>>m;
	int x=n+m+1;
	x--;	x|=x>>1;x|=x>>2;
	x|=x>>4;x|=x>>8;x|=x>>16;
	x++;
	vector<ll>a(x,0),b(x,0);
	for(int i=0;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=m;i++)
		cin>>b[i];
	NTT(a,1);
	NTT(b,1);
	vector<ll>c(x,0);
	for(int i=0;i<x;i++){
		c[i]=a[i]*b[i];
		c[i]%=mod;
		c[i]*=qp(x,mod-2);
		c[i]%=mod;
	}
	NTT(c,-1);
	for(int i=0;i<=n+m;i++){
		cout<<(c[i]>2e8?c[i]-mod:c[i])<<' ';
	}
	return 0;
} 
