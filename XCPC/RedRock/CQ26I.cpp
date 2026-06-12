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
struct flower{
	int a,b;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k,n;
	cin>>n>>k;
	vector<flower>f(n+1);
	for(int i=1;i<=n;i++)cin>>f[i].a;
	for(int i=1;i<=n;i++)cin>>f[i].b;	
	auto cb=[](flower x,flower y){
		return x.b>y.b;
	};
	auto ca=[](flower x,flower y){
		return x.a<y.a;
	};
	sort(f.begin()+1,f.end(),cb);
	priority_queue<flower,vector<flower>,decltype(ca)>pq(ca);
	ll ans=0;
	for(int t=k,i=1;t>=1;t--){
		while(i<=n&&f[i].b>=t){
			pq.push(f[i]);
			i++;
		}
		if(!pq.empty()){
			ans+=pq.top().a;
			pq.pop();
		}
		else{cout<<-1;return 0;}
	}
	cout<<ans;
	return 0;
}
