#include<bits/stdc++.h>
using namespace std;
//QQ:3208554058
//bilibili:111268933
//luogu:225671
//codeforces:AsatsukiSakura
#define debug(x) cerr<<#x<<'='<<x<<' '
using ll=long long;
using pii=pair<int,int>;
const ll mod=998244353;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q;
	cin>>Q;
	priority_queue<int>maxqp;//小的
	priority_queue<int,vector<int>,greater<int>>minqp;//大的
	while(Q--){
		char op;
		cin>>op;
		if(op=='?'){
			cout<<maxqp.top()<<endl;
		}
		else{
			int x;
			cin>>x;
			if(maxqp.empty()||x<=maxqp.top())
			{	maxqp.push(x);	}
			else{ minqp.push(x);}
		}
		if(minqp.size()>maxqp.size()){
			maxqp.push(minqp.top());
			minqp.pop();
		}
		if(maxqp.size()>minqp.size()+1){
			minqp.push(maxqp.top());
			maxqp.pop();
		}
	}
	return 0;
}
/*
12
+1
?
+2
?
+1
?
+2
?
+1
?
+2
?
*/
