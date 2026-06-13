#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	vector<ll>cnt(m+1,0),cntm(m+1,0);
	ll mt=0;
	for(int i=1;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(c){
			mt++;
			cntm[a]++;
		}
		cnt[a]+=b;
	}
	ll ml=*min_element(cnt.begin()+1,cnt.end());
	ll l=0,h=mt;
	while(l<=h){
		ll mid=(l+h)/2;
		if(mid>ml){
			h=mid-1;
		}
		else{
			ll tml=0;
			for(int i=1;i<=m;i++){
				ll diff=cnt[i]-mid;
				tml+=min(diff,cntm[i]);
			}
			if(tml<mid)h=mid-1;
			else l=mid+1;
		}
	}
	cout<<h;
	return 0;
}