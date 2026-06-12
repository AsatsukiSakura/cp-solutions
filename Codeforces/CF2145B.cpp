#include<bits/stdc++.h>
#define ll long long
const ll mod=998244353;
using namespace std;
void solve(){
	int i,n,k,p[200005],u=0,d=0,v=0;
	memset(p,-1,sizeof(p));
	string s;
	cin>>n>>k;
	for(i=1;i<=k;i++){
		cin>>s[i];
		if(s[i]=='0')	u++;
		if(s[i]=='1')	d++;
		if(s[i]=='2')	v++;
	}
	for(i=1;i<=u;i++)
		p[i]=1;
	for(i=n;i>=n-d+1;i--)
		p[i]=1;
    if(v==n-u-d)
        for(i=1;i<=n;i++)
            p[i]=1;
    else{
        for(i=u+1;i<=u+v;i++)
            p[i]=0;
        for(i=n-d;i>=n-d-v+1;i--)
            p[i]=0;
    }
	for(i=1;i<=n;i++){
		if(p[i]==-1) cout<<'+';
		if(p[i]==0) cout<<'?';
		if(p[i]>=1) cout<<'-';
	}
	cout<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
