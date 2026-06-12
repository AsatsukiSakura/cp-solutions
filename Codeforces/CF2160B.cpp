#include<bits/stdc++.h>
using ll=long long;
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<ll> a(n+1),b(n+1),last(n+1);
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	last[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=last[i-b[i]+b[i-1]];
		if(i==b[i]-b[i-1])	last[0]++;
		last[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
