#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=1004535809;
const ll inf=0x3f3f3f3f;
int qp(ll base,int p){
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
ll root[25],iroot[25];
void init(){
	for(int i=1;i<=21;i++){
		root[i]=qp(3,(mod-1)>>i);
		iroot[i]=qp(root[i],mod-2);
	}
}
void NTT(vector<ll> &x,int dir){
	int n=x.size();
	if(n==1)return;
	int half=n/2;
	vector<ll>even(half),odd(half);
	for(int i=0;i<half;i++){
		even[i]=x[2*i];
		odd[i]=x[2*i+1];
	}
	NTT(even,dir);
	NTT(odd,dir);
	ll omegai=1;
	ll omega=(dir==1?root[__builtin_ctz(n)]:iroot[__builtin_ctz(n)]);
	for(int i=0;i<half;i++){
		x[i]=(even[i]+odd[i]*omegai)%mod;
		x[i+half]=((even[i]-odd[i]*omegai)%mod+mod)%mod;
		omegai*=omega;
		omegai%=mod;
	}
}
int rk(string s){
	ll res=0;
	for(char c:s){
		res=(res*10+(c-'0'))%mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int n,k,t;
	string strk;
	cin>>n>>strk>>t;
	k=rk(strk);
	int x=2*n-1;
	x--;	x|=x>>1;x|=x>>2;
	x|=x>>4;x|=x>>8;x|=x>>16;
	x++;
	vector<ll>a(x,0),b(x,0);
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	vector<int>inv(n);
	inv[1]=1;
	for(int i=2;i<=n-1;i++){
		inv[i]=(1ll*(mod-mod/i)*inv[mod%i])%mod;
	}
	if(t==1){
		b[0]=1;
		for(int i=1;i<=n-1;i++){
			b[i]=1ll*b[i-1]*(k-i+1)%mod*inv[i]%mod*(mod-1)%mod;
		}
	}else{
		b[0]=1;
		for(int i=1;i<=n-1;i++){
			b[i]=1ll*b[i-1]*(k+i-1)%mod*inv[i]%mod;
		}
	}
	NTT(a,1);
	NTT(b,1);
	vector<ll>c(x);
	for(int i=0;i<=x-1;i++){
		c[i]=b[i]*a[i];
	}
	NTT(c,-1);
	ll invx=qp(x,mod-2);
	for(int i=0;i<=x-1;i++){
		c[i]*=invx;
		c[i]%=mod;
	}
	for(int i=0;i<=n-1;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
