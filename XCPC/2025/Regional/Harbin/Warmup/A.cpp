#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
using pii=pair<int,int>;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<pii>c(n+1,{0,0});
	for(int i=1;i<=n;i++)
		cin>>c[i].first>>c[i].second;
	sort(c.begin(),c.end());
	ll g=0;
	for(int i=1;i<=n;i++){
		g+=1ll*k*(c[i].first-c[i-1].first);
		g-=c[i].second;
		if(g<0){
			cout<<"No\n";return;
		}
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
}
