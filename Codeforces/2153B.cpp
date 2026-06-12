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
void solve(){
	int x,y,z;
	cin>>x>>y>>z;
	while(x!=0 || y!=0 ||z!=0){
		int p=(x&1)+(y&1)+(z&1);
		if(p==2){
			cout<<"no"<<endl;return;
		}
		x>>=1;y>>=1;z>>=1;
	}
	cout<<"yes"<<endl;return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
