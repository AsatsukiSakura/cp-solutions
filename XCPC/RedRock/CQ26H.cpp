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
	int h,w,xa,ya,xb,yb;
	cin>>h>>w>>xa>>ya>>xb>>yb;
	int t=xb-xa;
	if(t<0)cout<<"Draw\n";
	else if(t&1){
		//alien advantage
		int la=max(1,ya-(t+1)/2),ra=min(w,ya+(t+1)/2);
		int lb=max(1,yb-(t+1)/2+1),rb=min(w,yb+(t+1)/2-1);
		if(la<=lb&&ra>=rb)cout<<"Alien\n";
		else cout<<"Draw\n";
	}else{
		//rcx advantage
		int la=max(1,ya-t/2),ra=min(w,ya+t/2);
		int lb=max(1,yb-t/2),rb=min(w,yb+t/2);
		if(lb<=la&&rb>=ra)cout<<"rcx\n";
		else cout<<"Draw\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
