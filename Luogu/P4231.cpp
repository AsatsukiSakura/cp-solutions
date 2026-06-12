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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<ll>a(n+10,0);
	for(int i=1;i<=m;i++){
		ll l,r,s,e;
		cin>>l>>r>>s>>e;
		if(l<r){
			ll d=(e-s)/(r-l);
			a[l]+=s;
			a[l+1]+=(d-s);
			a[r+1]-=(d+e);
			a[r+2]+=e;
		}
	}
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	ll mx=0,x=0;
	for(int i=1;i<=n;i++){
		mx=max(a[i],mx);
		x^=a[i];
	}
	cout<<x<<' '<<mx;
	return 0;
}
/*
0 a1 a2 a3 a4 ... an 0 0
0 a1 d  d   d ... d  -an 0
0 a1 d-a1 0 0 ... 0 -d-an +an

0 a1 0
0 a1 -a1
0 a1 -2a1
*/
