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
struct matrix{
	int n;
	vector<vector<ll>>a;
	matrix(int n){
		this->n=n;
		a=vector<vector<ll>>(n+1,vector<ll>(n+1,0));
	}
	void identity(){
		for(int i=1;i<=n;i++)
			a[i][i]=1;
	}
	matrix operator*(const matrix &b){
		matrix res(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					res.a[i][j]+=this->a[i][k]*b.a[k][j];
					res.a[i][j]%=(mod-1);//fermat little theorem
				}
			}
		}
		return res;
	}
	matrix& operator*=(const matrix &b){
		*this=*this*b;
		return *this;
	}
	matrix pow(ll x){
		matrix res(n);
		res.identity();
		matrix base=*this;
		while(x){
			if(x&1){
				res*=base;
			}
			base*=base;
			x>>=1;
		}
		return res;
	}
};
ll qp(ll b,ll x){
	ll res=1;
	while(x){
		if(x&1){
			res*=b;
			res%=mod;
		}
		b*=b;
		b%=mod;
		x>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin>>n;
	if(n==1){cout<<2;return 0;}
	if(n==2){cout<<6;return 0;}
	matrix f(2);
	f.a[1][1]=f.a[1][2]=f.a[2][1]=1;
	f.a[2][2]=0;
	matrix p=f.pow(n);
	ll p3=p.a[1][1]-1,p2=p.a[1][2];
	cout<<(qp(2,p2)*qp(3,p3))%mod;
	return 0;
}
