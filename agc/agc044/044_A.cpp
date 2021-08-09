#include <stdio.h>
#include <map>

std::map<long long int, long long int> check;
long long int b,c,d,e;
long long int func(long long int k)
{
	if(check.find(k)!=check.end()) return check[k];
	
	long long int ans = -1;
	for(int i=0;i<=4;i++)
	{
		if((k+i)%2==0 && (k+i)/2 < k)
		{
			long long int s = func((k+i)/2) + b + i*e;
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
		if((k+i)%3==0 && (k+i)/3 < k)
		{
			long long int s = func((k+i)/3) + c + i*e;
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
		if((k+i)%5==0 && (k+i)/5 < k)
		{
			long long int s = func((k+i)/5) + d + i*e;
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
	}
	
	for(int i=1;i<=4;i++)
	{
		if((k-i)%2==0 && (k-i)>=0)
		{
			long long int s;
			if(k-i==0) s = i*e;
			else s = func((k-i)/2) + b + i*e;
			
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
		if((k-i)%3==0 && (k-i)>=0)
		{
			long long int s;
			if(k-i==0) s = i*e;
			else s = func((k-i)/3) + c + i*e;
			
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
		if((k-i)%5==0 && (k-i)>=0)
		{
			long long int s;
			if(k-i==0) s = i*e;
			else s = func((k-i)/5) + d + i*e;
			
			if(ans==-1) ans = s;
			else ans = ans<s?ans:s;
		}
	}
	if(k<=2000000000)
	{
		long long int s = k*e;
		ans = ans<s?ans:s;
	}
	
	return check[k] = ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check.clear();
		long long int a;
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
		printf("%lld\n",func(a));
	}
}
