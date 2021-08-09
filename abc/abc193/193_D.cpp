#include <stdio.h>

int power(int a, int b)
{
	int ans = 1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}

int count1[110],count2[110];
char x[10],y[10];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	scanf("%s",y+1);
	
	double ans = 0;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			for(int k=1;k<=9;k++) count1[k] = count2[k] = 0;
			for(int k=1;k<=4;k++) count1[x[k]-'0']++;
			count1[i]++;
			for(int k=1;k<=4;k++) count2[y[k]-'0']++;
			count2[j]++;
			if(count1[i]+count2[i]>a) continue;
			if(count1[j]+count2[j]>a) continue;
			double p;
			if(i==j) p = (double)(a-count1[i]-count2[i]+2)/(9*a-8) * (double)(a-count1[j]-count2[j]+1)/(9*a-9);
			else p = (double)(a-count1[i]-count2[i]+1)/(9*a-8) * (double)(a-count1[j]-count2[j]+1)/(9*a-9);
			int s = 0, t = 0;
			for(int k=1;k<=9;k++) s += k*power(10,count1[k]);
			for(int k=1;k<=9;k++) t += k*power(10,count2[k]);
			if(s>t) ans += p;
		}
	}
	
	printf("%.12lf",ans);
}