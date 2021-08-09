#include <stdio.h>
#include <vector>

long long int MAX = 21;
std::pair<long long int, long long int> func(long long int k, long long int s, long long int t)
{
	if(s<t)
	{
		if(s==0)
		{
			if(k%t==0) return std::make_pair(0,-(k/t));
			else return std::make_pair(0,0);
		}
		
		long long int a = t/s;
		std::pair<long long int, long long int> P = func(k,s,t%s);
		std::pair<long long int, long long int> ans = std::make_pair(P.first+a*P.second,P.second);
		ans.first += t, ans.second += s;
		long long int n1 = ans.first/t;
		long long int n2 = ans.second/s;
		long long int m = n1<n2?n1:n2;
		ans.first -= m*t, ans.second -= m*s;
		return ans;
	}
	else
	{
		if(t==0)
		{
			if(k%s==0) return std::make_pair((k/s),0);
			else return std::make_pair(0,0);
		}
		
		long long int a = s/t;
		std::pair<long long int, long long int> P = func(k,s%t,t);
		std::pair<long long int, long long int> ans = std::make_pair(P.first,P.second+a*P.first);
		ans.first += t, ans.second += s;
		long long int n1 = ans.first/t;
		long long int n2 = ans.second/s;
		long long int m = n1<n2?n1:n2;
		ans.first -= m*t, ans.second -= m*s;
		return ans;
	}
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

int main()
{
	for(int i=1;i<=17;i++) MAX *= 10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		long long int ans = MAX;
		for(long long int i = c-a-b+1;i<=c+d-a-1;i++)
		{
			long long int t;
			if(i==0)
			{
				long long int s1 = a;
				long long int s2 = c;
				t = s1>s2?s1:s2;
			}
			else
			{
				std::pair<long long int, long long int> P = func(i,2*a+2*b,c+d);
				if(P.first==0&&P.second==0) continue;
				
				long long int s1 = P.first * (2*a+2*b) + a;
				long long int s2 = P.second * (c+d) + c;
				t = s1>s2?s1:s2;
			}
			t %= lcm(2*a+2*b,c+d);
			ans = ans<t?ans:t;
		}
		if(ans==MAX) printf("infinity\n");
		else printf("%lld\n",ans);
	}
}