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
	vector<int>a(n+1),fa(n+1);
	map<int,int>l;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mn=a[1],mx=a[1];
	l[a[1]]=1;fa[1]=0;
	for(int i=2;i<=n;i++){
		l[a[i]]=i;
		if(a[i]-1<mn || a[i]-1>mx){
			fa[i]=0;
			mn=mx=a[i];
		}
		else{
			mx=a[i];
			fa[i]=l[a[i]-1];
		}
	}
	ll ans=0;
	//for(int i=1;i<=n;i++)debug(fa[i]);
	ll anst=0;
	for(int i=1;i<=n;i++){
		ans+=anst+1;
		ans+=i-1-fa[i];
		anst+=i-1-fa[i];
		anst++;
		//debug(i),debug(ans);debug(anst)<<'\n';
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
