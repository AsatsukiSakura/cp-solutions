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
	int l=1,r=999;
	while(l+1<r){
		int ml=l+(r-l)/3;
		int mr=l+2*(r-l)/3;
		cout<<"? "<<ml<<' '<<mr<<endl;
		int x;
		cin>>x;
		if(x==ml*mr)l=mr;
		if(x==ml*(mr+1))l=ml,r=mr;
		if(x==(ml+1)*(mr+1))r=ml;
	}
	cout<<"! "<<r<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
