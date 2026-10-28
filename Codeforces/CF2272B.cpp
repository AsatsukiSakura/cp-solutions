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
	int n;
	string s[2];
	cin>>n>>s[0]>>s[1];
	s[0]=' '+s[0];
	s[1]=' '+s[1];
	int p[2]={0,0};
	int c[2]={0,0};
	for(int x=0;x<=1;x++){
		for(int i=1;i<=n;){
			if(i<=n-1&&s[x][i]=='f'&&s[x][i+1]=='f')p[x]++,i+=2;	
			else if(s[x][i]=='f')c[x]++,i++;
			else i++;
		}
	}
	
	if(c[0]==c[1]){
		cout<<0<<'\n';
		return;
	}
	if(c[0]<c[1]){
		if(c[0]+2*p[0]<=c[1]){
			c[0]+=2*p[0];
			cout<<c[1]-c[0]<<'\n';
		}
		else{
			if((c[1]-c[0])&1)cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	if(c[0]>c[1]){
		if(c[1]+2*p[1]<=c[0]){
			c[1]+=2*p[1];
			cout<<c[0]-c[1]<<'\n';
		}
		else{
			if((c[0]-c[1])&1)cout<<1<<'\n';
			else cout<<0<<'\n';
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
