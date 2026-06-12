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
	int n;
	cin>>n;
	vector<int>pos(n+1),num(n+1);
	for(int i=1;i<=n;i++){
		cin>>pos[i]>>num[i];
	}
	auto vp=pos,vn=num;
	sort(vp.begin()+1,vp.end());
	sort(vn.begin()+1,vn.end());
	vn.erase(unique(vn.begin()+1,vn.end()),vn.end());
	int tp=vn.size()-1;
	vector<pii>p(n+1);
	for(int i=1;i<=n;i++){
		int ps=lower_bound(vp.begin()+1,vp.end(),pos[i])-vp.begin();
		int nm=lower_bound(vn.begin()+1,vn.end(),num[i])-vn.begin();
		p[ps].first=pos[i];
		p[ps].second=nm;
	}
	vector<int>c(n+1,0);
	int cnt=0;
	pii r={-inf,inf};
	for(int i=1,j=1;j<=n;j++){
		if(c[p[j].second]==0)cnt++;
		c[p[j].second]++;
		while(cnt==tp){
			if(p[j].first-p[i].first<r.second-r.first)
				r={p[i].first,p[j].first};
			c[p[i].second]--;
			if(c[p[i].second]==0)cnt--;
			i++;
		}
	}
	cout<<r.second-r.first;
	return 0;
}
