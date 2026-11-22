#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
#define debug(x) cerr<<#x<<'='<<x<<' '
const int inf=1e18;
struct Matrix{
	int sz;
	vector<vector<int>>num;
	Matrix(int n){
		sz=n;
		num.resize(n+1,vector<int>(n+1,-inf));
	}
	void e(){
		for(int i=0;i<=sz;i++)
			this->num[i][i]=0;
	}
	Matrix operator*(const Matrix &b){
		Matrix res(sz);
		res.e();
		for(int i=0;i<=sz;i++)
			for(int j=0;j<=sz;j++)
				for(int k=0;k<=sz;k++){
					res.num[i][j]=max(res.num[i][j],
						this->num[i][k]+b.num[k][j]);
				}
		return res;
	}
	Matrix pow(int p){
		Matrix res(sz);
		res.e();
		Matrix base=*this;
		while(p){
			if(p&1)
				res=res*base;
			base=base*base;
			p>>=1;
		}
		return res;
	}
};
void solve(){
	int n,m,k,r;
	cin>>n>>m>>k>>r;
	int N=1<<n;
	N--;
	vector<int>a(n+1,0),c(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	Matrix X(N);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			int cost=0;
			int damage=0;
			for(int b=n-1;b>=0;b--){
				int now=(i>>b)&1;
				int pre=(j>>b)&1;
				if(pre+now==2){
					cost+=c[b+1]+k;
					damage+=a[b+1];
				}
				else if(now==1){
					cost+=c[b+1];
					damage+=a[b+1];
				}
			}
			if(cost<=m){
				X.num[i][j]=damage;
			}
			//debug(i),debug(j),debug(X.num[i][j])<<'\n';
		}
		
	}
	X=X.pow(r);
	int ans=0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++)
			ans=max(ans,X.num[i][j]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
