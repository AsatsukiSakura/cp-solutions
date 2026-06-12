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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k,n;
	cin>>k>>n;
	vector<int>a(n+1);
	set<int>machine;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(machine.size()<k || machine.count(a[i]))
			machine.insert(a[i]);
		else{
			pii mxk={0,0};
			for(auto it=machine.begin();it!=machine.end();it++){
				int pos=inf;
				for(int j=i+1;j<=n;j++){
					if(a[j]==*it){pos=j;break;}
				}
				if(pos>mxk.second){
					mxk.first=*it;
					mxk.second=pos;
					if(pos==inf)break;
				}
			}
			machine.erase(mxk.first);
			machine.insert(a[i]);
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
