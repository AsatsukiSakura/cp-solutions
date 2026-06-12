#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	ll x,y,k;
	cin>>x>>y>>k;
	if(y==1){cout<<-1<<endl;return;}
	if(k<y){cout<<k<<endl;return;}
	for(ll i=1;i<=x;){
		ll l=(k-1)/(y-1);
		ll nxf=((k-1)/(y-1)+1)*(y-1)+1;
		ll steps=(nxf-k+l-1)/l;
		if(i+steps<=x+1){
			i+=steps;
			k+=l*steps;
		}
		else{
			k+=l*(x+1-i);
			i=x+1;
		}
		if(k>1e12){cout<<-1<<endl;return;}
	}
	cout<<k<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}


