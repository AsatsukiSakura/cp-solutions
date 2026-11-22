#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
const ll inf =1e16;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	string s;
	string ans;
	cin>>s;
	for(char c:s){
		if(c=='-'){
			if(!ans.empty())ans.pop_back();
			continue;
		}
		if((ans.size()>=2&&ans[ans.size()-2]==c)||(ans.size()>=1&&ans[ans.size()-1]==c)){
		}else{
			ans+=c;
		}
	}
	if(ans.empty())cout<<"-\n";
	else cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
