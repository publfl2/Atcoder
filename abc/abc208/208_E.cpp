#include <stdio.h>
#include <map>

int digit[110];
long long int x[110];
long long int power[110];

int p = 0;
std::map<long long int, long long int> M[110];
long long int func(int s, long long int C)
{
	if(s<0)
	{
		if(C>0) return 1;
		else return 0;
	}
	if(M[s].find(C)!=M[s].end()) return M[s][C];
	
	long long int ans = power[s];
	for(int i=1;i<=9;i++) ans += func(s-1,C/i);
	return M[s][C] = ans;
}

int main()
{
	power[0] = 1;
	for(int i=1;i<=18;i++) power[i] = 10*power[i-1];
	
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	for(int i=0;a;i++)
	{
		digit[i] = a%10;
		p = i;
		a/=10;
	}
	
	x[0] = digit[0];
	for(int i=1;i<=p;i++) x[i] = x[i-1] + digit[i] * power[i];
	
	long long int ans = 0;
	for(int i=0;i<p;i++) ans += func(i,b) - power[i];
	
	for(int i=p;i>=0;i--)
	{
		if(digit[i]==0)
		{
			ans += x[i]+1;
			goto u;
		}
		
		if(i!=p) ans += power[i];
		for(int j=1;j<digit[i];j++) ans += func(i-1,b/j);
		b /= digit[i];
	}
	
	if(b>0) ans++;
	u:;
	printf("%lld",ans);
}