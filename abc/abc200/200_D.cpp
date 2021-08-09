#include <stdio.h>
#include <vector>
int check[210][210][210][3];
int x[210],a;
int func(int k, int s, int t, int type)
{
	if(k>a)
	{
		if(type==0) return 0;
		else if(s==t) return 1;
		else return 0;
	}
	if(check[k][s][t][type]!=-1) return check[k][s][t][type];
	
	int s1 = func(k+1,s,t,type);
	int s2 = func(k+1,(s+x[k])%200,t,1);
	int s3 = func(k+1,s,(t+x[k])%200,1);
	int s4 = 1-(1-s1)*(1-s2)*(1-s3);
	return check[k][s][t][type] = s4;
}

std::vector<int> ans1,ans2;
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] %= 200;
	for(int i=1;i<=a;i++) for(int j=0;j<=200;j++) for(int k=0;k<=200;k++) check[i][j][k][0] = check[i][j][k][1] = -1;
	
	int t = func(1,0,0,0);
	if(t==0) printf("No\n");
	else
	{
		int s = 0,t = 0, type = 0;
		for(int k=1;k<=a;k++)
		{
			int s1 = func(k+1,s,t,type);
			int s2 = func(k+1,(s+x[k])%200,t,1);
			int s3 = func(k+1,s,(t+x[k])%200,1);
			if(s1==1) continue;
			else if(s2==1)
			{
				ans1.push_back(k);
				s = (s+x[k])%200;
				type = 1;
			}
			else if(s3==1)
			{
				ans2.push_back(k);
				t = (t+x[k])%200;
				type = 1;
			}
		}
		
		printf("Yes\n");
		printf("%d ",ans1.size());
		for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
		printf("\n");
		printf("%d ",ans2.size());
		for(int i=0;i<ans2.size();i++) printf("%d ",ans2[i]);
	}
}