#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
void grey(int n, ull k)
{
	if(n==0)	return;
	ull mid= 1ULL<<(n-1);
	if(k<=mid-1){
		cout<<0;grey(n-1,k);
	}
	else{
		cout<<1;grey(n-1,mid-k-1+mid);
	}
	return;
 } 
int main(){
	int n; 
    	ull k;
	cin>>n>>k;
	grey(n,k);
	return 0; 
}
