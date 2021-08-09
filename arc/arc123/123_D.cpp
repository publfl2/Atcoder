#include <stdio.h>
#include <map>
#define MAX (long long int)1e16

long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int x[200010],B[200010],C[200010],sum1[200010],sum2[200010];
std::map<long long int,int> M;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	if(x[1]<0)
	{
		for(int i=1;i<=a;i++) x[i] *= (-1);
	}
	
	B[1] = 0;
	for(int i=2;i<=a;i++) B[i] = B[i-1] + (0>x[i]-x[i-1]?0:x[i]-x[i-1]);
	for(int i=1;i<=a;i++) C[i] = x[i] - B[i];
	
	for(int i=1;i<=a;i++) sum1[i] = sum1[i-1] + B[i];
	for(int i=1;i<=a;i++) sum2[i] = sum2[i-1] + C[i];
	
	long long int ans = MAX;
	for(int i=a;i>=1;i--) if(M[C[i]]==0) M[C[i]] = i;
	M[MAX] = 0;
	
	for(int i=a;i>=1;i--)
	{
		std::map<long long int,int> ::iterator it = M.lower_bound(-B[i]);
		int t = (it->second);
		long long int val1 = (sum1[a] - sum1[i-1]) - (a-i+1)*B[i];
		long long int val2 = -(sum1[i-1] - (i-1)*B[i]);
		long long int val3 = (sum2[t]) + (t)*B[i];
		long long int val4 = -(sum2[a]-sum2[t] + (a-t)*B[i]);
		long long int val = val1+val2+val3+val4;
		ans = ans<val?ans:val;
	}
	printf("%lld",ans);
}