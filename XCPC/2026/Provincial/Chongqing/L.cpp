#include<bits/stdc++.h>
using namespace std;
bool ask(vector<int>a){
    	cout<<"? "<<a.size()<<' ';
    	for(int i:a) cout<<i<<' ';
    	cout<<endl;
    	string str;
    	cin>>str;
    	return str=="YES";
}
int main(){
    	int n;
    	cin>>n;
    	int maxl=log2(n);
    	vector<int>good(maxl+1,-1),bad(maxl+1,-1);
    	for(int i=0;i<=maxl;i++){
    	    vector<int>a0,a1;
    	    for(int j=1;j<=n;j++){
    	        if(j&(1<<i)) a1.push_back(j);
    	        else a0.push_back(j);  
    	    }
    	    bool b0=ask(a0);
    	    bool b1=ask(a1);
    	    if(b0){good[i]=0;bad[i]=1;}
    	    if(b1){good[i]=1;bad[i]=0;}
    	}
    	for(int i=0;i<=maxl;i++){
    	    vector<int>a;
    	    if(good[i]!=-1) continue;
    	    for(int j=1;j<=n;j++){
    	        bool d=true;
    	        for(int k=0;k<=maxl;k++){
    	            if(good[k]==-1) continue;
    	            if(good[k]==0 && (j&(1<<k))) d=false;
    	            if(good[k]==1 && !(j&(1<<k))) d=false;
    	        }
    	        if(d&&(j&(1<<i))) a.push_back(j);
    	    }
    	    bool b=ask(a);
    	    if(b){good[i]=1;bad[i]=0;}
    	    else{good[i]=0;bad[i]=1;}
    	}
    	for(int i=maxl-1;i>=0;i--){
    	    good[i]+=2*good[i+1];
    	}
    	cout<<"! "<<good[0]<<'\n';
    	return 0;
}