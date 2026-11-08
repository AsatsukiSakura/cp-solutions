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
	int len=1;
	while(len*97<=n)len++;
	len--;
	string c(len,'a');
	n-=97*len;
	//debug(n);
	if(n>25*len){cout<<"No\n";return;}
	cout<<"Yes\n";
	debug(n);
	for(int i=0;i<len;i++){
		if(n>25){
			n-=25;
				c[i]+=25;
		}else{
			c[i]+=n;
			break;
		}
	}
	cout<<c<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
