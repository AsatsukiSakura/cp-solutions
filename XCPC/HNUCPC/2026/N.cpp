#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int n;
	cin>>n;
	vector<ll>a(n+1,0);
	for(int i=1;i<=n;i++)
	a[i]=a[i-1]+(1ll<<(n-i));
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}
