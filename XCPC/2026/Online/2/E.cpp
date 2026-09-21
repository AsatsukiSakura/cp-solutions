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
	map<int,int>cnt;
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			n/=i;
			cnt[i]++;
		}
	}
	if(n>1)cnt[n]++;
	vector<int>v;
	for(auto &[p,k]:cnt){
		if(p==2){
			if(k>=2)v.push_back(2);
			if(k>2)v.push_back(1<<(k-2));
		}
		else{
			int j=1;
			for(int i=1;i<=k;i++){
				j*=p;
			}
			j-=j/p;
			v.push_back(j);
		}
	}
	map<int,map<int,int>>cy;
	for(int o:v){
		for(int i=2;i*i<=o;i++){
			int c=0;
			while(o%i==0){
				o/=i;
				c++;
			}
			if(c)cy[i][c]++;
		}
		if(o>1)cy[o][1]++;
	}
	ll ans=1;
	for(auto &[p,mp]:cy){
		ll cur=1; 
		ll pren=1; 
		ll pk=1;
		int mxe=mp.rbegin()->first; 
		for(int k=1;k<=mxe;k++){
			ll pw=0;
			for(auto &[e,c]:mp){
				pw+=min(e,k)*c;
			}
			ll curn=1;
			for(int i=1;i<=pw;i++){
				curn*=p;
			}
			pk*=p; 
			cur+=(curn-pren)*pk; 
			pren=curn;
		}
		ans*=cur;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
