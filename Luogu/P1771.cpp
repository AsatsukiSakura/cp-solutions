#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1000;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
struct Bigint{
	vector<int>d;
	int sign;
	Bigint(ll v=0){
		sign=v<0?-1:1;
		if(sign==-1)v=-v;
		d.clear();
		if(v==0)d.push_back(0);
		while(v>0){
			d.push_back(v%10);
			v/=10;
		}
	}
	void clean(){
		while(d.size()>1&&d.back()==0) 
			d.pop_back();
	}
	Bigint operator*(const Bigint& b)const{
		Bigint r;
		r.d.resize(d.size()+b.d.size(),0);
		for(int i=0;i<d.size();i++){
			for(int j=0;j<b.d.size();j++){
				r.d[i+j]+=d[i]*b.d[j];
				if(r.d[i+j]>=10){
					r.d[i+j+1]+=r.d[i+j]/10;
					r.d[i+j]%=10;
				}
			}
		}
		r.clean();
		return r;
	}
	Bigint operator+(const Bigint& b) const {
		Bigint r;
		int n=d.size(),m=b.d.size();
		r.d.resize(max(n,m)+1,0);
		for (int i=0;i<max(n,m);i++) {
			if(i<n)r.d[i]+=d[i];
			if(i<m)r.d[i]+=b.d[i];
			if(r.d[i]>=10) {
				r.d[i+1]++;
				r.d[i]-=10;
			}
		}
		r.clean();
		return r;
	}
	Bigint operator-(const Bigint& b)const{
		Bigint r=*this;
		if(*this<b){
			r=b-*this;
			r.sign=-1;
			return r;
		}
		for(int i=0;i<b.d.size();i++){
			r.d[i]-=b.d[i];
			if(r.d[i]<0){r.d[i]+=10;r.d[i+1]--;}
		}
		for(int i=b.d.size();i<r.d.size()-1&&r.d[i]<0;i++){
			r.d[i]+=10;r.d[i+1]--;
		}
		r.clean();return r;
	}
	Bigint operator/(int b)const{
		Bigint r=*this;
		ll c=0;
		for(int i=r.d.size()-1;i>=0;i--){
			ll t=r.d[i]+c*10;
			r.d[i]=t/b; 
			c=t%b;
		}
		r.clean(); 
		return r;
	}
	bool operator<(const Bigint& b)const{
		if(d.size()!=b.d.size())
			return d.size()<b.d.size();
		for(int i=d.size()-1;i>=0;i--)
			if(d[i]!=b.d[i])
				return d[i]<b.d[i];
		return false;
	}
	friend istream& operator>>(istream& is, Bigint& b){
		string s;
		cin>>s;
		b.d.clear();
		for(int i=s.size()-1;i>=0;i--) {
			b.d.push_back(s[i]-'0');
		}
		b.clean();
		return is;
	}
	friend ostream& operator<<(ostream& os,const Bigint& b){
		if(b.sign==-1)os<<'-';
		for(int i=b.d.size()-1;i>=0;i--){
			os<<b.d[i];
		}
		return os;
	}
};
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x,k;
	cin>>k>>x;
	x=qp(x,x);
	Bigint ans(1);
	for(int i=x-1;i>=k;i--){
		ans=ans*Bigint(i);
	}
	for(int i=2;i<=x-k;i++){
		ans=ans/i;
	}
	cout<<ans;
	return 0;
}
