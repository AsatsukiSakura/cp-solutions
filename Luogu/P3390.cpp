#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
struct Matrix{
	int ord;
	vector<vector<ll>>num;
	Matrix(int ord){
		this->ord=ord;
		num.resize(ord+1,vector<ll>(ord+1,0));
	}
	void e(){
		for(int i=1;i<=ord;i++)
			this->num[i][i]=1;	
	}
	Matrix operator*(const Matrix &b){
		Matrix res(ord);
		for(int i=1;i<=ord;i++)
			for(int j=1;j<=ord;j++)
				for(int k=1;k<=ord;k++){
					res.num[i][j]+=(this->num[i][k])*(b.num[k][j]);
					res.num[i][j]%=mod;
				}
		return res;
	}
	Matrix pow(ll b){
		Matrix res(ord);
		res.e();
		Matrix base=*this;
		while(b!=0){
			if(b&1){
				res=res*base;
			}
			base=base*base;
			b>>=1;
		}
		return res;
	}
	friend ostream& operator<<(ostream &os,const Matrix &m){
		for(int i=1;i<=m.ord;i++){
			for(int j=1;j<=m.ord;j++){
				os<<m.num[i][j]<<' ';
			}
			os<<endl;
		}
		return os;
	}
	friend istream& operator>>(istream &is,Matrix &m){
		for(int i=1;i<=m.ord;i++){
			for(int j=1;j<=m.ord;j++){
				is>>m.num[i][j];
			}
		}
		return is;
	}
};
int main(){	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll k;int n;
	cin>>n>>k;
	Matrix a(n);
	cin>>a;
	a=a.pow(k);
	cout<<a;
	return 0;
}
