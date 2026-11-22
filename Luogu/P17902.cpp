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
	int n,s,t;
	cin>>n>>s>>t;
	struct Film{
		int t,q;
	};
	vector<int>q(n+1);
	for(int i=1;i<=n;i++)
		cin>>q[i];
	vector<int>l(n+1),r(n+1);
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	auto cmp=[](const Film &x,const Film &y){return x.q>y.q;};
	priority_queue<Film,vector<Film>,decltype(cmp)>pq(cmp);
	ll ans=0,ct=0;
	for(int i=1;i<=n;i++){
		ct+=r[i];
		ans+=1ll*r[i]*q[i];
		ll ddl=s+1ll*(i-1)*t;
		if(r[i]>l[i])pq.push({r[i]-l[i],q[i]});
		while(!pq.empty()&&ddl<ct){
			Film f=pq.top();
			pq.pop();
			ll nd=ct-ddl;
			if(nd>=f.t){
				ct-=f.t;
				ans-=1ll*f.t*f.q;
			}else{
				f.t-=nd;
				pq.push(f);
				ct-=nd;
				ans-=1ll*nd*f.q;
			}
		}
		if(ddl<ct){cout<<"Bansakutsukita!\n";return;}
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
