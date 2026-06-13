#include<bits/stdc++.h>
using namespace std;
void solve(){
long long p,q;
	cin>>p>>q;
	cout<<180*q/gcd(p,180*q)-1<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)	solve(); 
	return 0;
}