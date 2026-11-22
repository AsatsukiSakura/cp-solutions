#include<bits/stdc++.h>
using namespace std;
int main(){
	double ans=0;
	int cnt=0;
	vector<double>a(9,0),b(9,0);
	for(int i=1;i<=8;i++)cin>>a[i]>>b[i];
	vector<int>seed={0,1,2,3,4,5,6,7,8};
	do{
		vector<vector<double>>winr(9,vector<double>(9,0));
		for(int i=1;i<=8;i++){
			for(int j=i+1;j<=8;j++){
				if(seed[i]<seed[j])winr[i][j]=a[i]/(a[i]+b[j]);
				else winr[i][j]=b[i]/(b[i]+a[j]);
				winr[j][i]=1-winr[i][j];
				
			}
		}
		vector<int>rseed(9);
		for(int i=1;i<=8;i++)rseed[seed[i]]=i;
		double pos=0;
		for(int q1=1;q1<=2;q1++){
			for(int q2=3;q2<=4;q2++){
				for(int q3=5;q3<=6;q3++){
					for(int q4=7;q4<=8;q4++){						
						double tmp=1;
						tmp*=winr[rseed[q1]][rseed[q1+((q1&1)?1:-1)]];
						tmp*=winr[rseed[q2]][rseed[q2+((q2&1)?1:-1)]];
						tmp*=winr[rseed[q3]][rseed[q3+((q3&1)?1:-1)]];
						tmp*=winr[rseed[q4]][rseed[q4+((q4&1)?1:-1)]];
						vector<int>up={q1,q2};
						vector<int>dn={q3,q4};						
						for(int i=0;i<=1;i++){
							for(int j=0;j<=1;j++){
								double ttmp=tmp;
								//cerr<<"yyy"<<endl;
								ttmp*=winr[rseed[up[i]]][rseed[up[i+((i&1)?-1:1)]]];
								ttmp*=winr[rseed[dn[j]]][rseed[dn[j+((j&1)?-1:1)]]];
								vector<int>fin={up[i],dn[j]};				
								//cerr<<"yyy"<<endl;
								for(int k=0;k<=1;k++){
									double tttmp=ttmp;
									tttmp*=winr[rseed[fin[k]]][rseed[fin[k+((k&1)?-1:1)]]];
									//if(q1==1)cerr<<tttmp<<endl;
									if(rseed[fin[k]]==1)pos+=tttmp;
								}
							}
						}
					}
				}
			}
		}
		ans=max(pos,ans);
		cnt++;
	}while(next_permutation(seed.begin()+1,seed.end()));
	//cerr<<cnt<<endl;
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}
