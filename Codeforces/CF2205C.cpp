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
	int n;
	cin>>n;
	vector<vector<int>>a(n+1);
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		set<int>u;
		stack<int>tmp;
		for(int j=1;j<=l;j++){
			int x;
			cin>>x;
			tmp.push(x);
		}
		while(!tmp.empty()){
			int x=tmp.top();
			tmp.pop();
			if(!u.count(x)){
				u.insert(x);
				a[i].push_back(x);
			}
		}
	}
	vector<int>ans;
	set<int>u;
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		for(int x:a[i]){
			if(!u.count(x)){
				u.insert(x);
				ans.push_back(x);
			}
		}
		for(int j=i+1;j<=n;j++){
			vector<int>tmp;
			for(int x:a[j]){
				if(!u.count(x))
					tmp.push_back(x);
			}
			a[j]=tmp;
		}
		sort(a.begin()+i+1,a.end());
	}
	for(int x:ans){
		cout<<x<<' ';
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
