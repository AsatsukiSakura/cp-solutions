#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d[200005];
bool check(int fac){
	int mins=0,maxs=0;
	for(int i=1;i<=n;i++){
		mins+=max(0ll,d[i]*fac-fac/2);
		maxs+=min(100ll*fac,d[i]*fac+max(fac/2-1,0ll));
	}
//	cout<<fac<<": "<<mins<<" "<<maxs<<'\n';
	return mins<=100ll*fac&&100ll*fac<=maxs;
}
void solve(){
	cin>>n;
	int mins=0,maxs=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		sum+=d[i]*10000000;
		mins+=max(0ll,d[i]*10000000-5000000);
		maxs+=min(1000000000ll,d[i]*10000000+4999999);
	}
	if(mins<=1000000000&&1000000000<=maxs){
		int avg=(1000000000-sum)/n;
		int lem=(1000000000-sum)%n;
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
			cout<<min(1000000000ll,max(0ll,d[i]*10000000+avg+(i==n?0:lem)))<<' ';
		}
		cout<<'\n';
	}else{
		cout<<"No\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
