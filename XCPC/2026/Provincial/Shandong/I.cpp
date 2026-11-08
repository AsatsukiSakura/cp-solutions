#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
void solve(){
	int n;
	cin>>n;
	vector<pii>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	pii p=*max_element(a.begin(),a.end());
	cout<<p.first<<' '<<p.second<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	
}
