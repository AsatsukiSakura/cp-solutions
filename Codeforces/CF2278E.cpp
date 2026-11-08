#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1,0);
	ll s=0;
	int k=(n+1)>>1;
	vector<int>b(n+1,0);
	for(int i=1,c=-1;i<=n;i++,c*=-1){
		cin>>a[i];
		b[i]=c*a[i];
	}
	sort(b.begin()+1,b.end());
	for(int i=1;i<=k;i++){
		s+=b[i];
	}
	s=-s;
	for(int i=k+1;i<=n;i++){
		s+=b[i];
	}
	cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
