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
struct point{
	int x;
	vector<int>a;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int>va;
	va.push_back(-inf);
	vector<vector<int>>a(k+1);
	vector<point>p(n+1);
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int s;
			cin>>s;
			a[i].push_back(s);
			va.push_back(s);
		}
	}
	sort(va.begin(),va.end());
	for(int i=1;i<=k;i++){
		for(int &s:a[i]){
			int ps=lower_bound(va.begin(),va.end(),s)-va.begin();
			p[ps].x=s;
			p[ps].a.push_back(i);
		}
	}
	pii r={-inf,inf};
	vector<int>c(k+1);
	int cnt=0;
	for(int i=1,j=1;j<=n;j++){
		for(int s:p[j].a){
			if(c[s]==0)cnt++;
			c[s]++;
		}
		while(cnt==k){
			if(p[j].x-p[i].x<r.second-r.first)
				r={p[i].x,p[j].x};
			for(int s:p[i].a){
				c[s]--;
				if(c[s]==0)cnt--;
			}
			i++;
		}
	}
	cout<<r.second-r.first;
	return 0;
}
