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
struct item{
	int value,weight;
	bool z;
	item(int vv,int ww,bool zz){
		value=vv;weight=ww;z=zz;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char c,d;
	int hs,ms,he,me,n;
	cin>>hs>>c>>ms>>he>>d>>me>>n;
	int t=(he-hs)*60+(me-ms);
	cout<<t;
	vector<item>a;
	a.push_back(item(0,0,false));
	for(int i=1;i<=n;i++){
		int weight,value,p;
		cin>>weight>>value>>p;
		if(p==0)a.push_back(item(value,weight,true));
		else{
			int k=1;
			while(k<=p){
				a.push_back(item(k*value,k*weight,false));
				p-=k;
				k*=2;
			}
			if(p!=0) a.push_back(item(p*value,p*weight,false));
		}
	}
	vector<int>dp(t+1,0);
	for(int i=1;i<=a.size()-1;i++){
		if(a[i].z){
			for(int j=a[i].weight;j<=t;j++){
				dp[j]=max(dp[j],dp[j-a[i].weight]+a[i].value);
			}
		}
		else{
			for(int j=t;j>=a[i].weight;j--){
				dp[j]=max(dp[j],dp[j-a[i].weight]+a[i].value);
			}
		}
	}
	cout<<dp[t];
	return 0;
}
