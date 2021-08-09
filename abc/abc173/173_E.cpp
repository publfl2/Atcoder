#include <stdio.h>
#include <algorithm>
#include <vector>
#define MOD 1000000007

std::vector<long long int> V1,V2;
long long int x[200010];
int a,b;
long long int max()
{
	int k = b;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>0) V1.push_back(x[i]);
		else if(x[i]<0) V2.push_back(x[i]);
	}
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	
	int start1 = 0, start2 = 0, p,q;
	
	if(k<=V1.size()) start1 = V1.size()-k, q = 0;
	else q = k-V1.size(), start1 = 0;
	
	if(q%2==1) q++, start1++;
	
	for(int i=start1;i<(int)V1.size()-1;i+=2)
	{
		if(q+1>=V2.size()) break;
		
		long long int S = V1[i] * V1[i+1];
		long long int T = V2[q] * V2[q+1];
		if(S>=T)
		{
			long long int ans = 1;
			for(int j=i;j<V1.size();j++) ans *= V1[j], ans %= MOD;
			for(int j=0;j<q;j++)
			{
				ans *= V2[j], ans %= MOD;
				ans += MOD, ans %= MOD;
			}
			return ans;
		}
		q+=2;
	}
	
	if(k<=V2.size())
	{
		long long int ans = 1;
		if(k%2==0)
		{
			for(int j=0;j<k;j++)
			{
				ans *= V2[j], ans %= MOD;
				ans += MOD, ans %= MOD;
			}
			return ans;
		}
		else
		{
			for(int j=0;j<k-1;j++)
			{
				ans *= V2[j], ans %= MOD;
				ans += MOD, ans %= MOD;
			}
			ans *= V1[V1.size()-1], ans %= MOD;
			return ans;
		}
	}
	else
	{
		long long int ans = 1;
		if(V2.size()%2==0)
		{
			for(int j=0;j<V2.size();j++)
			{
				ans *= V2[j], ans %= MOD;
				ans += MOD, ans %= MOD;
			}
			
			int C = k-V2.size();
			for(int i=V1.size()-1 ; i>=(int)V1.size()-(int)(k-V2.size()) ; i--)
			{
				ans *= V1[i], ans %= MOD;
			}
			return ans;
		}
		else
		{
			for(int j=0;j<V2.size()-1;j++)
			{
				ans *= V2[j], ans %= MOD;
				ans += MOD, ans %= MOD;
			}
			for(int i=V1.size()-1;i>=(int)V1.size()-(int)(k-V2.size()+1);i--) ans *= V1[i], ans %= MOD;
			return ans;
		}
	}
}

long long int min()
{
	int k = b;
	int count = 0;
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>0) V1.push_back(x[i]);
		else if(x[i]<0) V2.push_back(x[i]);
	}
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	
	if(k<=V2.size())
	{
		for(int j=V2.size()-1;j>=(int)V2.size()-k;j--)
		{
			ans *= V2[j], ans %= MOD;
			ans += MOD, ans %= MOD;
		}
		return ans;
	}
	else
	{
		for(int j=0;j<V2.size();j++)
		{
			ans *= V2[j], ans %= MOD;
			ans += MOD, ans %= MOD;
		}
		
		for(int i=0;i<(k-V2.size());i++) ans *= V1[i], ans %= MOD;
		return ans;
	}
}

int main()
{
	int count1 = 0, count2 = 0, count3 = 0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>0) count1++;
		else if(x[i]==0) count2++;
		else count3++;
	}
	if(count1+count3<b)
	{
		printf("0");
		return 0;
	}
	if(count2>0)
	{
		int m = 0>b-count1?0:b-count1;
		int M = b<count3?b:count3;
		
		if(m==M && m%2==1)
		{
			printf("0");
			return 0;
		}
		else
		{
			printf("%lld",max());
			return 0;
		}
	}
	else
	{
		int m = 0>b-count1?0:b-count1;
		int M = b<count3?b:count3;
		
		if(m==M && m%2==1)
		{
			printf("%lld",min());
			return 0;
		}
		else
		{
			printf("%lld",max());
			return 0;
		}
	}
}
