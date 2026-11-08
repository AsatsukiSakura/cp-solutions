#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	ll s=0,ss=0;
	if(n&1){
		for(int i=1;i<=n;i++)s+=abs(a[i]-a[(n+1)>>1]);
	}else{
		for(int i=1;i<=n;i++)s+=abs(a[i]-a[n>>1]),ss+=abs(a[i]-a[1+n/2]);
		s=min(s,ss);
	}
	cout<<s<<' '<<a[n]-a[1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
