#include<bits/stdc++.h>
#define ld long double
#define eps 1e-2
int n,k;
ld l[10005];
using namespace std;
bool check(ld a,int k){
	int i,sum=0;
	for(i=1;i<=n;i++)
		sum+=floor(l[i]/a);
	return (sum>=k);
}
ld binaryanswer(ld low,ld high,int k){
	ld mid=(low+high)/2; 
	if(high-low<=eps)	return mid;
	if(check(mid,k))	return binaryanswer(mid,high,k);
	else	return binaryanswer(low,mid,k);
}
int main(){
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)	cin>>l[i];
	printf("%.2Lf",binaryanswer(1,LDBL_MAX,k));
	return 0; 
} 
