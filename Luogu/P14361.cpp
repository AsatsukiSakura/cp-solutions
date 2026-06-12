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
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>a(n+1,vector<int>(4));
	vector<vector<int>>mbs(4);
	ll fav=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int group=distance(a[i].begin(),max_element(a[i].begin()+1,a[i].end()));
		int diff=inf;
		for(int j=1;j<=3;j++){
			if(j==group)continue;
			diff=min(diff,a[i][group]-a[i][j]);
		}
		fav+=*max_element(a[i].begin()+1,a[i].end())*1ll;
		mbs[group].push_back(diff);
	}
	if(mbs[1].size()<=n/2&& mbs[2].size()<=n/2&& mbs[3].size()<=n/2){
		cout<<fav<<endl;return;
	}
	vector<int>sizes={-inf,(int)mbs[1].size(),(int)mbs[2].size(),(int)mbs[3].size()};
	int ms=distance(sizes.begin(),max_element(sizes.begin()+1,sizes.end()));
	sort(mbs[ms].begin(),mbs[ms].end(),cmp);
	while(mbs[ms].size()>n/2){
		fav-=mbs[ms].back();
		mbs[ms].pop_back();
	}
	cout<<fav<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
