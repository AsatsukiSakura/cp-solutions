#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll inf=0x3f3f3f3f;
void solve(){
	int n;
	string s,x;
	cin>>n;
	vector<int>p(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	x.resize(n+1,'0');
	cin>>s;
	s=' '+s;
	int ooo=0;
	for(int i=1;i<=n;i++){
		ooo+=(s[i]-'0');
	}
	if(ooo==0){
		cout<<0<<endl;return;
	}
	if(s[1]=='1' || s[n]=='1'){
		cout<<-1<<endl;return;
	}
	int maxidx=distance(p.begin(),max_element(p.begin()+1,p.end()));
	int minidx=distance(p.begin(),min_element(p.begin()+1,p.end()));
	if(s[maxidx]=='1' || s[minidx]=='1'){
		cout<<-1<<endl;return;
	}
	for(int i=2;i<maxidx;i++){
		if(p[i]<p[maxidx]&&p[i]>p[1])x[i]='1';
	}
	for(int i=2;i<minidx;i++){
		if(p[i]>p[minidx]&&p[i]<p[1])x[i]='1';
	}
	for(int i=maxidx+1;i<n;i++){
		if(p[i]<p[maxidx]&&p[i]>p[n])x[i]='1';
	}
	for(int i=minidx+1;i<n;i++){
		if(p[i]>p[minidx]&&p[i]<p[n])x[i]='1';
	}
	for(int i=min(minidx,maxidx);i<max(minidx,maxidx);i++){
		if(p[i]>p[minidx]&&p[i]<p[maxidx])x[i]='1';
	}
	for(int i=1;i<=n;i++){
		if(x[i]=='0'&&s[i]=='1'){
			cout<<-1<<endl;return;
		}
	}
	cout<<5<<endl;
	cout<<1<<' '<<minidx<<endl;
	cout<<1<<' '<<maxidx<<endl;
	cout<<maxidx<<' '<<n<<endl;
	cout<<minidx<<' '<<n<<endl;
	cout<<min(minidx,maxidx)<<' '<<max(minidx,maxidx)<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
