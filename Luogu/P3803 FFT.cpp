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
const double pi=acos(-1);
void FFT(vector<complex<double>> &x,int dir){
	int n=x.size();
	if(n==1)return;
	int half=n/2;
	vector<complex<double>> even(half),odd(half);
	for(int i=0;i<half;i++){
		even[i]=x[2*i];
		odd[i]=x[2*i+1];
	}
	FFT(even,dir);
	FFT(odd,dir);
	complex<double>omegai=1,omega=polar(1.0,dir*2*pi/x.size());
	for(int i=0;i<half;i++){
		x[i]=even[i]+odd[i]*omegai;
		x[i+half]=even[i]-odd[i]*omegai;
		omegai*=omega;		
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int x=n+m+1;
	x--;	x|=x>>1;x|=x>>2;
	x|=x>>4;x|=x>>8;x|=x>>16;
	x++;
	double r;
	vector<complex<double>>a(x,0),b(x,0);
	for(int i=0;i<=n;i++){
		cin>>r;a[i]=r;
	}
	for(int i=0;i<=m;i++){
		cin>>r;b[i]=r;
	}
	FFT(a,1);
	FFT(b,1);
	vector<complex<double>>c(x,0);
	for(int i=0;i<x;i++){
		c[i]=a[i]*b[i];
		c[i]/=x;
	}
	FFT(c,-1);
	for(int i=0;i<=n+m;i++){
		cout<<(ll)(c[i].real()+0.5)<<' ';
	}
	return 0;
}
