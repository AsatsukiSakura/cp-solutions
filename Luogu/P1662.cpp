#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x,b=1,n=0;
	cin>>x;
	for(int i=1;i<=x;i++){
		n+=b;
		if(i%7==0 || i%10==7)
			b*=-1;
	}
	cout<<(n+1336)%1337+1;
	return 0;
}
