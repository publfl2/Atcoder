#include <stdio.h>
#include <queue>
#include <vector>
 
int dist[100010];
long long int func(long long int k)
{
	if(k<100000) return dist[k];
	long long int k2 = k;
	int L = 0;
	while(k2)
	{
		L++;
		k2/=10;
	}
	L/=2;
	long long int M = 1;
	for(int i=1;i<=L;i++) M*=10;
	
	long long int b = (k/M);
	long long int c = (k%M);
	int ans = 12345;
	for(int i=0;i<=9&&i<=b;i++)
	{
		long long int s = (b-i);
		long long int t = c + i*M;
		int s1 = func(s);
		int s2 = func(t);
		int s3 = s1>s2?s1:s2;
		ans = ans<s3?ans:s3;
	}
	return ans;
}
 
std::vector<int> V;
void init(int k, int C)
{
	if(k<0)
	{
		V.push_back(C);
		return;
	}
	
	int M = 1;
	for(int i=1;i<=k;i++) M*=10;
	
	for(int i=1;i<=3;i++) init(k-1,C+i*M);
}
 
int prev[100010];
std::queue<int> Q;
int main()
{
	for(int i=4;i>=0;i--) init(i,0);
	for(int i=0;i<100000;i++) dist[i] = -1;
	dist[0] = 0;
	Q.push(0);
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		for(int i=0;i<V.size();i++)
		{
			if(k+V[i]<100000&&dist[k+V[i]]==-1)
			{
				prev[k+V[i]] = k;
				dist[k+V[i]] = dist[k] + 1;
				Q.push(k+V[i]);
			}
		}
	}
	
	int k = 923410;
	printf("%d\n",prev[k]);
	k = prev[k];
	printf("%d\n",prev[k]);
	k = prev[k];
	printf("%d\n",prev[k]);
}