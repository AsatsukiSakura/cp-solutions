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
	int n;
	cin>>n;
	vector<int>a(2*n+1),l(n,0),r(n);
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(l[a[i]]==0)l[a[i]]=i;
		else r[a[i]]=i;
	}
	int ans=1;
	vector<int>c3={l[0]+r[0],2*l[0],2*r[0]};
	for(int c:c3){
		vector<pii>pp;
		for(int i=0;i<n;i++){
			if(l[i]+r[i]==c)
				pp.push_back({r[i]-l[i],i});
			else if(2*l[i]==c||2*r[i]==c)
				pp.push_back({0,i});			
		}
		sort(pp.begin(),pp.end());		
		int cnt=0;
		set<int>s;
		int mex=0;	
		for(pii &p:pp){
			int dis=p.first;
			int val=p.second;
			cnt+=(dis==0?1:2);
			if(cnt==dis+1){
				s.insert(val);
				while(s.count(mex))mex++;
				ans=max(ans,mex);
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
