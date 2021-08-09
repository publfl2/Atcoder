#include <stdio.h>
#include <algorithm>
#define MAX 1234

int a;
int max[30][30],next[30];
long long int save[20][270010];
long long int func(int k, int bit)
{
	if(k>a) return 1;
	if(save[k][bit]!=-1) return save[k][bit];
	
	int check[20] = {}, sum[20] = {}, max2[20] = {};
	int bit2 = bit;
	for(int i=1;i<=a;i++)
	{
		check[i] = bit2%2;
		bit2/=2;
	}
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + check[i];
	for(int i=1;i<=a;i++) max2[i] = max[k][i] - sum[i];
	for(int i=a-1;i>=1;i--) max2[i] = max2[i]<max2[i+1]?max2[i]:max2[i+1];
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0 && max2[i]>=1)
		{
			ans += func(k+1,bit+(1<<(i-1)));
		}
	}
	return save[k][bit] = ans;
}

struct str{
	int first;
	int second;
	int value;
}x[30];
bool cmp(str a, str b)
{
	return a.second<b.second;
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x[i]={c,d,e};
	}
	std::sort(x+1,x+b+1,cmp);
	
	for(int i=1;i<=a;i++) next[i] = b+1;
	for(int i=b;i>=1;i--) for(int j=1;j<=x[i].second;j++) next[j] = i;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) max[i][j] = MAX;
		for(int j=next[i];j<=b;j++) max[i][x[j].first] = max[i][x[j].first]<x[j].value?max[i][x[j].first]:x[j].value;
	}
	
	int c = (1<<a);
	for(int i=1;i<=a;i++) for(int j=0;j<=c;j++) save[i][j] = -1;
	printf("%lld",func(1,0));
}