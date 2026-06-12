#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
ll mod;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
struct Matrix{
	int n;
	ll a[200][200];
	//vector<vector<ll>>a;
	Matrix(int n){
		this->n=n;
		//a=vector<vector<ll>>(n,vector<ll>(n,0));
		memset(a,0,sizeof(a));
	}
	void identity(){
		for(int i=0;i<=n-1;i++)
			a[i][i]=1;
	}
	Matrix operator*(const Matrix &b)const{
		Matrix res(n);
		for(int i=0;i<=n-1;i++){
			for(int j=0;j<=n-1;j++){
				for(int k=0;k<=n-1;k++){
					if(a[i][k]==0||b.a[k][j]==0)continue;
					res.a[i][j]+=a[i][k]*b.a[k][j];
					if(res.a[i][j]>=mod)res.a[i][j]%=mod;
				}
			}
		}
		return res;
	}
	vector<ll> operator*(const vector<ll>&b)const{
		vector<ll>res(n,0);
		for(int i=0;i<=n-1;i++){
			for(int j=0;j<=n-1;j++){
				res[i]+=this->a[i][j]*b[j];
				res[i]%=mod;
			}
		}
		return res;
	}
	Matrix& operator*=(const Matrix &b){
		*this=*this*b;
		return *this;
	}
	Matrix pow(ll p)const{
		Matrix b=*this;
		Matrix res(n);
		res.identity();
		while(p){
			if(p&1){
				res*=b;
			}
			b*=b;
			p>>=1;
		}
		return res;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,a,b;
	cin>>n>>a>>b>>mod;
	Matrix f(2*(a+b+1));
	vector<vector<ll>>c(a+b+1,vector<ll>(a+b+1,0));
	vector<ll>v(2*(a+b+1),0);
	v[0]=1;
	for(int i=0;i<=a+b;i++){
		f.a[i][i]=f.a[i][i+a+b+1]=1;
		f.a[i+a+b+1][0]=c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			f.a[i+a+b+1][j]=c[i][j];
		}
	}
	v=f.pow(n)*v;
	ll ans=0;
	vector<ll>np(a+1,1);
	for(int i=1;i<=a;i++){
		np[i]=(np[i-1]*n)%mod;
	}
	for(int i=0;i<=a;i++){
		ans+=c[a][i]*(i&1?mod-1:1)%mod*np[a-i]%mod*(v[i+b]+v[i+b+a+b+1])%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
