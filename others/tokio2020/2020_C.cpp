#include <stdio.h>

int x[200010],s[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int j=1;j<=50&&j<=b;j++)
	{
		for(int i=1;i<=a;i++)
		{
			int L = i-x[i];
			int R = i+x[i];
			if(L<1) L = 1;
			if(R>a) R = a;
			s[L]++, s[R+1]--;
		}
		
		for(int i=1;i<=a;i++) x[i] = x[i-1] + s[i];
		for(int i=1;i<=a+1;i++) s[i] = 0;
	}
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
}
