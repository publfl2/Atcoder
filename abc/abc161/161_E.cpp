#include <stdio.h>

int start[200010],end[200010];
char x[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s",x+1);
	
	int p = 1;
	for(int i=1;i<=b;i++)
	{
		while(p<=a)
		{
			if(x[p]=='o')
			{
				start[i] = p;
				p += (c+1);
				break;
			}
			else p++;
		}
	}
	
	p = a;
	for(int i=b;i>=1;i--)
	{
		while(p>=1)
		{
			if(x[p]=='o')
			{
				end[i] = p;
				p -= (c+1);
				break;
			}
			else p--;
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		if(start[i]==end[i]) printf("%d\n",start[i]);
	}
}
