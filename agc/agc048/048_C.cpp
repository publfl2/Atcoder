#include <stdio.h>
#include <map>

int x[100010],y[100010];
int type[100010];
std::map<int,int> check;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	x[0] = 0, y[0] = 0;
	x[a+1] = b+1, y[a+1] = b+1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>y[i]) type[i] = 1; // <<
		if(x[i]==y[i]) type[i] = 2; // --
		if(x[i]<y[i]) type[i] = 3; // >>
	}
	for(int i=1;i<a;i++)
	{
		if(type[i]==3&&type[i+1]==1)
		{
			printf("-1");
			return 0;
		}
	}
	// x[j] +(i-j) == y[i]
	long long int ans = 0;
	check[0] = 0;
	for(int i=1;i<=a;i++)
	{
		if(type[i]==1)
		{
			if(check.find(y[i]-i)==check.end())
			{
				printf("-1");
				return 0;
			}
			if(y[i-1]==y[i]-1) ans++;
			else
			{
				int k = check[y[i]-i];
				ans += (i-k);
			}
			check[x[i]-i] = i;
		}
		else if(type[i]==2)
		{
			check.clear();
			check[x[i]-i] = i;
		}
	}
	check.clear();
	
	//x[j] - (j-i) == y[i]
	check[(b+1)-(a+1)] = a+1;
	for(int i=a;i>=1;i--)
	{
		if(type[i]==3)
		{
			if(check.find(y[i]-i)==check.end())
			{
				printf("-1");
				return 0;
			}
			if(y[i+1]==y[i]+1) ans++;
			else
			{
				int k = check[y[i]-i];
				ans += (k-i);
			}
			check[x[i]-i] = i;
		}
		else if(type[i]==2)
		{
			check.clear();
			check[x[i]-i] = i;
		}
	}
	printf("%lld",ans);
}
