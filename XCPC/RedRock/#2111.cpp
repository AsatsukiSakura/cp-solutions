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
struct person{
	int id,nx,ny,hx,hy;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,x,y;
	cin>>n>>x>>y;
	auto cx=[](person a,person b){
		return a.nx>b.nx;
	};
	auto cy=[](person a,person b){
		return a.ny>b.ny;
	};
	priority_queue<person,vector<person>,decltype(cx)>px(cx);
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		px.push({i,a,b,c,d});
	}
	vector<int>ans;
	priority_queue<person,vector<person>,decltype(cy)>py(cy);
	while(!px.empty()||!py.empty()){
		int cnt=0;
		while(!px.empty()&&x>=px.top().nx){
			py.push(px.top());
			px.pop();
			cnt++;
		}
		if(py.empty()||y<py.top().ny){
			cout<<"NO";return 0;
		}
		while(!py.empty()&&y>=py.top().ny){
			x+=1ll*py.top().hx;
			y+=1ll*py.top().hy;
			ans.push_back(py.top().id);
			py.pop();
		}
	}
	cout<<"YES\n";
	for(int i:ans)cout<<i<<' ';
	return 0;
}
