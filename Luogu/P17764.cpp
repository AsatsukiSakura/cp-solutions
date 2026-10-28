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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>a,b;
	if(n<=4)cout<<-1;
	else{
		for(int i=1;i<=n;i+=2){
			a.push_back(i);
			b.push_back(i+2);
			if(b.back()>n)b.back()=2;
		}
		for(int i=2;i<=n;i+=2){
			a.push_back(i);
			b.push_back(i+2);
			if(b.back()>n)b.back()=1;
		}
		for(int x:a)cout<<x<<' ';
		cout<<'\n';
		for(int y:b)cout<<y<<' ';
	}
	return 0;
}
