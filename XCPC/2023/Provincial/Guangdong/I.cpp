#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<pii>pos(n*m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			pos[x]={i,j};
		}	
	}
	set<pii>sp;
	for(int i=0;i<=n*m-1;i++){
		if(!sp.empty()){
			auto it=sp.lower_bound(pos[i]);
			if(it!=sp.end()){
				if(pos[i].second>(*it).second){
					cout<<i<<'\n';
					return;
				}
			}
			if(it!=sp.begin()){
				if(pos[i].second<(*prev(it)).second){
					cout<<i<<'\n';
					return;
				}
			}
		}
		sp.insert(pos[i]);
	}
	cout<<n*m<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
}
