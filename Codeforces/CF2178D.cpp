#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<pii>a(n+1),ans;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin()+1,a.end());
	if(m>0){
		if(n<2*m){cout<<-1<<endl;return ;}
		int j=1;
		for(int i=1;i<=m-1;i++){
			ans.push_back({a[n-m+i].second,a[i].second});
		}
		for(int i=m+1;i<=n-m;i++){
			ans.push_back({a[i].second,a[i-1].second});
			
		}
		ans.push_back({a[n].second,a[n-m].second});
		cout<<ans.size()<<endl;
		for(auto p:ans){
			cout<<p.first<<' '<<p.second<<endl;
		}
	}
	else{
		ll sum=0;
		for(int i=n-1;i>=1;i--){
			sum+=a[i].first;
			if(sum>=a[n].first){
				for(int j=2;j<=i;j++){
					ans.push_back({a[j].second,a[j-1].second});
				}
				ans.push_back({a[n].second,a[i].second});
				for(int j=i+1;j<=n-1;j++){
					ans.push_back({a[j].second,a[n].second});
				}
				cout<<ans.size()<<endl;
				for(auto p:ans){
					cout<<p.first<<' '<<p.second<<endl;
				}
				return;
			}
		}
		cout<<-1<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
