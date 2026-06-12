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
int k,n;
vector<int>a;
bool check(int x){
	int sum=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(a[i]>x)return false;
		if(sum+a[i]>x){
			cnt++;
			sum=a[i];
		}
		else sum+=a[i];
	}
	return cnt<=k;
}
int binaryans(int l,int h){
	if(l>h)
		return l;
	int mid=l+(h-l)/2;
	if(check(mid))return binaryans(l,mid-1);
	else return binaryans(mid+1,h);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=binaryans(0,INT_MAX);
	cout<<ans;
	return 0;
}
