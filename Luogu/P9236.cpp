#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[100005],x[100005],w[20],i,j,n;
	long long ans;
	cin>>n;
	x[0]=0; 
	for(i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i]^x[i-1];
	}
	memset(w,0,sizeof(w));
	for(i=0;i<=20;i++){
		for(j=1;j<=n;j++){
			w[i]+=(x[j] & 1);
			x[j]>>=1;
		}
		ans+=(1LL<<i)*w[i]*(n-w[i]);
	}
	cout<<ans;
} 
