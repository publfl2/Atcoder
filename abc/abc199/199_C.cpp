#include <stdio.h>

char x[400010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int type = 0;
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(c==1)
		{
			if(type==0)
			{
				char t = x[d];
				x[d] = x[e];
				x[e] = t;
			}
			else
			{
				d+=a, e+=a;
				if(d>2*a) d-=2*a;
				if(e>2*a) e-=2*a;
				char t = x[d];
				x[d] = x[e];
				x[e] = t;
			}
		}
		else type = (1+type)%2;
	}
	
	if(type==0) for(int i=1;i<=2*a;i++) printf("%c",x[i]);
	else
	{
		for(int i=a+1;i<=2*a;i++) printf("%c",x[i]);
		for(int i=1;i<=a;i++) printf("%c",x[i]);
	}
}