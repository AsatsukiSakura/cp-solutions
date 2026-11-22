#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b,p[505][505];
void solve(){
	cin>>n>>m>>a>>b;
	vector<int> cnt((n+5)*(m+5),0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
			cnt[p[i][j]]++;
		}
	}
	sort(cnt.begin()+1,cnt.end(),greater<int>());
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(cnt[i]==0)
			break;
		ans+=min(a*cnt[i],b*((i-1)*cnt[i]+cnt[0]));
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*
3 3 6 4
1 2 3
4 4 4
4 4 4

3 3 6 3
1 2 3
4 4 4
4 4 4
*/
