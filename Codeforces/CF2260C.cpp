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
	int x,y,a=0,b=0;
	cin>>x>>y;
	for(int i=29;i>=0;i--){
		int d=x+y-a-b;
		if((1<<i)>d){}
		else if((1<<(i+1))<d){
			a+=(1<<i),b+=(1<<i);
		}
		else{
			if(a+(1<<i)<=x)a+=(1<<i);
			else b+=(1<<i);
		}
	}
	cout<<(a^b)<<' '<<x-a<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
