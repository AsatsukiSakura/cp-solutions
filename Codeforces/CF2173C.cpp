#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<endl
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
void solve(){
	set<pii>s;
	/*a prime and its multiples appers time must be
	at least floor(k/p) times means
	it can be in the B
	otherwise it cannot.
	*/
	set<int>res;
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert({a[i],0});
	}
	while(!s.empty()){
		int p=(*s.begin()).first;
		if((*s.begin()).second==0){
			for(int i=p;i<=k;i+=p){
				if(s.count({i,0})||s.count({i,1})){
					debug(i);
					s.erase({i,0});
					s.insert({i,1});
				}
				else{
					debug(i);
					cout<<-1<<endl;return;
				}
			}	
			res.insert(p);
		}
		s.erase(s.begin());
	}
	cout<<res.size()<<endl;
	for(auto it=res.begin();it!=res.end();it++){
		cout<<*it<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
