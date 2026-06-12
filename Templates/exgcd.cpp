#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int x1,y1;
	int gcd=exgcd(b,a%b,x1,y1);
	x=y1;y=x1-(a/b)*y1;
	return gcd;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b,x,y;
	cin>>a>>b;
	exgcd(a,b,x,y);
	cout<<x;
	return 0;
}
