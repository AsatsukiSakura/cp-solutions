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
	cin>>n;
	vector<int>p(n+1),premin(n+1,inf),sufmax(n+2,-inf);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
		premin[i]=min(premin[i-1],p[i]);
	for(int i=n;i>=1;i--)
		sufmax[i]=max(sufmax[i+1],p[i]);
	for(int i=1;i<=n-1;i++){
		if(premin[i]>sufmax[i+1]){
			cout<<"No"<<endl;return;
		}
	}
	cout<<"Yes"<<endl;
	set<int>s;
	for(int i=1;i<=n;i++){
		if(s.empty()){
			s.insert(p[i]);
		}
		else if(!s.empty()&&p[i]<*s.begin()){
			s.insert(p[i]);
		}
		else {
			auto it=s.upper_bound(p[i]);
			it--;
			while(1){
				cout<<*it<<' '<<p[i]<<endl;
				if(it==s.begin())break;
				auto nit=prev(it);
				s.erase(it);
				it=nit;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
