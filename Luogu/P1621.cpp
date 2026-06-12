#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces::AsatsukiSakura
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
vector<int>root;
int find(int x){
	if(root[x]==x)return x;
	else return root[x]=find(root[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b,pp;
	cin>>a>>b>>pp;
	vector<int>elem(b-a+1);
	root.resize(b-a+1);
	iota(root.begin(),root.end(),0);
	iota(elem.begin(),elem.end(),a);
	vector<int>primes;
	vector<int>spf(1e5+1);
	iota(spf.begin(),spf.end(),0);
	for(int i=2;i<=1e5;i++){
		if(spf[i]==i)	primes.push_back(i);
		for(int p:primes){
			if(i*p>1e5)break;
			spf[i*p]=p;
			if(spf[i]==p)break;
		}
	}
	for(int p:primes){
		if(p>b)break;
		if(p<pp)continue;
		for(int j=((a+p-1)/p)*p;j<=b;j+=p){
			if(j+p<=b){
				root[find(j+p-a)]=find(j-a);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<=b-a;i++){
		if(find(i)==i){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
