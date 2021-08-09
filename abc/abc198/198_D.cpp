#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V;
int check[11];
int value[30], count[30];
int a,b,c, control = 0;
char x[20],y[20],z[20];

void func(int k)
{
	if(control) return;
	if(k==V.size())
	{
		long long int S1 = 0, S2 = 0, S3 = 0;
		if(value[x[1]-'a']==0) return;
		if(value[y[1]-'a']==0) return;
		if(value[z[1]-'a']==0) return;
		
		for(int i=1;i<=a;i++)
		{
			S1*=10;
			S1 += value[x[i]-'a'];
		}
		for(int i=1;i<=b;i++)
		{
			S2*=10;
			S2 += value[y[i]-'a'];
		}
		for(int i=1;i<=c;i++)
		{
			S3*=10;
			S3 += value[z[i]-'a'];
		}
		
		if(S1+S2==S3)
		{
			printf("%lld\n%lld\n%lld",S1,S2,S3);
			control = 1;
		}
		return;
	}
	
	for(int i=0;i<=9;i++)
	{
		if(check[i]==0)
		{
			check[i] = 1;
			value[V[k]] = i;
			func(k+1);
			value[V[k]] = 0;
			check[i] = 0;
		}
	}
	
}
int main()
{
	scanf("%s%s%s",x+1,y+1,z+1);
	a = strlen(x+1);
	b = strlen(y+1);
	c = strlen(z+1);
	for(int i=1;i<=a;i++) count[x[i]-'a']++;
	for(int i=1;i<=b;i++) count[y[i]-'a']++;
	for(int i=1;i<=c;i++) count[z[i]-'a']++;
	
	for(int i=0;i<26;i++) if(count[i]>0) V.push_back(i);
	if(V.size()>10)
	{
		printf("UNSOLVABLE");
		return 0;
	}
	
	
	func(0);
	if(control==0) printf("UNSOLVABLE");
}