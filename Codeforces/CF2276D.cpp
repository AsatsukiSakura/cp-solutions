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
	vector<int>d(n+1,0);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		d[u]++,d[v]++;
	}
	sort(d.begin()+1,d.end());
	if(d[1]==0){cout<<"Brain Melt\n";}
	else if(d[n]==n-1 && d[n-1]==1){cout<<"2\n";}
	else {cout<<"Many\n";}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
