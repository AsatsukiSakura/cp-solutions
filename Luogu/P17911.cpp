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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>>bt(2,vector<int>(31,0));
	for(int i=1;i<=n-1;i++){
		for(int j=30;j>=0;j--){
			int bit=(a[i]>>j)&1;
			int bitt=(a[i+1]>>j)&1;
			if(bitt>bit){bt[1][j]++;break;}
			if(bitt<bit){bt[0][j]++;break;}
		}
	}
	int tag=0;
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			if(x>1){
				for(int j=30;j>=0;j--){
					int bit=((a[x-1]^tag)>>j)&1;
					int bitt=((a[x]^tag)>>j)&1;
					if(bitt>bit){bt[1][j]--;break;}
					if(bitt<bit){bt[0][j]--;break;}
				}
				for(int j=30;j>=0;j--){
					int bit=((a[x-1]^tag)>>j)&1;
					int bitt=(y>>j)&1;
					if(bitt>bit){bt[1][j]++;break;}
					if(bitt<bit){bt[0][j]++;break;}
				}
			}
			if(x<n){
				for(int j=30;j>=0;j--){
					int bit=((a[x]^tag)>>j)&1;
					int bitt=((a[x+1]^tag)>>j)&1;
					if(bitt>bit){bt[1][j]--;break;}
					if(bitt<bit){bt[0][j]--;break;}
				}
				for(int j=30;j>=0;j--){
					int bit=(y>>j)&1;
					int bitt=((a[x+1]^tag)>>j)&1;
					if(bitt>bit){bt[1][j]++;break;}
					if(bitt<bit){bt[0][j]++;break;}
				}
			}
			a[x]=y^tag;
		}
		if(op==2){
			int x;
			cin>>x;
			tag^=x;
			for(int j=30;j>=0;j--){
				int bit=(x>>j)&1;
				if(bit)	swap(bt[0][j],bt[1][j]);
			}
		}
		if(op==3){
			int ans=0;
			for(int j=30;j>=0;j--)
				ans+=bt[1][j];
			cout<<ans<<'\n';
		}
	}
}
