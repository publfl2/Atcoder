#include <stdio.h>
#include <math.h>

int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	long long int ans = 0;
	for(int i=-200000;i<=200000;i++)
	{
		if(a-c<=i&&i<=a+c)
		{
			double L,R;
			R = sqrt(c*c-(a-i)*(a-i))+b+300000;
			L = -sqrt(c*c-(a-i)*(a-i))+b+300000;
			int s,t;
			if(L==(int)L) s = (int)L;
			else s = (int)L+1;
			if(R==(int)R) t = (int)R;
			else t = (int)R;
			ans += (t-s+1);
		}
	}
	printf("%lld",ans);
}
