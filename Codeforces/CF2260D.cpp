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
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	if(s[1]=='0'||s.find("00")!=string::npos){cout<<"-1\n";return;}
	for(int k=1;k<=2;k++){
		int l=0,r=0;
		bool b=true;
		for(int i=1;i<=n;i++){
			int p=(l==r)?l:mod;
			l-=k,r+=k;
			if(s[i]=='0'){
				if(l>0||r<0){b=false;break;}
				l=r=0;
			}
			if(s[i]=='+'){
				if(r<=0){b=false;break;}
				l=max(1,l);
				if(l==p)l++;
				if(k==1&&l%2!=i%2)l++;
			}
			if(s[i]=='-'){
				if(l>=0){b=false;break;}
				r=min(-1,r);
				if(r==p)r--;
				if(k==1&&abs(r)%2!=i%2)r--;
			}
		}
		if(b){cout<<k<<'\n';return;}
	}
	cout<<3<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
