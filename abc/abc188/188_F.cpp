#include <stdio.h>
#include <map>
long long int MAX = 2;
long long int abs(long long int k)
{
	return k>0?k:-k;
}
std::map<long long int, int> count;
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int L = b, R = b;
	long long int ans = MAX;
	int C = 100;
	while(C--)
	{
		for(long long int i=L;i<=R;i++) ans = ans<abs(i-a)+count[i]?ans:abs(i-a)+count[i];
		for(long long int i=L;i<=R;i++)
		{
			if(i%2==0)
			{
				count[i/2] = count[i]+1;
				if((i-1)>=L) count[i/2] = count[i/2]<count[i-1]+2?count[i/2]:count[i-1]+2;
				if((i+1)<=R) count[i/2] = count[i/2]<count[i+1]+2?count[i/2]:count[i+1]+2;
			}
		}
		if((L-1)%2==0)
		{
			count[(L-1)/2] = count[L]+2;
			L--;
		}
		if((R+1)%2==0)
		{
			count[(R+1)/2] = count[R]+2;
			R++;
		}
		L/=2,R/=2;
	}
	printf("%lld",ans);
}
