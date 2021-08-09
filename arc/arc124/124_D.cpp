#include <stdio.h>

int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}

int x[200010];
int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a+b;i++) scanf("%d",&x[i]);
	
	int ans = a+b;
	int count0 = 0, count1 = 0, count2 = 0;
	for(int i=1;i<=a+b;i++)
	{
		if(check[i]==0)
		{
			if(x[i]==i)
			{
				check[i] = 1;
				ans--;
				continue;
			}
			
			int t = i;
			int L = 0, R = 0;
			while(check[t]==0)
			{
				check[t] = 1;
				if(t<=a) L = 1;
				else R = 1;
				t = x[t];
			}
			if(L==1&&R==1) count0++;
			if(L==1&&R==0) count1++;
			if(L==0&&R==1) count2++;
		}
	}
	
	if(count0>=1)
	{
		printf("%d",ans-count0+max(count1,count2)-min(count1,count2));
	}
	else
	{
		if(count1>=1 && count2>=1) printf("%d",ans+max(count1,count2)-min(count1,count2));
		else printf("%d",ans+max(count1,count2));
	}
}