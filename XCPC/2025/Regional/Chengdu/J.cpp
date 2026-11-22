#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int n,m,k,b;
	int p=0,rp=0;
	cin>>n>>m>>k>>b;
	vector<int>sc(n+1,0),rsc(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			sc[i]+=x;
			if(x>=1)rsc[i]+=x-1;
			else rsc[i]+=x+1;
		}
		//debug(rsc[i]);
		if(sc[i]>=k)p++;
		else if(rsc[i]>=k)rp++;
	}
	cout<<p+min(rp,b)<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
}
