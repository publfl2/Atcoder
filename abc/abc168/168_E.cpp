#include <stdio.h>
#include <map>
#define MOD 1000000007

long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k , k%=MOD;
		b/=2;
	}
	return ans;
}

std::map< std::pair<long long int, long long int> , int> check1,check2;

int main()
{
	int a,count=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		if(b==0&&c==0)
		{
			count++;
			continue;
		}
		
		long long int d = gcd(abs(b),abs(c));
		b/=d, c/=d;
		if(b<0 && c<0) check1[std::make_pair(abs(b),abs(c))]++;
		if(b>0 && c>0) check1[std::make_pair(abs(b),abs(c))]++;
		if(b<0 && c>0) check2[std::make_pair(abs(b),abs(c))]++;
		if(b>0 && c<0) check2[std::make_pair(abs(b),abs(c))]++;
		if(b==0) check1[std::make_pair(abs(b),abs(c))]++;
		if(c==0) check2[std::make_pair(abs(b),abs(c))]++;
	}
	
	long long int ans = 1;
	std::map< std::pair<long long int, long long int> ,int > ::iterator it;
	
	for(it = check1.begin();it!=check1.end();it++)
	{
		std::pair<long long int, long long int> x0 = it->first;
		std::pair<long long int, long long int> x1 = std::make_pair(x0.second,x0.first);
		int y0 = it->second;
		if(check2.find(x1)!=check2.end())
		{
			long long int S = (power(2,y0) + power(2,check2[x1])-1)%MOD;
			ans *=S, ans%=MOD;
		}
		else
		{
			long long int S = (power(2,y0))%MOD;
			ans *=S, ans%=MOD;
		}
	}
	
	for(it = check2.begin();it!=check2.end();it++)
	{
		std::pair<long long int, long long int> x0 = it->first;
		std::pair<long long int, long long int> x1 = std::make_pair(x0.second,x0.first);
		int y0 = it->second;
		if(check1.find(x1)==check1.end())
		{
			long long int S = (power(2,y0))%MOD;
			ans *=S, ans%=MOD;
		}
	}
	
	ans += (count), ans%=MOD;
	printf("%lld",(ans+MOD-1)%MOD);
}
