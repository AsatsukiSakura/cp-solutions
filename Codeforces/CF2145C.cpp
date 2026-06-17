#include<bits/stdc++.h>
#define ll long long
const ll mod=998244353;
using namespace std;
void solve(){
	int i,n,k,p[200005],pre[200005],v=0,ans=0x3f3f3f3f;
	map<int,int> ny;
	for(i=-200005;i<=200005;i++) 
    		ny[i]=-0x3f3f3f3f;
	string s;
	cin>>n>>k;
	pre[0]=0;
	for(i=1;i<=k;i++){
		cin>>s[i];
		if(s[i]=='a'){
			v++;pre[i]=pre[i-1]+1;
		}
		if(s[i]=='b'){
			v--;pre[i]=pre[i-1]-1;
		}
	}
	if(v==0){cout<<0;return;}
	for(i=1;i<=n;i++){
		ny[pre[i]]=i;
		ans=min(ans,i-ny[pre[i]-v]);
	}
	if(ans==0x3f3f3f3f)	ans=-1;
	cout<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
