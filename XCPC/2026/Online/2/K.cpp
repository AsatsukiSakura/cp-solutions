#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define debug(x) cerr<<#x<<'='<<x<<' '
void solve(){
	int n,q;
	cin>>n;
	vector<int>a(n+1);
	unordered_multiset<int>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	cin>>q;
	sort(a.begin()+1,a.end());
	int mex=0;
	for(;mex<=n;mex++){
		if(s.find(mex)==s.end())break;
	}
//	debug(mex);
	unordered_map<int,int>mp;
	for(int i=1;i<=n;i++){
		int k=mex+a[i];
		if(k<0)continue;
		int kmex=0;
		vector<int>cnt(2*n+1,0);
		for(int j=1;j<=n;j++){
			if(0<=a[j] && a[j]<=2*n){
				cnt[a[j]]++;
			}else if(0<=(k-a[j])&&(k-a[j])<=2*n){
				cnt[k-a[j]]++;
			}
		}
		for(;kmex<=2*n;kmex++){
			//debug(kmex);debug(ns.count(0))<<'\n';
			if(cnt[kmex]){
				cnt[kmex]--;
			}else if((k-kmex)<=2*n &&(k-kmex)>=0&&cnt[k-kmex])cnt[k-kmex]--;
			else break;
		}
		kmex=max(mex,kmex);
		mp[k]=kmex;
	//	debug(k);debug(kmex);
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		int k;
		cin>>k;
		if(mp.count(k)){
			ans^=mp[k];
		}
		else ans^=mex;
	//	cerr<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)solve();
}
