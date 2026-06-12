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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<int>dq;
	for(int i=1-k;i<=n-k;i++){
		while(!dq.empty() && a[dq.back()]<a[i+k]){
			dq.pop_back();
		}
		dq.push_back(i+k);
		while(!dq.empty()&&dq.front()<=i){
			dq.pop_front();
		}
		if(i>=0){
			cout<<a[dq.front()]<<' ';
		}
	}
	return 0;
}
