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
	int n,q,a;
	string s;
	cin>>n>>q;
	cin>>s;
	bool p=true;
	for(int i=0;i<=n-1;i++){
		if(s[i]=='B')
			p=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		if(p){
			cout<<a<<endl;
		}
		else{
			int j=1;
			for(j=1;;j++){
				if(s[i]=='A'){
					a--;
				}
				if(s[i]=='B'){
					a>>=1;
				}
				if(a==0)break;
			}
			cout<<j<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
