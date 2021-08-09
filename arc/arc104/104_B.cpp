#include <stdio.h>
#include <string.h>

char x[5010];
int count1[5010],count2[5010],count3[5010],count4[5010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='A') count1[i]++;
		if(x[i]=='T') count2[i]++;
		if(x[i]=='C') count3[i]++;
		if(x[i]=='G') count4[i]++;
	}
	for(int i=1;i<=a;i++) count1[i] += count1[i-1];
	for(int i=1;i<=a;i++) count2[i] += count2[i-1];
	for(int i=1;i<=a;i++) count3[i] += count3[i-1];
	for(int i=1;i<=a;i++) count4[i] += count4[i-1];

	int ans = 0;
	int b = strlen(x+1);
	for(int i=1;i<=b;i++)
	{
		for(int j=i;j<=b;j++)
		{
			if(count1[j]-count1[i-1]==count2[j]-count2[i-1]&&count3[j]-count3[i-1]==count4[j]-count4[i-1]) ans++;
		}
	}
	printf("%d",ans);
}
