#include <stdio.h>
#include <vector>
#include <algorithm>
int x[200010],y[200010],ans[200010],count1[200010];
int count2[200010];
 
std::vector<int> V1[200010],V2[200010];
std::vector< std::pair<int,int> > V3;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) count1[x[i]]++;
	for(int i=1;i<=a;i++) count2[y[i]]++;
	
	int max = 0;
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		if(max<count1[i]+count2[i])
		{
			max = count1[i]+count2[i];
			s = i;
		}
	}
	
	int t1, t2;
	if(count1[s]==0)
	{
		t1 = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]>s)
			{
				t1 = i;
				break;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(y[i]==s)
			{
				t2 = i;
				break;
			}
		}
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			if(x[i]==s)
			{
				t1 = i;
				break;
			}
		}
		
		t2 = 1;
		for(int i=1;i<=a;i++)
		{
			if(y[i]>s)
			{
				t2 = i;
				break;
			}
		}
	}
		
	for(int i=1;i<=a;i++)
	{
		if(t1>a) t1 = 1;
		if(t2>a) t2 = 1;
		ans[t1] = y[t2];
		t1++, t2++;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==ans[i])
		{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}
