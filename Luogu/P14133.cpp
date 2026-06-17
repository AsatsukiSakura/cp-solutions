#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[2025][2025],min,i,j;
	cin>>n;
    	if(n%2==0){
    	    min=0;
    	    for(i=1;i<=n;i++){
    	        for(j=1;j<=n;j++)
    	            a[i][j]=i+n*j-n;
    	    }
	}
    	if(n%2==1)     {
    	    min=1;
    	    for(i=1;i<=n-1;i++)
    	        for(j=1;j<=n-1;j++)
    	            a[i][j]=1+(i-1)*(n+1)+(j-1); 
    	    for(i=1;i<=n-1;i++){
    	        a[n][i]=i*(n+1)-1;
    	        a[i][n]=i*(n+1);
    	    }
    	    a[n][n]=n*n;
    	}
	cout<<min<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		cout<<a[i][j]<<' ';
	cout<<endl;
	}
	return 0; 
} 