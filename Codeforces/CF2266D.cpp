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
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		v[i]-=i;
	}
	sort(v.begin()+1,v.end());
	v.erase(unique(v.begin()+1,v.end()),v.end());
	int k=v[1],x=1,ans=1;
	for(int i=2;i<=n;i++){
		if(k==v[i]-1){
			x++;
			ans=max(ans,x);
		}
		else{
			x=1;
		}
		k=v[i];		
	}
	ans=max(ans,x);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
