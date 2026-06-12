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
	ll s,m;
	cin>>s>>m;
	if(s%(m&-m)!=0){
		cout<<-1<<'\n';
		return;
	}
	s/=(m&-m);
	m/=(m&-m);
	vector<ll>cnt(63);
	for(int i=0;i<=62;i++){
		cnt[i]=((s>>i)&1);
	}
	for(int i=62;i>=1;i--){
		if(((m>>i)&1)==0){
			cnt[i-1]+=2*cnt[i];
			cnt[i]=0;
		}
	}
	ll l=1,r=s;
	while(l<=r){
		ll mid=(l+r)>>1;
		auto tmp=cnt;
		for(int i=62;i>=1;i--){
			if(((m>>i)&1)==0){
				tmp[i-1]+=2*tmp[i];
				tmp[i]=0;
			}
			else if(tmp[i]>mid){
				tmp[i-1]+=2*(tmp[i]-mid);
				tmp[i]=mid;
			}
		}
		if(*max_element(tmp.begin(),tmp.end())<=mid){
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
