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
	int n,k;
	cin>>n>>k;
	deque<int>mn,mx;
	vector<int>a(n+1);
	vector<int> rmn,rmx;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2-k;i<=n-k+1;i++){
		while(!mn.empty()&&mn.front()<i){
			mn.pop_front();
		}
		while(!mx.empty()&&mx.front()<i){
			mx.pop_front();
		}
		while(!mn.empty()&&a[mn.back()]>=a[i+k-1]){
			mn.pop_back();
		}
		mn.push_back(i+k-1);
		while(!mx.empty()&&a[mx.back()]<=a[i+k-1]){
			mx.pop_back();
		}
		mx.push_back(i+k-1);
		if(i>=1){
			rmx.push_back(a[mx.front()]);
			rmn.push_back(a[mn.front()]);
		}
	}
	for(auto i:rmn){
		cout<<i<<' ';
	}
	cout<<endl;
	for(auto i:rmx){
		cout<<i<<' ';
	}
	return 0;
}
