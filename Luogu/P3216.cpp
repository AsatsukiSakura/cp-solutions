#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=1e9+7;
struct matrix{
	ll num[4][4];
	matrix(){ 
        memset(num,0,sizeof(num));
        num[1][1]=num[2][2]=num[3][3]=1;
    }
}e;
matrix mul(matrix x,matrix y){
	int i,j,k;
	matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			for(k=1;k<=3;k++){
				ans.num[i][j]+=x.num[i][k]*y.num[k][j];
				ans.num[i][j]%=mod;
			}
	return ans;
}
matrix power(matrix x,ll b){
	matrix ans;
	while(b!=0){
		if(b&1)	ans=mul(ans,x);
	x=mul(x,x);
	b>>=1;
	}
	return ans;
}
int main(){
	ll n;int i; 
	cin>>n;
	matrix a[20]={};
	ll p10[20];p10[0]=1; 
	for(i=1;i<=19;i++){
		p10[i]=(10*p10[i-1])%mod;
	for(i=1;i<=log10(n)+1;i++){
		a[i].num[1][1]=p10[i];	a[i].num[1][2]=1;a[i].num[1][3]=0;
		a[i].num[2][1]=0;		a[i].num[2][2]=1;a[i].num[2][3]=1;
		a[i].num[3][1]=0;		a[i].num[3][2]=0;a[i].num[3][3]=1;
	}
	for(i=1;i<=log10(n)+1;i++)
		e=mul(e,power(a[i],max(n-p10[i-1],p10[i]-p10[i-1]));
	cout<<(e.num[1][2]+e.num[1][3])%mod;
	return 0;
}
