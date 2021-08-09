#include <stdio.h>
#include <string.h>
#include <atcoder/convolution>
#include <atcoder/modint>

using mint = atcoder::modint1000000007;
std::vector<mint> count;

mint fact[100010];
mint comb(int a, int b)
{
	mint ans = fact[a];
	ans /= fact[a-b];
	ans /= fact[b];
	return ans;
}

char x[100010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=100000;i++) fact[i] = fact[i-1]*i;
	
	scanf("%s",x+1);
	int a = strlen(x+1);
	int b;
	scanf("%d",&b);
	
	count.push_back(1);
	
	x[0] = -1, x[a+1] = -1;
	int last = 0;
	for(int i=1;i<=a+1;i++)
	{
		if(x[i]=='?') continue;
		else
		{
			std::vector<mint> temp;
			int l = (i-last-1);
			for(int j=0;j<=l;j++) temp.push_back(comb(l,j));
			if(x[last]==-1&&x[i]==-1) for(int j=0;j<temp.size();j++) temp[j] *= 2;
			else if(x[last]==-1||x[i]==-1);
			else
			{
				if(x[last]!=x[i])
				{
					temp.push_back(0);
					for(int j=0;j+1<temp.size();j+=2)
					{
						temp[j+1] += temp[j];
						temp[j] = 0;
					}
				}
				else
				{
					temp.push_back(0);
					for(int j=1;j+1<temp.size();j+=2)
					{
						temp[j+1] += temp[j];
						temp[j] = 0;
					}
				}
				count = atcoder::convolution(count,temp);
			}
		}
	}
	
	mint ans = 0;
	for(int i=0;i<count.size();i++) ans += count[i]*((i+1)/2);
	printf("%lld",ans);
}