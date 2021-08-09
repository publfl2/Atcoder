#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int limit;
std::vector<int> V[200010];
long long int check[200010][3];
int abs(int k)
{
	return k>0?k:-k;
}
long long int func(int k, int type)
{
	if(k>limit)
	{
		if(type==1) return abs(V[k-1][0]-0);
		else return abs(V[k-1].back()-0);
	}
	if(check[k][type]!=-1) return check[k][type];
	
	int start;
	if(type==1) start = V[k-1][0];
	else start = V[k-1].back();
	
	long long int s1 = func(k+1,1) + abs(start-V[k].back()) + abs(V[k].back()-V[k][0]);
	long long int s2 = func(k+1,2) + abs(start-V[k][0]) + abs(V[k].back()-V[k][0]);
	return check[k][type] = s1<s2?s1:s2;
}

int x[200010],y[200010];
std::vector<int> index;
std::map<int,int> hash;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=a;i++) index.push_back(y[i]);
	
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	for(int i=1;i<=a;i++) V[hash[y[i]]].push_back(x[i]);
	limit = index.size();
	
	for(int i=1;i<=limit;i++) std::sort(V[i].begin(),V[i].end());
	V[0].push_back(0);
	
	for(int i=1;i<=limit;i++) check[i][2] = check[i][1] = -1;
	printf("%lld",func(1,1));
}