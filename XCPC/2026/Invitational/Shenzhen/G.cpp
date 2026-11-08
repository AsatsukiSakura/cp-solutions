#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,dx,dy;
const int N=1100;
char a[N][N];
void dfs(int x,int y){
	if(n%2==0){
		while(1){
			if(x==1&&y==2){
				a[x][y]='L';
				y--;
				while(x<n){
					a[x][y]='D';
					x++;
				}
				a[x][y]='R';
				return ;
			}
			if(x%2==0){
				if(y<m){
					a[x][y]='R';
					y++;
					continue;
				}
				else{
					a[x][y]='U';
					x--;
					continue;
				}
			}
			else{
				if(y>2){
					a[x][y]='L';
					y--;
					continue;
				}
				else{
					a[x][y]='U';
					x--;
					continue;
				}
			}
		}
	}
	if(m%2==0){
		x=2,y=1;
		while(1){
			if(x==2&&y==m){
				a[x][y]='U';
				x--;
				while(y>1){
					a[x][y]='L';
					y--;
				}
				a[x][y]='D';
				return ;
			}
			if(y%2==1){
				if(x<n){
					a[x][y]='D';
					x++;
				}
				else{
					a[x][y]='R';
					y++;
				}
			}
			else{
				if(x>2){
					a[x][y]='U';
					x--;
				}
				else{
					a[x][y]='R';
					y++;
				}
			}
		}
	}
	else{
		a[n][m]='U';
		x=n,y=2;
		while(y<m){
			if(y%2==0){
				a[x][y]='U';
				x--;
				a[x][y]='R';
				y++;
			}
			else{
				a[x][y]='D';
				x++;
				a[x][y]='R';
				y++;
			}
		}
		a[n-1][m]='U';
		x=n-1,y=m;
//		cout<<"xy:"<<x<<" "<<y<<endl;
		a[x][y]='U';
		x--;
		while(1){
			if(x==1&&y==2){
				a[x][y]='L';
				y--;
				while(x<n){
					a[x][y]='D';
					x++;
				}
				a[x][y]='R';
				return ;
			}
			if(x%2==1){
				if(y>2){
					a[x][y]='L';
					y--;
				}
				else{
					a[x][y]='U';
					x--;
				}
			}
			else{
				if(y<m){
					a[x][y]='R';
					y++;
				}
				else{
					a[x][y]='U';
					x--;
				}
			}
		}
	}
}
void work(){
	cin>>n>>m>>dx>>dy;
	dfs(n,2);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=n*m-1;i++){
		int tx,ty;
		cin>>tx>>ty;
//		cout<<n<<" "<<m<<" "<<dx<<" "<<dy<<endl;
		while(dx!=tx||dy!=ty){
			if(n%2==1&&m%2==1){
//				cout<<"now"<<dx<<" "<<dy<<endl;
				if(dx==n&&dy==m-1){
					if(tx==n-1&&ty==m-1){
						cout<<'U';
						dx=tx,dy=ty;
						continue;
					}
					if(tx==n&&ty==m){
						cout<<'R';
						dx=tx,dy=ty;
						continue;
					}
				}
				cout<<a[dx][dy];
				if(a[dx][dy]=='L')dy--;
				else if(a[dx][dy]=='R')dy++;
				else if(a[dx][dy]=='U')dx--;
				else dx++;
			}
			else{
				cout<<a[dx][dy];
				if(a[dx][dy]=='L')dy--;
				else if(a[dx][dy]=='R')dy++;
				else if(a[dx][dy]=='U')dx--;
				else dx++;
			}
		}
		cout<<endl;
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}
