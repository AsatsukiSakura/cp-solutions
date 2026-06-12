#include<bits/stdc++.h>
int n,k,l[100005];
using namespace std;
long double eps=1e-3;
bool check(int a,int k){
	int i,sum=0;
	for(i=1;i<=n;i++)
		sum+=floor(l[i]/a);
	return (sum>=k);
}
int binaryanswer(int low,int high,int k){
	int mid=(low+high)/2; 
	if(high-low<=eps)	return mid;
	if(check(mid,k))	return binaryanswer(mid,high,k);
	else	return binaryanswer(low,mid,k);
}
int main(){
	int i; 
	cin>>n>>k;
	for(i=1;i<=n;i++)	cin>>l[i];
	cout<<binaryanswer(0,INT_MAX,k);
	return 0; 
} 
