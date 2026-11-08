#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	ll s=0;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	if(s==n)cout<<"-1\n";
		else if(s-a[1]-a[n]==n-2)
			cout<<s-n+1<<'\n';
			else cout<<s-1<<'\n';
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
