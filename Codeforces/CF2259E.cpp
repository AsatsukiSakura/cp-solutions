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
	vector<int>b(n+1,0),d(n+2,0);
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=0)continue;
		int l=max(1,i-b[i]+1);
		int r=min(n,i+b[i]-1);
		d[l]--,d[r+1]++;
	}
	for(int i=1;i<=n;i++)
		d[i]+=d[i-1];
	for(int i=1;i<=n;i++){
		if(b[i]==-1)continue;
		if((i-b[i]<1||d[i-b[i]]<0)&&(i+b[i]>n||d[i+b[i]]<0)){
			cout<<"-1\n";return;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<(d[i]<0?0:1);
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
