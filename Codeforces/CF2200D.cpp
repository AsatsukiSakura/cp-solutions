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
	int n,x,y;
	cin>>n>>x>>y;
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)cin>>p[i];
	int l=y-x;
	vector<int>out;
	for(int i=1;i<=n;i++){
		if(i<=x||i>=y+1)out.push_back(p[i]);
	}
	vector<int>in;
	for(int i=x+1;i<=y;i++)in.push_back(p[i]);
	int idx=min_element(in.begin(),in.end())-in.begin();
	vector<int>in1;
	for(int i=0;i<=l-1;i++){
		in1.push_back(in[(idx+i)%l]);
	}
	if(out.empty()||in1<out){
		for(int x:in1)cout<<x<<' ';
		for(int x:out)cout<<x<<' ';
	}
	else{
		bool b=true;
		for(int x:out){
			if(!in1.empty()&&x>in1[0]&&b){
				b=false;
				for(int y:in1)cout<<y<<' ';
			}
			cout<<x<<' ';
		}
		if(b){
			for(int y:in1)cout<<y<<' ';
		}
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
