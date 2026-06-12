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
void solve(){
	int n;
	ll k;
	cin>>n>>k;
	multiset<ll>q,r;
	for(int i=1;i<=n;i++){
		ll qq;
		cin>>qq;
		q.insert(qq);
	}
	for(int i=1;i<=n;i++){
		ll rr;
		cin>>rr;
		r.insert(rr);
	}
	for(auto it=q.begin();it!=q.end();){
		//q(r+1)+r<=k 找到最大的r
		//即 (q+1)r<=k-q
		//r<=(k-q)/(q+1)
		ll tar=(k-(*it))/((*it)+1);
		//cerr<<*it<<' '<<tar<<endl;
		auto rit=r.upper_bound(tar);
		if(rit==r.begin())break;
		else{
			rit--;
			r.erase(rit);
			it=q.erase(it);
		}
	}
	cout<<n-q.size()<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
