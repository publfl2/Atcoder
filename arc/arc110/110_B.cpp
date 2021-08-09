#include <stdio.h>
#include <vector>

long long int MAX = 1;
std::vector<int> V;
char x[200010];
int main()
{
	for(int i=1;i<=10;i++) MAX*=10;
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) if(x[i]=='0') V.push_back(i);
	if(V.empty())
	{
		if(a==1) printf("%lld",2*MAX);
		else if(a==2) printf("%lld",MAX);
		else printf("0");
	}
	else
	{
		if(V[0]>=4) printf("0");
		else if(V.back()<=a-3) printf("0");
		else
		{
			for(int i=0;i+1<V.size();i++)
			{
				if(V[i+1]-V[i]!=3)
				{
					printf("0");
					goto u;
				}
			}
			
			if(x[a]=='0') printf("%lld",MAX-V.size()+1);
			else printf("%lld",MAX-V.size());
			u:;
		}
	}
}
