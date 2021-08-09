#include <stdio.h>
#include <vector>

long long int power(long long int a, long long int b, long long int MOD)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k, long long int MOD)
{
	return power(k,MOD-2,MOD);
}

int check[100010],check2[100010];
std::vector<long long int> ans;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==2)
	{
		printf("Yes\n");
		printf("1 1");
		return 0;
	}
	
	int order1, order2;
	
	long long int p = 1;
	for(int i=1;;i++)
	{
		p = (p*b)%a;
		check[p] = 1;
		if(p==1)
		{
			order1 = i;
			break;
		}
	}
	
	p = 1;
	for(int i=1;;i++)
	{
		p = (p*c)%a;
		check2[p] = 1;
		if(p==1)
		{
			order2 = i;
			break;
		}
	}
	
	int count = 0;
	for(int i=1;i<a;i++) if(check[i]==1&&check2[i]==1) count++;
	
	if((long long int)order1*order2/count!=(a-1))
	{
		printf("No");
		return 0;
	}
	
	ans.push_back(1);
	p = 1;
	if(order1%2==0)
	{
		order2 /= count;
		for(int i=0;i<order1;i+=2)
		{
			for(int j=1;j<=order2-1;j++)
			{
				p = (p*c)%a;
				ans.push_back(p);
			}
			
			p = (p*b)%a;
			ans.push_back(p);
			
			for(int j=order2-2;j>=0;j--)
			{
				p = (p*inv(c,a))%a;
				ans.push_back(p);
			}
			
			p = (p*b)%a;
			ans.push_back(p);
		}
	}
	else
	{
		order1 /= count;
		for(int i=0;i<order2;i+=2)
		{
			for(int j=1;j<=order1-1;j++)
			{
				p = (p*b)%a;
				ans.push_back(p);
			}
			
			p = (p*c)%a;
			ans.push_back(p);
			
			for(int j=order1-2;j>=0;j--)
			{
				p = (p*inv(b,a))%a;
				ans.push_back(p);
			}
			
			p = (p*c)%a;
			ans.push_back(p);
		}
	}
	
	printf("Yes\n");
	for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}