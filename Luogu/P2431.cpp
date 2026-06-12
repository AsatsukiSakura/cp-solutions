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
using ull=unsigned long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ull a,b;
	cin>>a>>b;
	ull cnt=0;
	for(int i=0;;i++){
		cnt+=(1ull<<i);
		if(cnt>=b) break;
	}
	for(int i=63;i>=0;i--){
		if(cnt-a>=(1ull<<i))
			cnt-=(1ull<<i);
		if(cnt<=b)break;
	}
	cout<<__builtin_popcountll(cnt);
	return 0;
}
