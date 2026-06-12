#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int order=2;
struct matrix{
	long long num[order+1][order+1];
};
matrix mul(matrix x,matrix y,int w){
	matrix z={};
	for(int i=1;i<=w;i++)
		for(int j=1;j<=w;j++)
			for(int k=1;k<=w;k++){
				z.num[i][j]+=x.num[i][k]*y.num[k][j];
				z.num[i][j]%=mod;
			}
	return z;
}
void solve(){
	int i;
	long long n;cin>>n;
	matrix a[70],e;	
	e.num[1][1]=1; e.num[1][2]=0;
	e.num[2][1]=0; e.num[2][2]=1;
	a[0].num[1][1]=0; a[0].num[1][2]=1;
	a[0].num[2][1]=1; a[0].num[2][2]=1;
	for(i=1;i<=69;i++)	a[i]=mul(a[i-1],a[i-1],order);
	n--;i=0;
	while(n){
		if(n&1)
			e=mul(e,a[i],order);
		n>>=1;i++;
	}
	cout<<(e.num[2][1]+e.num[2][2]+e.num[1][2])%mod<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)	solve();
	return 0; 
}
