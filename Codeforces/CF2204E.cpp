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
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s<<'\n';
		return;
	}
	vector<int>cnt(10,0);
	/*过程:x0->x1->x2->x3->xend
	总位数和=x1+x2+x3+....+xend+xend*/
	int tots=0;
	for(char &c:s){
		tots+=c-'0';
		cnt[c-'0']++;
	}
	//x1<=900000 x2<=54 x3<=13 x4<=4...
	for(int x1=max(1,tots-100);x1<=tots;x1++){
		vector<int>seq;
		int x=x1;
		int sum=x1;
		while(1){
			seq.push_back(x);
			if(x<=9){
				sum+=x;
				break;
			}
			int nx=0;
			int tmp=x;
			while(tmp){
				nx+=tmp%10;tmp/=10;
			}
			x=nx;
			sum+=x;
		}
		if(sum==tots){
			vector<int>nd(10,0);
			for(int val:seq){
				string tmp=to_string(val);
				for(char c:tmp)nd[c-'0']++;
			}
			bool b=true;
			for(int i=0;i<=9;i++)if(cnt[i]<nd[i])b=false;
			if(b){
				for(int i=0;i<=9;i++)cnt[i]-=nd[i];
				string ans;
				for(int i=9;i>=0;i--){
					ans+=string(cnt[i],i+'0');
				}
				for(int val:seq){
					ans+=to_string(val);
				}
				cout<<ans<<'\n';
				return;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
