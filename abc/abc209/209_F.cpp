#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
#define MAX (long long int)1e16

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k , k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[4010][4010];
long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	if(fact[a][b]) return fact[a][b];
	return fact[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}

std::pair<long long int ,long long int> check[4010][4010];
long long int x[4010];
std::pair<long long int ,long long int> func(int L, int R)
{
	printf("%d %d??\n",L,R);
	if(L==R) return std::make_pair(x[L],1);
	if(check[L][R].first!=-1) return check[L][R];
	
	std::pair<long long int ,long long int> ans = std::make_pair(MAX,0);
	std::pair<long long int ,long long int> P1 = func(L+1,R);
	P1.first += x[L]+x[L+1];
	if(ans.first>P1.first) ans = P1;
	else if(ans.first==P1.first) ans.second += P1.second, ans.second %= MOD;
	
	std::pair<long long int ,long long int> P2 = func(L,R-1);
	P2.first += x[R]+x[R-1];
	if(ans.first>P2.first) ans = P2;
	else if(ans.first==P2.first) ans.second += P2.second, ans.second %= MOD;
	
	for(int i=L+1;i<=R-1;i++)
	{
		std::pair<long long int ,long long int> P1 = func(L,i-1);
		std::pair<long long int ,long long int> P2 = func(i+1,R);
		std::pair<long long int ,long long int> P;
		P.first = P1.first + P2.first + x[i]+x[i-1]+x[i+1];
		P.second = (P1.second * P2.second) % MOD;
		P.second *= comb(R-L,i-L);
		P.second %= MOD;
		if(ans.first>P.first) ans = P;
		else if(ans.first==P.first) ans.second += P.second, ans.second %= MOD;
	}
	
	return check[L][R] = ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	for(int i=1;i<=a;i++) for(int j=i;j<=a;j++) check[i][j].first = -1;
	std::pair<long long int ,long long int> P = func(1,a);
	
	printf("%lld",P.second);
}