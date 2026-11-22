#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int n,m,k;
	cin>>n>>k>>m;
	if(m==n)m--;
	int d=n/k;
	int xd=n-d;
	if(m<=xd){
		cout<<m+1+(d-1)/2<<'\n';
	}
	else{
		m-=xd;
		d-=m;
		//debug(m),debug(xd),debug(d);
		cout<<xd+1+(d-1)/2+m<<'\n';
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
}
