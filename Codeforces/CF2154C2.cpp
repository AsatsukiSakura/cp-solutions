#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<vector<int>>pfac(2e5+5);
void init(){
	for(int i=2;i<=2e5;i++){
		if(pfac[i].empty()){
			for(int j=i;j<=2e5;j+=i)
				pfac[j].push_back(i);
		}
	}
}
struct node{
	ll a,b;
};
bool cmp(node x,node y){
	return(x.b<y.b);
}
void solve(){
	int n;
	map<int,int>pcnt;
	vector<int>pfacs;
	cin>>n;
	vector<node>g(n+1);
	for(int i=1;i<=n;i++){
		cin>>g[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>g[i].b;
	}
	sort(g.begin()+1,g.end(),cmp);
	ll ans=g[1].b+g[2].b;
	for(int i=1;i<=n;i++){
		for(int p:pfac[g[i].a]){
			if(pcnt[p]>=1)	ans=0;
			pcnt[p]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int p:pfac[g[i].a]){
			pcnt[p]--;
		}
		for(int p:pfac[g[i].a+1]){
			if(pcnt[p]>=1)	ans=min(ans,g[i].b);
		}
		for(int p:pfac[g[i].a]){
			pcnt[p]++;
		}
	}
	for(int i=2;i<=n;i++){
		for(int p:pfac[g[i].a]){
			pfacs.push_back(p);
		}
	}
	for (int p:pfacs){
		int k=(p-(g[1].a%p))%p;
		ans=min(1ll*ans,1ll*k*g[1].b);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
