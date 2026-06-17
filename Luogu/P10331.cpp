#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    	int n;
    	string s;
    	cin>>n>>s;
    	s=" "+s;
    	string t=" ";
    	int cnt=0;
    	char c='*';
    	for(int i=1;i<=n;i++){
    	    if(s[i]!=c){
    	        if(cnt==1)t.push_back('x');
    	        else t.push_back('y');
    	        cnt=1;
    	        c=s[i];
    	    }
    	    else cnt++;
    	}
    	vector<int>dp(cnt+1);
    	for(int i=1;i<=cnt;i++){
    	    dp[i]=dp[(i+2)/3];
    	}
    	cout<<cnt-1<<' '<<dp[cnt]<<endl;
    	}
    	cout<<endl;
}
int main(){
    	int t;
    	cin>>t;
    	while(t--){
    	    solve();
    	}
}