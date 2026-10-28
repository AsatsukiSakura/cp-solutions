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
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=inf;
	for(int i=1;i<=n;i++){
		if(a[i]==1){l=i;break;}
	}
	int r=-inf;
	for(int i=n;i>=1;i--){
		if(a[i]==1){r=i;break;}
	}
	int l_=inf;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){l_=i;break;}
	}
	int r_=-inf;
	for(int i=n;i>=1;i--){
		if(a[i]==-1){r_=i;break;}
	}
	if(l_<=l&&l_!=inf)a[l_]=1;
	if(r_>=r&&r_!=-inf)a[r_]=1;
	for(int i=1;i<=n;i++)
		if(a[i]==-1)
			a[i]=0;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
