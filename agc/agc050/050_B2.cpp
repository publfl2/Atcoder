#include <stdio.h>

int x[510];
int check[510][510],check2[510][510];
int func(int s, int t)
{
	if(s>t) return 0;
	if(check[s][t]) return check2[s][t];
	
	int ans = 0;
	int S = func(s+1,t);
	ans = ans>S?ans:S;
	S = func(s,t-1);
	ans = ans>S?ans:S;
	for(int i=s+1;i<=t-1;i++)
	{
		if((i-s)%3==1 && (t-s)%3==2)
		{
			S = x[s]+x[t]+x[i] + func(s+1,i-1) + func(i+1,t-1);
			ans = ans>S?ans:S;
		}
	}
	check[s][t] = 1;
	check2[s][t] = ans;
	return ans;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("%d",func(1,a));
}
