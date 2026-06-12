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
ll a,b,ans=0,n;
vector<ll>lucky,valid(1);
void gen(ll x){
	lucky.push_back(x);
	if(10*x+6<=b)gen(10*x+6);
	if(10*x+8<=b)gen(10*x+8);
}
void dfs(int cur,int num,ll lcm_){
	if(cur>n){
		if(num){
			ans+=(num&1?1:-1)*(b/lcm_-(a-1)/lcm_);
		}
		return;
	}
	dfs(cur+1,num,lcm_);
	ll _lcm=lcm(lcm_,valid[cur]);
	if(_lcm<=b&&_lcm>0){
		dfs(cur+1,num+1,_lcm);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a>>b;
	gen(0);
	sort(lucky.begin()+1,lucky.end());
	lucky.erase(unique(lucky.begin(),lucky.end()),lucky.end());
	for(int i=1;i<lucky.size();i++){
		bool f=true;
		for(int j=1;j<i;j++){
			if(lucky[i]%lucky[j]==0){
				f=false;break;
			}
		}
		if(f)valid.push_back(lucky[i]);
	}
	n=valid.size()-1;
	sort(valid.begin()+1,valid.end(),greater<ll>());
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
