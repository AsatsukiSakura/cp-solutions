#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[55];
int dis[55][55],root[55],n,i,j; 
int find(int x) {
    while (root[x]!=x) {
        root[x]=find(root[x]);
    }
    return root[x];
}
bool check(int d){
	for(i=1;i<=n;i++){
		root[i]=i; 
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(dis[i][j]<=d && find(j)!=find(i)){
				root[find(j)]=find(i);
			}
		}
	}
	for(i=1;i<=n;i++)
		if(find(i)!=find(1))
			return false;
	return true;	
}
int binaryanswer(int l,int h){
	int mid=(l+h)/2;
	if(h<l)	return h;
	if(check(mid))	return binaryanswer(l,mid-1);
	else return binaryanswer(mid+1,h);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++)
			dis[i][j]=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
	}
	cout<<binaryanswer(0,0x3f3f3f3f);
	return 0;
} 
