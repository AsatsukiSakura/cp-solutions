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
	struct work{
		int d,p;
	};
	vector<work>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i].d>>a[i].p;
	sort(a.begin()+1,a.end(),[](const work &x,const work &y){
		return x.d<y.d;
	});
	auto cmp=[](const work& x,const work &y){
		return x.p>y.p;
	};
	ll ans=0;
	priority_queue<work,vector<work>,decltype(cmp)>pq(cmp);
	for(int i=1;i<=n;i++){
		if((int)pq.size()<a[i].d){
			ans+=a[i].p;
			pq.push(a[i]);
		}
		else{
			if(!pq.empty()&&pq.top().p<a[i].p){
				ans-=pq.top().p;
				ans+=a[i].p;
				pq.pop();
				pq.push(a[i]);
			}
		}
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
