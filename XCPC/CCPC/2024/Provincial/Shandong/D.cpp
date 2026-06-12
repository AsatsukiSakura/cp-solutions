#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int>x(n+1);
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		int r=(b+a-1)/n;
		int d=(b+a-1)%n;
		//b~n-1 :+1
		//0~d:+1
		//0~n-1 :+r-1
		x[0]+=r;
		x[d+1]--;
		x[n]-=r;
		x[b]++;
	}
	for(int i=1;i<=n-1;i++){
		x[i]+=x[i-1];
	}
	for(int i=0;i<=n-1;i++)cout<<x[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
}
