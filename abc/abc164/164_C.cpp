#include <stdio.h>
#include <map>
#include <string.h>

std::map<long long int,int> check;
char x[200010][20];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%s",x[i]+1);
		b = strlen(x[i]+1);
		
		long long int s = 0;
		for(int j=1;j<=b;j++)
		{
			s*=27;
			s+=(x[i][j]-'a'+1);
		}
		check[s]++;
	}
	int count = 0;
	for(std::map<long long int,int> ::iterator it = check.begin();it!=check.end();it++) count++;
	printf("%d",count);
}
