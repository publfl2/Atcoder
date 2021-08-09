#include <stdio.h>
#include <vector>
#define MOD 1000000007

long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		t/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::pair<long long int,int> check1[200010];
long long int check2[200010];
std::vector<int> V[200010];
long long int fact[200010];
std::pair<long long int,int> func(int k, int prev)
{
	if(check1[k].second!=0) return check1[k];
	
	long long int ans = 1;
	int size = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans *= func(V[k][i],k).first, ans %= MOD;
		size += func(V[k][i],k).second;
	}
	ans *= fact[size], ans %= MOD;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans *= inv(fact[func(V[k][i],k).second]), ans %= MOD;
	}
	
	return check1[k] = std::make_pair(ans,size+1);
}

long long int func2(int k, int prev, long long int value, int s)
{
	long long int ans = value;
	int size = s;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans *= func(V[k][i],k).first, ans %= MOD;
		size += func(V[k][i],k).second;
	}
	ans *= fact[size], ans %= MOD;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans *= inv(fact[func(V[k][i],k).second]), ans %= MOD;
	}
	ans *= inv(fact[s]), ans %= MOD;
	check2[k] = ans;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		
		int S = size - func(V[k][i],k).second;
		long long int A = ans;
		A *= inv(fact[size]), A %= MOD;
		A *= fact[S], A %= MOD;
		A *= fact[func(V[k][i],k).second], A %= MOD;
		A *= inv(func(V[k][i],k).first), A %= MOD;
		func2(V[k][i],k,A,S+1);
	}
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = fact[i-1]*i, fact[i] %= MOD;
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func2(1,0,1,0);
	for(int i=1;i<=a;i++) printf("%lld\n",check2[i]);
	
}
