#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

std::vector<int> V[110];
std::pair<int,int> edge[1010];

int check[110],check2[110];
void func(int k, int prev)
{
	if(check[k]==0) return;
	if(check2[k]) return;
	check2[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i],k);
}

long long int ans[1000010],save[1000010],ans2[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
		edge[i] = std::make_pair(c,d);
	}
	
	for(int i=1;i<(1<<a);i+=2)
	{
		for(int j=1;j<=a;j++)
		{
			if(((i>>(j-1))&1)==1) check[j] = 1;
			else check[j] = 0;
		}
		
		for(int j=1;j<=a;j++) check2[j] = 0;
		func(1,0);
		int count1, count2;
		for(int j=1;j<=a;j++) if(check[j]==1&&check2[j]==0) goto u;
		
		count1 = 0, count2 = 0;
		for(int j=1;j<=b;j++)
		{
			if(check[edge[j].first]==1 && check[edge[j].second]==1) count1++;
			if(check[edge[j].first]==0 && check[edge[j].second]==0) count2++;
		}
		
		ans[i] = power(2,count1+count2);
		//save[i] = power(2,count2);
		save[i] = 1;
		u:;
	}
	
	for(int i=0;i<(1<<a);i++)
	{
		printf("%lld ",ans[i]);
	}
	printf("\n");
	
	for(int i=0;i<(1<<a);i++)
	{
		int count = 0;
		for(int j=1;j<=a;j++) if(((i>>(j-1))&1)==1) count++;
		if(count%2==1) ans[i] *= (-1), ans[i] += MOD, ans[i] %= MOD;
	}
	
	for(int i=0;i<a;i++) for(int j=0;j<(1<<a);j++) if((j&(1<<i))!=0) ans[j] += ans[j^(1<<i)], ans[j] %= MOD;
	
	for(int i=0;i<(1<<a);i++)
	{
		int count = 0;
		for(int j=1;j<=a;j++) if(((i>>(j-1))&1)==1) count++;
		if(count%2==1) ans[i] *= (-1), ans[i] += MOD, ans[i] %= MOD;
	}
	
	for(int i=0;i<(1<<a);i++)
	{
		printf("%lld ",ans[i]);
	}
	printf("\n");
	for(int i=0;i<(1<<a);i++)
	{
		printf("%lld ",save[i]);
	}
	printf("\n");
	
	for(int i=0;i<(1<<a);i++)
	{
		for(int j=1;j<=a;j++)
		{
			if((i&(1<<(j-1)))!=0)
			{
				ans2[j] += ans[i]*save[i], ans2[j] %= MOD;
			}
		}
	}
	for(int i=2;i<=a;i++) printf("%lld\n",ans2[i]);
}