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
struct Bigint{
	vector<complex<double>>a;
	Bigint& operator/=(int b){
		for(auto &x:a){
			x/=b;
		}
		return *this;
	}
	Bigint operator*(Bigint &b){
		int x=a.size()+b.a.size()-1;
		x--;	x|=x>>1;x|=x>>2;
		x|=x>>4;x|=x>>8;x|=x>>16;
		x++;
		Bigint c;
		c.a.resize(x,0);
		a.resize(x,0);
		b.a.resize(x,0);
		FFT(a,1);FFT(b.a,1);
		for(int i=0;i<x;i++){
			c.a[i]=a[i]*b.a[i];
		}
		FFT(c.a,-1);
		c/=x;
		c.a.resize(x+10,0);
		for(int i=0;i<x || abs(c.a[i].real())>=1e-2;i++){
			int val=(int)(c.a[i].real()+0.5);
			if(val>=10){
				c.a[i+1]+=val/10;
				c.a[i].real(val%10);
			}
		}
		while(!c.a.empty()&&abs(c.a.back().real())<=1e-2)c.a.pop_back();
		return c;
		
	}
	friend istream& operator>>(istream& is,Bigint &b){
		b.a.clear();
		string str;
		is>>str;
		b.a.resize(str.size());
		for(int i=0;i<str.size();i++){
			b.a[str.size()-1-i]=str[i]-'0';
		}
		return is;
	}
	friend ostream& operator<<(ostream& os,const Bigint &b){
		for(int i=b.a.size()-1;i>=0;i--){
			os<<(int)(b.a[i].real()+0.5);
		}
		return os;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Bigint a,b;
	cin>>a>>b;
	cout<<(a*b);
	return 0;
}
