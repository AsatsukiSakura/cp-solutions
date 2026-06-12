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
	/*
	1 4 16 64  256
	2 8 32 128 512
	*/
	int a,b,a_,b_;
	cin>>a>>b;
	a_=b;b_=a;
	int ans1=0,ans2=0;
	int p=1;
	while(1){
		if(a>=p){
			a-=p;
			ans1++;
		}
		else break;
		p<<=1;
		if(b>=p){
			b-=p;
			ans1++;
		}
		else break;
		p<<=1;
	}
	p=1;
	while(1){
		if(a_>=p){
			a_-=p;
			ans2++;
		}
		else break;
		p<<=1;
		if(b_>=p){
			b_-=p;
			ans2++;
		}
		else break;
		p<<=1;
	}
	cout<<max(ans1,ans2)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
