#include <stdio.h>


char x[200010];
int power1[200010],power2[200010];
int func(int k)
{
	int C = k;
	int count = 0;
	while(C)
	{
		count += (C%2);
		C/=2;
	}
	if(count==0) return 0;
	else return func(k%count)+1;
}
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	int count = 0;
	for(int i=1;i<=a;i++) count += (x[i]-'0');
	int count1 = count+1, count2 = count-1;
	
	
	int s1 = 0, s2 = 0;
	for(int i=1;i<=a;i++)
	{
		s1*=2;
		s1+=(x[i]-'0');
		s1%=count1;
	}
	
	if(count2>0)
	{
		for(int i=1;i<=a;i++)
		{
			s2*=2;
			s2+=(x[i]-'0');
			s2%=count2;
		}
	}
	power1[0] = power2[0] = 1;
	for(int i=1;i<=a;i++) power1[i] = 2*power1[i-1],power1[i]%=count1;
	if(count2>0) for(int i=1;i<=a;i++) power2[i] = 2*power2[i-1],power2[i]%=count2;
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0') printf("%d\n",func((s1+power1[a-i])%count1)+1);
		else
		{
			if(count2==0) printf("0\n");
			else printf("%d\n",func((s2-power2[a-i]+count2)%count2)+1);
		}
	}
}
