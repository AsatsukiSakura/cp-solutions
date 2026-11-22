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
	int state=0;
	int day=1;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s=="yeshenle"){
			if(state==1)day++,state=0;
		}
		if(s=="zaoshanghao"){
			if(state==0)state=1;
		}
	}
	cout<<day;
	return 0;
}
