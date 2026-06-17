#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7; 
struct matrix{
		long long num[3][3];
	}a[63],e;
matrix matrixmul(matrix m1,matrix m2,int w){
	matrix m3;
	memset(m3.num,0,sizeof(m3.num));
	for(int i=1;i<=w;i++)
			for(int j=1;j<=w;j++)
				for(int k=1;k<=w;k++){
					m3.num[i][j]+=m1.num[i][k]*m2.num[k][j];
					m3.num[i][j]%=mod;
				}		
	return m3;
}
int main(){
	a[0].num[1][1]=1;
	a[0].num[1][2]=1;
	a[0].num[2][1]=1;
	a[0].num[2][2]=0;
	e.num[1][1]=1;
	e.num[1][2]=0;
	e.num[2][1]=0;
	e.num[2][2]=1;
	for(int i=1;i<=62;i++){
		a[i]=matrixmul(a[i-1],a[i-1],2);
	}
	long long n;	cin>>n;
	if(n<=2) cout<<1;
	else{
    	    n-=2;
		int i=0;
		while(n){
			if(n&1)	
				e=matrixmul(e,a[i],2);
			n>>=1;
    	        i++;
		}
		cout<<(e.num[1][1]+e.num[1][2])%mod;
	}
	return 0; 
} 
