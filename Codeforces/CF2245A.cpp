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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s=' '+s;
	if(2*k>n){
		cout<<-1<<'\n';return;
	}
	int cnt=0;
	for(int i=1;i<=k;i++)cnt+=(s[i]!='R');
	for(int i=n;i>=n-k+1;i--)cnt+=(s[i]!='L');
	cout<<cnt<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
