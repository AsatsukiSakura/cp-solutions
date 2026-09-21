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
struct Node{
	int cnt=0;
	unordered_map<char,int>nxt;
};
struct Trie{
	vector<Node>tree;
	Trie(){
		tree.emplace_back();
	}
	void insert(const string &s){
		int u=0;
		for(char c:s){
			if(!tree[u].nxt.count(c)){
				tree[u].nxt[c]=tree.size();
				tree.emplace_back();
			}
			u=tree[u].nxt[c];
			tree[u].cnt++;
		}
	}
	int query(const string &s){
		int u=0;
		for(char c:s){
			if(!tree[u].nxt.count(c)){
				return 0;
			}
			u=tree[u].nxt[c];
		}
		return tree[u].cnt;
	}
};
void solve(){
	int n,q;
	cin>>n>>q;
	Trie tr;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		tr.insert(s);
	}
	for(int i=1;i<=q;i++){
		string s;
		cin>>s;
		cout<<tr.query(s)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
