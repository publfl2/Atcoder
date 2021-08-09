#include <stdio.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using mint = atcoder::modint998244353;

int size[2010];
std::vector<int> V[2010];
int getSize(int k)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++) ans += getSize(V[k][i]);
	return size[k] = ans;
}

std::vector<mint> func(int k)
{
	std::vector<mint> ans;
	ans.push_back(1);
	for(int i=0;i<V[k].size();i++)
	{
		ans = atcoder::convolution(ans,func(V[k][i]));
	}
	
	int S = getSize(k)-1;
	ans.push_back(0);
	for(int i=ans.size()-2;i>=0;i--) ans[i+1] += (S-i)* ans[i];
	if(ans.back()==0) ans.pop_back();
	return ans;
}

mint fact[2010];
std::vector<mint> ans;
int main()
{
	fact[0] = 1;
	for(int i=1;i<=2000;i++) fact[i] = i*fact[i-1];
	
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
	}
	ans = func(1);
	
	for(int i=0;i<ans.size();i++) ans[i] *= fact[a-i];
	
	mint sum = 0;
	for(int i=0;i<ans.size();i++)
	{
		if(i%2==0) sum += ans[i];
		else sum -= ans[i];
	}
	printf("%lld",sum);
}