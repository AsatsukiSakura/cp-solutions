#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[114514],n,i,l=1e9+7,r=-8848,cnt=0;
    	cin>>n;
	for(i=1;i<=n;i++)	cin>>a[i];
	for(i=1;i<=n;i++)
		if(a[i]==1){l=i;break;}
	for(i=n;i>=1;i--)
		if(a[i]==1)	{r=i;break;}
	if(l>r){
		for(i=1;i<=n;i++)
			if(a[i]==2)	{l=i;break;}
		for(i=l;i<=n;i++)
			if(a[i]==3){cout<<2;return 0;}
		cout<<1;return 0;
	}
	for(i=l;i<=r;i++)
		if(a[i]==1)	cnt++;
	for(i=l;i>=1;i--)
		if(a[i]==2)	{cnt++;break;}
	for(i=r;i<=n;i++)
		if(a[i]==3)	{cnt++;break;}
	cout<<cnt;return 0;
}