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
void solve(){
	string x;
	int k;
	cin>>x>>k;
	stack<int>y;
	for(auto it=x.rbegin();k!=0&&it!=x.rend();){
		if(*it=='0'){
			y.push(0);
			it++;
		}
		else{
			int cnt=1;
			it++;
			while(it!=x.rend()&&*it=='9'){
				it++;
				cnt++;
			}
			if(k>=cnt){
				k-=cnt;
				y.push(9);
				for(int i=1;i<=cnt-1;i++)
					y.push(0);
			}
			else{
				for(int i=1;i<=cnt-k;i++)
					y.push(0);
				y.push(9);
				for(int i=1;i<=k-1;i++)
					y.push(0);
				k=0;
			}
			if(it!=x.rend())(*it)++;
		}
	}
	if(k==0){
		while(!y.empty()&&y.top()==0)
			y.pop();
		while(!y.empty()){
			cout<<y.top();
			y.pop();
		}
	}
	else cout<<-1;
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
