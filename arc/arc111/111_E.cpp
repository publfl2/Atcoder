#include <stdio.h>
#include <vector>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int A,B,C,D;
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		
		if(B==0)
		{
			long long int E;
			if(A%D==0) E = A;
			else E = (A/D+1)*D;
			long long int L;
			if((E-A)%C==0) L = (E-A)/C;
			else L = (E-A)/C+1;
			printf("%lld\n",L-1);
			continue;
		}
		
		std::pair<long long int,long long int> P = std::make_pair(0,1);
		long long int ans = 0;
		while(1)
		{
			
			if((D*P.second-A)%C==0) P.first = (D*P.second-A)/C;
			else P.first = (D*P.second-A)/C + 1;
			long long int L = (D*P.second-A)/B;
			if(P.first<=L)
			{
				//printf("%lld %lld??\n",P.first,L);
				
				ans -= (L-P.first+1);
				P.first = L;
				P.second++;
				if((D*P.second-C*P.first)<=A)
				{
					ans += P.first;
					break;
				}
			}
			else
			{
				if((B*P.first+A)%D==0) P.second = (B*P.first+A)/D;
				else P.second = (B*P.first+A)/D + 1;
			}
		}
		printf("%lld\n",ans);
	}
}
