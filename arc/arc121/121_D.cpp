#include <stdio.h>
#include <algorithm>
#define MAX (long long int)1e15

int x[5010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int L = 1, R = a;
	
	long long int min = MAX, max = -MAX;
	while(L<R)
	{
		if(x[L]<0 && x[R]>0)
		{
			min = min<x[R]+x[L]?min:x[R]+x[L];
			max = max>x[R]+x[L]?max:x[R]+x[L];
			L++, R--;
		}
		else break;
	}
	
	long long int ans = MAX;
	for(int i=L;i<=R+1;i++)
	{
		long long int m = min, M = max;
		for(int j=i;j<=R;j++) m = m<x[j]?m:x[j], M = M>x[j]?M:x[j];
		for(int j=0;L+j<=i-1-j;j++)
		{
			if(L+j==i-1-j)
			{
				m = m<x[L+j]?m:x[L+j];
				M = M>x[L+j]?M:x[L+j];
			}
			else
			{
				int t = x[L+j] + x[i-1-j];
				m = m<t?m:t, M = M>t?M:t;
			}
		}
		ans = ans<M-m?ans:M-m;
	}
	
	for(int i=L-1;i<=R;i++)
	{
		long long int m = min, M = max;
		for(int j=L;j<=i;j++) m = m<x[j]?m:x[j], M = M>x[j]?M:x[j];
		for(int j=0;i+1+j<=R-j;j++)
		{
			if(R-j==i+1+j)
			{
				m = m<x[R-j]?m:x[i+1+j];
				M = M>x[R-j]?M:x[i+1+j];
			}
			else
			{
				int t = x[R-j] + x[i+1+j];
				m = m<t?m:t, M = M>t?M:t;
			}
		}
		ans = ans<M-m?ans:M-m;
	}
	
	printf("%lld",ans);
}