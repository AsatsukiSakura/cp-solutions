#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
    	int n;
    	cin>>n;
    	vector<int>a(n+1);
    	map<int,int> mp;
    	int cnt=0;
    	int mn=inf;
    	ll ans=0;
    	for(int i=1;i<=n;i++){
    	    cin>>a[i];
    	    a[i]=a[i]&-a[i];
    	    if(mp[a[i]]++==0) cnt++;
    	    mn=min(mn,a[i]);
    	}
    	for(int i=0;i<=29;i++){
    	    if(mp[(1ll<<i)]==0) continue;
    	    ans+=(1ll<<i)*mp[(1ll<<i)];
    	}
    	ans+=(cnt-2)*mn;
    	cout<<ans<<'\n';
}
int main(){
    	int t;
    	cin>>t;
    	while(t--){
    	    solve();
    	}
    	return 0;
}
