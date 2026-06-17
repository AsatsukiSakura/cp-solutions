#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int l,n,k;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n-1;i++){
    	    int dis=p[i+1]-p[i];
		cnt+=(dis+x-1)/x-1;
	}
	if(cnt<=k)	return true;
	else return false;
}
int binaryanswer(int l,int h){
	int mid=(l+h)/2;
    	if(mid==0)return 1;
	if(l>h)	return l;
	if(check(mid))	return binaryanswer(l,mid-1);
	else return binaryanswer(mid+1,h);
}
int main(){
	cin>>l>>n>>k;
	p.resize(n+2);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=binaryanswer(0,l);
    	cout<<ans;
	return 0;
}