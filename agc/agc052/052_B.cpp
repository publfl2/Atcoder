#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int val1;
	int val2;
};

int value1[100010],value2[100010],value3[100010];
std::vector<str> V[100010];

void func(int k, int prev, int S1, int S2)
{
	value1[k] = S1;
	value2[k] = S2;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		int T1 = (S1^V[k][i].val1);
		int T2 = (S2^V[k][i].val2);
		func(V[k][i].first,k,T1,T2);
	}
}

int count1[31][10],count2[31][10];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		V[b].push_back({c,d,e});
		V[c].push_back({b,d,e});
	}
	
	func(1,0,0,0);
	
	for(int i=1;i<=a;i++)
	{
		int t = value1[i];
		for(int j=0;j<30;j++)
		{
			count1[j][t%2]++;
			t/=2;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = value2[i];
		for(int j=0;j<30;j++)
		{
			count2[j][t%2]++;
			t/=2;
		}
	}
	
	int root = 0;
	for(int j=0;j<30;j++)
	{
		if(count2[j][0]==count1[j][0]);
		else root += (1<<j);
	}
	//printf("%d!!\n",root);
	
	for(int i=1;i<=a;i++) value3[i] = (value2[i]^root);
	std::sort(value1+1,value1+a+1);
	std::sort(value3+1,value3+a+1);
	
	for(int i=1;i<=a;i++)
	{
		if(value1[i]!=value3[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}