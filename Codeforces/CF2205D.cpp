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
void solve(){
	int n;
	cin>>n;
	vector<int>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	/*
	单调栈
	找出每个元素左边最大和右边最大
	把数组看作一个树
	一个元素左边小的部分在左子树 右边的部分在右子树
	结果就相当于保留一条链 剩下全删掉
	*/
	stack<int>st;
	vector<int>lb(n+1,0),rb(n+1,inf);
	for(int i=1;i<=n;i++){
		while(!st.empty()&&p[i]>p[st.top()]){
			rb[st.top()]=i;
			st.pop();
		}
		if(!st.empty())lb[i]=st.top();
		st.push(i);
	}
	vector<int>lc(n+1,0),rc(n+1,0);
	int root;
	for(int i=1;i<=n;i++){
		if(lb[i]==0&&rb[i]==inf)root=i;
		else if(lb[i]==0)lc[rb[i]]=i;
		else if(rb[i]==inf)rc[lb[i]]=i;
		else{
			if(p[lb[i]]<p[rb[i]])rc[lb[i]]=i;
			else lc[rb[i]]=i;
		}
	}
	queue<int>q;
	vector<int>l(n+1);
	l[root]=1;
	q.push(root);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(lc[u]!=0){
			q.push(lc[u]);
			l[lc[u]]=l[u]+1;
		}
		if(rc[u]!=0){
			q.push(rc[u]);
			l[rc[u]]=l[u]+1;
		}
	}
	cout<<n-*max_element(l.begin()+1,l.end())<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
