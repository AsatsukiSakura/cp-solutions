#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[5010][5010],sum[5010],mod=1e9+7;
vector<int> a[5010],g[5010];
void dfs(int now,int fa)
{
	for(int i=0;i<a[now].size();++i)
		f[now][a[now][i]]=1;
	if(now!=1&&g[now].size()==1)
	{
		sum[now]=a[now].size();
		return;
	}
	for(int i=0;i<g[now].size();++i)
	{
		int v=g[now][i];
		if(v==fa)
			continue;
		dfs(v,now);
		for(int j=0;j<a[now].size();++j)
			f[now][a[now][j]]=(f[now][a[now][j]]*((sum[v]-f[v][a[now][j]]+mod)%mod))%mod;
	}
	for(int i=0;i<a[now].size();++i)
		sum[now]=(sum[now]+f[now][a[now][i]])%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int k,x;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld",sum[1]);
	return 0;
}
