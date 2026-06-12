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
int ask(int i,int x){
	cout<<'?'<<' '<<i<<' '<<x<<endl;
	int ans;
	cin>>ans;
	return ans;
}
void solve(){
	int n;
	cin>>n;
	vector<int>q,q0,q1,nums(n),temp;
	int last=0;
	iota(nums.begin(),nums.end(),1);
	for(int i=1;i<=n-1;i++){
		q.push_back(i);
	}
	for(int i=0;i<=log2(n-1);i++){
		q0.clear();
		q1.clear();
		temp.clear();
		int ct=0,cnt=0;
		for(int j:nums){
			ct+=(j&(1<<i))/(1<<i);
		}
		for(int j:q){
			int ans=ask(j,(1<<i));
			if(ans){
				q1.push_back(j);
				cnt++;
			}
			else
				q0.push_back(j);
		}
		if(cnt==ct){
			q=q0;
			for(int j:nums){
				if(!(j&(1<<i))){
					temp.push_back(j);
				}
			}
		}
		else{
			q=q1;
			last+=(1<<i);
			for(int j:nums){
				if(j&(1<<i)){
					temp.push_back(j);
				}
			}
		}
		nums=temp;
	}
	if(last==0)last=n;
	cout<<'!'<<' '<<last<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
