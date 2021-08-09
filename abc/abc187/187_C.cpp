#include <stdio.h>
#include <string.h>
#include <map>
#define MOD 99999971
std::map<long long int,int> check1,check2;
char x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		if(x[1]=='!')
		{
			long long int S = 0;
			for(int j=2;j<=b;j++)
			{
				S*=MOD;
				S+=x[j];
			}
			if(check1[S]==1)
			{
				printf("%s",x+2);
				return 0;
			}
			check2[S] = 1;
		}
		else
		{
			long long int S = 0;
			for(int j=1;j<=b;j++)
			{
				S*=MOD;
				S+=x[j];
			}
			if(check2[S]==1)
			{
				printf("%s",x+1);
				return 0;
			}
			check1[S] = 1;
		}
	}
	printf("satisfiable");
}
