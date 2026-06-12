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
	priority_queue<int>pqmax;
	priority_queue<int,vector<int>,greater<int>>pqmin;
	int n,m;
	cin>>m>>n;
	vector<int>a(m+1),u(n+1);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>u[i];
	}
	int j=0;
	for(int i=1;i<=m;i++){
		pqmax.push(a[i]);
		pqmin.push(pqmax.top());
		pqmax.pop();
		while(u[j+1]==i){
			while(pqmax.size()<j){
				pqmax.push(pqmin.top());
				pqmin.pop();
			}
			j++;
			cout<<pqmin.top()<<endl;
		}
	}
	return 0;
}
