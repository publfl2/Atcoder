#include <stdio.h>

char x[200010],y[200010],z[200010];
int count[10];
int ans[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s%s",x+1,y+1,z+1);
		int type1 = 0, type2 = 0, type3 = 0, type4 = 0;
		if(x[1]=='0'&&x[2*a]=='0') type1 = 1;
		if(x[1]=='0'&&x[2*a]=='1') type2 = 1;
		if(x[1]=='1'&&x[2*a]=='0') type3 = 1;
		if(x[1]=='1'&&x[2*a]=='1') type4 = 1;
		if(y[1]=='0'&&y[2*a]=='0') type1 = 1;
		if(y[1]=='0'&&y[2*a]=='1') type2 = 1;
		if(y[1]=='1'&&y[2*a]=='0') type3 = 1;
		if(y[1]=='1'&&y[2*a]=='1') type4 = 1;
		if(z[1]=='0'&&z[2*a]=='0') type1 = 1;
		if(z[1]=='0'&&z[2*a]=='1') type2 = 1;
		if(z[1]=='1'&&z[2*a]=='0') type3 = 1;
		if(z[1]=='1'&&z[2*a]=='1') type4 = 1;
		if(type1==1&&type4==1)
		{
			if(type2==1)
			{
				for(int i=1;i<=a;i++) printf("1");
				for(int i=1;i<=a;i++) printf("0");
				printf("1\n");
			}
			else
			{
				for(int i=1;i<=a;i++) printf("0");
				for(int i=1;i<=a;i++) printf("1");
				printf("0\n");
			}
		}
		else if(type1==1)
		{
			for(int i=1;i<=a;i++) printf("1");
			printf("0");
			for(int i=1;i<=a;i++) printf("1");
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++) printf("0");
			printf("1");
			for(int i=1;i<=a;i++) printf("0");
			printf("\n");
		}
	}
}