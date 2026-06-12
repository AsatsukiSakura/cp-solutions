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
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<int>b(m+1),c(m+1);
	vector<pii>nz,z;
	multiset<int>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	int maxa=*max_element(a.begin()+1,a.end());
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		if(c[i]==0){
			z.push_back({b[i],c[i]});
		}
		else{
			nz.push_back({b[i],c[i]});
		}
	}
	sort(nz.begin(),nz.end());
	sort(z.begin(),z.end());
	int cnt=0;
	for(auto it=nz.begin();it!=nz.end();it++){
		auto sit=s.lower_bound(it->first);
		if(sit!=s.end()){
			int u=*sit;
			s.erase(sit);
			s.insert(max(it->second,u));
			cnt++;
		}
		else break;
	}
	for(auto it=z.begin();it!=z.end()&&!s.empty();it++){
		auto sit=s.lower_bound(it->first);
		if(sit!=s.end()){
			s.erase(sit);
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
