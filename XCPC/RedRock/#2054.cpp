#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=1001;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	int p;
	cin>>p;
	int ans=0;
	for(int i=1;i<=p;){
		
		int j=mod/(mod/i);
		if(j<=p){
			ans^=(j-i+1);
			i=j+1;
		}
		else{
			ans^=(p-i+1);
			i=p+1;
		}
		debug(i);
	}
	cout<<ans<<endl;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
