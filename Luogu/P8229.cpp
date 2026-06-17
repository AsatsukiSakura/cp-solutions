#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<' '
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
struct Matrix{
    	int n;
    	ll a[4][4]={};
    	Matrix(int n){
    	    this->n=n;
    	    memset(a,0,sizeof(a));
    	}
    	void identity(){
    	    for(int i=1;i<=n;i++)
    	        a[i][i]=1;
    	}
    	Matrix operator*(const Matrix &b)const{
    	    Matrix res(n);
    	    for(int i=1;i<=n;i++){
    	        for(int j=1;j<=n;j++){
    	            for(int k=1;k<=n;k++){
    	                if(a[i][k]==0||b.a[k][j]==0)continue;
    	                res.a[i][j]+=a[i][k]*b.a[k][j];
    	                if(res.a[i][j]>=mod)res.a[i][j]%=mod;
    	            }
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
void solve(){
	ll n,k,p;
    	cin>>n>>k>>p;
    	Matrix m(3);
    	m.a[1][1]=k*p%mod; m.a[1][3]=(1-p+mod)%mod;
    	m.a[2][1]=(1-p+mod)%mod; m.a[2][2]=1;
    	m.a[3][3]=1;
    	Matrix res=m.pow(n);
    	cout<<(res.a[2][1]+res.a[2][3])%mod<<'\n';
}
int main(){
    	int t;
    	cin>>t;
    	while(t--)solve();
    	return 0;
}
