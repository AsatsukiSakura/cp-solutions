#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<"="<<x<<endl
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<vector<int>>a(n+1,vector<int>(n+1,0));
	vector<pair<pii,pii>>ap(n*n+1,{{inf,inf},{-inf,-inf}});
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ap[a[i][j]].first.first=min(ap[a[i][j]].first.first,i);
			ap[a[i][j]].first.second=min(ap[a[i][j]].first.second,j);
			ap[a[i][j]].second.first=max(ap[a[i][j]].second.first,i);
			ap[a[i][j]].second.second=max(ap[a[i][j]].second.second,j);
		}
	}
	int cnt=0;
	vector<vector<ll>>d(n+2,vector<ll>(n+2,0));
	for(int i=1;i<=n*n;i++){
		if(ap[i].first.first<=n && ap[i].second.second>=0){
			cnt++;
			d[ap[i].first.first][ap[i].first.second]++;
			d[ap[i].second.first+1][ap[i].second.second+1]++;
			d[ap[i].first.first][ap[i].second.second+1]--;
			d[ap[i].second.first+1][ap[i].first.second]--;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]+=d[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]+=d[i-1][j];
	vector<bool>z(n*n+1,true);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]>1)
				z[a[i][j]]=false;
		}
	}
	int ans=0;
	for(int i=1;i<=n*n;i++){
		ans+=z[i];
	}
	cout<<ans-(cnt==1);
	return 0;
}
