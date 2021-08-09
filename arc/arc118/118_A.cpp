#include <stdio.h>
#include <vector>

std::vector<int> V;
int check[210];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	b--;
	for(int i=0;i<100;i++)
	{
		int c = ((100+a)*i)/100;
		check[c] = 1;
	}
	for(int i=0;i<100+a;i++) if(check[i]==0) V.push_back(i);
	
	int c = V.size();
	int d = b/c;
	long long int ans = (long long int)(100+a)*d;
	printf("%lld",ans + V[b%c]);
}