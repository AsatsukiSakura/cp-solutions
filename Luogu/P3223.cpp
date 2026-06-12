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
struct Bigint{
	vector<int>d;
	Bigint(ll v=0){
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
		for(int i=b.d.size()-1;i>=0;i--){
			os<<b.d[i];
		}
		return os;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	Bigint ans((n+2)*(n+3)-2*(n-m+3));
	for(int i=2;i<=n+1;i++){
		ans=ans*Bigint(i);
	}
	for(int i=n+2;i>=n-m+4;i--){
		ans=ans*Bigint(i);
	}
	cout<<ans;
	return 0;
}
