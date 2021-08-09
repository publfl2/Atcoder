#include <stdio.h>
#include <vector>
#include <algorithm>

#define MOD 1000000007
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::vector<long long int> poly;
void mul(long long int k)
{
	std::vector<long long int> newPoly;
	newPoly.push_back(0);
	for(int i=0;i<poly.size();i++) newPoly.push_back(poly[i]);
	for(int i=0;i<poly.size();i++)
	{
		newPoly[i] += k*(MOD-poly[i]);
		newPoly[i]%=MOD;
	}
	poly = newPoly;
}
std::vector<long long int> newPoly, newPoly2;

void integral()
{
	newPoly2.clear();
	newPoly2.push_back(0);
	for(int i=0;i<poly.size();i++)
	{
		newPoly2.push_back(poly[i]*inv(1+i));
		newPoly2[i+1] %= MOD;
	}
}

long long int func(std::vector<long long int>& poly2, long long int val)
{
	long long int sum = 0;
	long long int k = 1;
	for(int i=0;i<poly2.size();i++)
	{
		sum += k*poly2[i];
		sum %= MOD;
		k*=val;
		k%=MOD;
	}
	return sum;
}

std::pair<int,int> P[1010];
bool cmp(std::pair<int,int> a,std::pair<int,int> b)
{
	return a.second<b.second;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
	}
	
	long long int start = 1;
	for(int i=1;i<=a+1;i++) start*=i, start%=MOD;
	poly.push_back(start);
	
	int limit = P[1].first;
	for(int i=2;i<=a;i++) limit = limit>P[i].first?limit:P[i].first;
	
	long long int ans = 0;
	std::sort(P+1,P+a+1,cmp);
	P[0].second = limit;
	for(int i=a;i>=1;i--)
	{
		if(P[i].second<=limit) break;
		int min = limit>P[i-1].second?limit:P[i-1].second;
		int max = P[i].second;
		
		mul(P[i].first);
		
		newPoly.clear();
		newPoly.push_back(0);
		for(int j=0;j<poly.size();j++) newPoly.push_back(poly[j]);
		long long int S1 = func(newPoly,max) - func(newPoly,min);
		S1 += MOD;
		S1 %= MOD;
		integral();
		long long int S2 = func(newPoly2,max) - func(newPoly2,min);
		S2 += MOD;
		S2 %= MOD;
		ans += (S1-S2+MOD);
		ans %= MOD;
	}
	printf("%lld",ans);
}
