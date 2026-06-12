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
					res.a[i][j]%=mod;
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
void solve(){
	int q,k;
	cin>>q>>k;
	mod=k;
	matrix f(2);
	f.a[1][1]=f.a[1][2]=f.a[2][1]=1;
	f.a[2][2]=0;
	while(q--){
		ll n;
		cin>>n;
		if(k==1 || n==0)cout<<"0\n";
		else if(n<=2)cout<<1<<'\n';
		else cout<<f.pow(n-1).a[1][1]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
