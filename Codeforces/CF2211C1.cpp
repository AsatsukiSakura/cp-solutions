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
	vector<int>a(n+1),b(n+1);
	vector<int>fa(n+1,0),fb(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	for(int i=1;i<=k;i++){
		set<int>s;
		for(int j=i;j<=n;j+=k){
			s.insert(a[j]);
		}
		if(s.size()==1){
			fa[*s.begin()]++;
			set<int>s1;
			for(int j=i;j<=n;j+=k){
				if(b[j]!=-1)s1.insert(b[j]);
			}
			if(s1.size()>1)	{cout<<"NO\n";return;}
			if(s1.size()==1)fb[*s1.begin()]++;
		}
		else{
			for(int j=i;j<=n;j+=k){
				if(b[j]!=-1 && a[j]!=b[j])	{cout<<"NO\n";return;}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(fb[i]>fa[i])	{cout<<"NO\n";return;}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
