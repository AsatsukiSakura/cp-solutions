#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int n,k1,k2;
	cin>>n>>k1>>k2;
	vector<ll>a(n+1),b(n+1),v(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)v[i]=1ll*k1*a[i]-1ll*k2*b[i];
	cout<<(1ll*k1*(*min_element(a.begin()+1,a.end()))-1ll*k2*(*max_element(b.begin()+1,b.end())))<<' '<<*max_element(v.begin()+1,v.end());
}
