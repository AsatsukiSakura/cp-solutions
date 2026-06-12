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
	int n;
	cin>>n;
	vector<vector<bool>>b(n+1,vector<bool>(n+1,true));
	vector<vector<bool>>v(n+1,vector<bool>(n+1,false));
	for(int i=1;i<=2*n-2;i++){
		int x,y;
		cin>>x>>y;
		if(x+y-2>i)
			b[x][y]=false;
	}
	queue<pii>q;
	q.push({1,1});v[1][1]=true;
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		if(x+1<=n&& !v[x+1][y]&&b[x+1][y]){
			q.push({x+1,y});v[x+1][y]=true;
		}
		if(x-1>=1&& !v[x-1][y]&&b[x-1][y]){
			q.push({x-1,y});v[x-1][y]=true;
		}
		if(y-1>=1&& !v[x][y-1]&&b[x][y-1]){
			q.push({x,y-1});v[x][y-1]=true;
		}
		if(y+1>=1&& !v[x][y+1]&&b[x][y+1]){
			q.push({x,y+1});v[x][y+1]=true;
		}
	}
	cout<<(v[n][n]?"Yes":"No")<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
