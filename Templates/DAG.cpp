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
ll g=3,gp[25],invg[25],inv[1<<20],fact[1<<17],invfact[1<<17];
ll qp(ll b,ll p){
	ll r=1;
	while(p){
		if(p&1){
			r*=b;
			r%=mod;
		}
		b*=b;
		b%=mod;
		p>>=1;
	}
	return r;
}
void init(){
	inv[1]=1;
	for(int i=2;i<=1000000;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	fact[0]=1;
	for(int i=1;i<=130000;i++){
		fact[i]=i*fact[i-1]%mod;
	}
	invfact[130000]=qp(fact[130000],mod-2);
	for(int i=129999;i>=0;i--){
		invfact[i]=(i+1)*invfact[i+1]%mod;
	}
	for(int i=0;i<=20;i++){
		gp[i]=qp(g,(mod-1)>>i);
		invg[i]=qp(gp[i],mod-2);
	}
}
void NTT(vector<ll> &a,int dir){
	int n=a.size();
	if(n==1)return;
	vector<ll>odd(n/2),even(n/2);
	for(int i=0;i<n/2;i++){
		even[i]=a[2*i];
		odd[i]=a[2*i+1];
	}
	NTT(odd,dir);
	NTT(even,dir);
	ll w=1,wn=dir==1?gp[__builtin_ctz(n)]:invg[__builtin_ctz(n)];
	for(int i=0;i<n/2;i++){
		ll t=odd[i]*w%mod;
		a[i]=even[i]+t>=mod?even[i]+t-mod:even[i]+t;
		a[i+n/2]=even[i]-t<0?even[i]-t+mod:even[i]-t;
		w=w*wn%mod;
	}
	return;
}
vector<ll> PolyInv(vector<ll> &a,int n){
	if(a.size()<n)a.resize(n);
	if(n==1){
		return {qp(a[0],mod-2)};
	}
	vector<ll>b=PolyInv(a,n>>1);
	int t=1;
	while(t<(n<<1))	t<<=1;
	vector<ll>ta(t,0),tb(t,0);
	for(int i=0;i<n;i++)
		ta[i]=i<(int)a.size()?a[i]:0;
	for(int i=0;i<b.size();i++)
		tb[i]=b[i];
	NTT(ta,1);
	NTT(tb,1);
	for(int i=0;i<t;i++)
		tb[i]=tb[i]*(2ll-ta[i]*tb[i]%mod+mod)%mod;
	NTT(tb,-1);
	for(int i=0;i<t;i++){
		tb[i]=(tb[i]*inv[t])%mod;
	}
	tb.resize(n);
	return tb;
}
vector<ll>PolyDeriv(vector<ll>&a){
	int n=a.size();
	vector<ll>res(n-1);
	for(int i=0;i<n-1;i++){
		res[i]=1ll*(i+1)*a[i+1]%mod;
	}
	return res;
}
vector<ll>PolyInt(vector<ll>&a){
	int n=a.size();
	vector<ll>res(n+1,0);
	for(int i=0;i<n;i++){
		res[i+1]=1ll*inv[i+1]*a[i]%mod;
	}
	return res;
}
vector<ll>PolyLn(vector<ll>&a){
	int n=a.size();
	int t=1;
	while(t<n)t<<=1;
	auto inva=PolyInv(a,t);
	auto dera=PolyDeriv(a);
	t=1;
	while(t<(n<<1))t<<=1;
	inva.resize(t,0);
	dera.resize(t,0);
	NTT(inva,1);
	NTT(dera,1);
	for(int i=0;i<t;i++){
		inva[i]=inva[i]*dera[i]%mod;
	}
	NTT(inva,-1);
	for(int i=0;i<t;i++){
		inva[i]=inva[i]*inv[t]%mod;
	}
	auto res=PolyInt(inva);
	res.resize(n);
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	init();
	vector<ll>b(n+1);
	b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=invfact[i]*qp(qp(2,1ll*i*(i-1)>>1),mod-2)%mod*(i&1?-1:1);//其实这里是-b
		if(b[i]<0)b[i]+=mod;
	}
	int t=1;
	while(t<n)t<<=1;
	auto a=PolyInv(b,t);//a=1/(1-b)
	for(int i=0;i<=n;i++){
		a[i]=a[i]*qp(2,1ll*i*(i-1)>>1)%mod;
	}
	a.resize(n+1);
	auto g=PolyLn(a);
	for(int i=1;i<=n;i++){
		cout<<g[i]*fact[i]%mod<<'\n';
	}
	return 0;
}
