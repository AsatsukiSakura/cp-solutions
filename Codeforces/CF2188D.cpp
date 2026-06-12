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
ll x,y,p1,q1;
ll dist;
void update(ll p,ll q){
	ll tmp=abs(x-p)+abs(y-q);
	if(tmp<dist){
		dist=tmp;
		p1=p;
		q1=q;
	}
}
void solve(){
	cin>>x>>y;
	dist=inf*inf;
	update(x,y&~x);
	update(y,x&~y);
	for(int i=0;i<=30;i++){
		int bx=(x>>i)&1,by=(y>>i)&1;
		ll h=~((1ll<<(i+1))-1);
		ll l=(1ll<<i)-1;
		if(bx){//借位
			ll p=x^(1ll<<i);
				p|=l;
				update(p,y&~p);
		}
		else{//进位
			ll p=(x&h)|(1ll<<i); 
			update(p,y&~p);
		}
		if(by){//借位
			ll q=y^(1ll<<i);
			q|=l;
			update(x&~q,q);
		}
		else{//进位
			ll q=(y&h)|(1ll<<i); 
			update(x&~q,q);
		}
	}
	cout<<p1<<' '<<q1<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
