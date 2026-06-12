#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
void solve(){
	ll n,dbl=0,ans=0,cnt=0;
	cin>>n;
	multiset<ll>a;a.insert(0);
	for(int i=1;i<=n;i++){
		int ai;
		cin>>ai;a.insert(ai);
	}
	for(auto it=a.begin();it!=a.end();){
		if(next(it)!=a.end() && *(it)==*(next(it))){
			dbl+=2*(*it);
			it=a.erase(it);
			it=a.erase(it);
			cnt+=2;
		}
		else{it++;}
	}
	ans=dbl;
	if(a.size()>=2){
		for(auto it=a.begin();it!=a.end();it++){
			if(next(it)!=a.end() && *it+dbl>*(next(it))){
				ans=dbl+*it+*(next(it));
				if(!(cnt&1))cnt++;
			}
		}
	}
	if(cnt>=3) cout<<ans<<endl;
	else cout<<0<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
