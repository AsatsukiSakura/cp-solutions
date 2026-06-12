#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e8;
const ll inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string x,y;
	cin>>x>>y;
	x.pop_back();y.pop_back();
	if(x.size()<y.size())swap(x,y);
	vector<int>lcs(y.size()+1,0),t1(y.size()+1,0);
	vector<ll>lcscnt(y.size()+1,0),t2(y.size()+1,1);
	for(int i=1;i<=x.size();i++){
		for(int j=1;j<=y.size();j++){
			if(x[i-1]==y[j-1])lcs[j]=t1[j-1]+1;
			else lcs[j]=max(lcs[j-1],t1[j]);
		}
		lcscnt.assign(y.size()+1,0);
		lcscnt[0]=1;
		for(int j=1;j<=y.size();j++){
			if(x[i-1]==y[j-1])lcscnt[j]+=t2[j-1]%mod;			
			if(lcs[j]==t1[j])lcscnt[j]+=t2[j];
			if(lcs[j]==lcs[j-1])lcscnt[j]+=lcscnt[j-1];
			if(lcs[j]==t1[j-1])lcscnt[j]-=t2[j-1];
			lcscnt[j]%=mod;
			lcscnt[j]+=mod;
			lcscnt[j]%=mod;
		}
		t1=lcs;
		t2=lcscnt;
	}
	cout<<lcs[y.size()]<<endl<<lcscnt[y.size()];
	return 0;
}
