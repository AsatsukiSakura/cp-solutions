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
	for(int j=1;j<=n-1;j++){
		pair<int,double>imax={j,abs(a(j,j))};
		for(int i=j+1;i<=n;i++){
			if(abs(a(i,j))>imax.second)
				imax={i,abs(a(i,j))};
		}
		if(abs(imax.second)<eps)continue;
		if(imax.first!=j){
			a.rowswap(j,imax.first);
			swap(b[j],b[imax.first]);
		}
		for(int i=j+1;i<=n;i++){
			double f=-1.0*a(i,j)/a(j,j);
			a.rowadd(j,f,i);
			b[i]+=f*b[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(abs(a(i,i))<eps){
			cout<<"No Solution.";
			return 0;
		}
	}
	for(int j=n;j>=1;j--){
		b[j]/=a(j,j);
		a(j,j)=1.0;
		for(int i=j-1;i>=1;i--){
			double f=-1.0*a(i,j);
			a(i,j)=0;
			b[i]+=f*b[j];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<fixed<<setprecision(2)<<b[i]<<'\n';
	return 0;
}
