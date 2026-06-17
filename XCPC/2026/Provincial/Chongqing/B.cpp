#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
    	int x,y,z;
	cin>>x>>y>>z;
    	set<int> s;
    	s.insert(x); s.insert(y); s.insert(z);
    	cout<<s.size()<<'\n';
}
int main(){
    	int t;
    	cin>>t;
    	while(t--){
    	    solve();
    	}
    	return 0;
}