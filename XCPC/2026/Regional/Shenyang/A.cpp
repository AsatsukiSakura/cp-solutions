#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int k;
	cin>>k;
	vector<pii>pf(k+1);
	for(int i=1;i<=k;i++){
		cin>>pf[i].first>>pf[i].second;
	}
	vector<pii>fact;
	map<int,int>phi;
	auto dfs=[&](auto &&self,int st,int val,int cnt,int ph)->void{
		if(st==k+1){
			fact.push_back({val,cnt});
			phi[val]=ph;
			return;
		}
		for(int i=0;i<=pf[st].second;i++){
			int tmp=1;
			for(int j=1;j<=i;j++)tmp*=pf[st].first;
			self(self,st+1,val*tmp,cnt*(1+i),ph*(tmp-tmp/pf[st].first));
		}
	};
	dfs(dfs,1,1,1,1);
	int ans=0;
	sort(fact.begin(),fact.end());
	int n=fact.size();
	for(int d=1;d<=n-1;d++){
		for(int i=d,j=2;i<=n-1;i+=d,j++){
			if(fact[i].second==j){
				int ok=1;
				for(int k=d;k<=i;k++){
					if(fact[i].first%fact[k].first==0)
						ok++;
				}
				if(ok==j)ans+=phi[fact.back().first/fact[i].first];
			}
		}
	}
	ans+=phi[fact.back().first];
	cout<<ans<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
}
