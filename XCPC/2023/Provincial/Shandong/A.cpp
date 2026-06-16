#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
using pii=pair<int,int>;
void solve(){
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
			for(int k=1;k<=6;k++){
				int r=0,b=0;
				if(i==1||i==4)r+=i;
				else b+=i;
				if(j==1||j==4)r+=j;
				else b+=j;
				if(k==1||k==4)r+=k;
				else b+=k;
				if(r==x&&b==y){cout<<"Yes\n";return;}
			}
	cout<<"No\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;t=1;
	while(t--)solve();
}
