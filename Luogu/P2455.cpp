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
const double eps=1e-5;
struct Matrix{
	int n;
	vector<vector<double>>a;
	Matrix(int n){
		this->n=n;
		a=vector<vector<double>>(n+1,vector<double>(n+1,0.0));
	}
	double& operator()(int x,int y){
		return a[x][y];
	}
	void rowadd(int x,double k,int y){
		for(int i=1;i<=n;i++){
			a[y][i]+=k*a[x][i];
		}
	}
	void rowswap(int x,int y){
		swap(a[x],a[y]);
	}
	bool is0r(int x){
		for(int i=1;i<=n;i++){
			if(abs(a[x][i])>eps)return false;
		}
		return true;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	Matrix a(n);
	vector<double>b(n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>a(i,j);
		cin>>b[i];
	}
	for(int i=1,j=1;j<=n&&i<=n;j++){
		int imax=i;
		for(int ii=i+1;ii<=n;ii++){
			if(abs(a(ii,j))>abs(a(imax,j)))
				imax=ii;
		}
		if(abs(a(imax,j))<eps)continue;
		if(imax!=i){
			a.rowswap(i,imax);
			swap(b[i],b[imax]);
		}
		b[i]/=a(i,j);
		for(int jj=1;jj<=n;jj++)	
			if(jj!=j)	a(i,jj)/=a(i,j);
		a(i,j)=1;
		for(int ii=1;ii<=n;ii++){
			if(i==ii)continue;
			double f=-1.0*a(ii,j);
			a.rowadd(i,f,ii);
			b[ii]+=f*b[i];
		}
		i++;
	}
	int i=n;
	for(;a.is0r(i)&&i>=1;i--){
		if(abs(b[i])>eps){cout<<-1;return 0;}
	}
	if(i<n){cout<<0;return 0;}
	else{
		for(int i=1;i<=n;i++)
			cout<<'x'<<i<<'='<<fixed<<setprecision(2)<<b[i]<<'\n';
		return 0;
	}
}
/*
4
0 0 1 1 1
0 0 1 0 1
0 0 0 1 1
0 0 0 0 0
*/
