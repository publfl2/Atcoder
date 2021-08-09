#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>


struct str{
	int first;
	int second;
	int index;
}x[200010];
bool cmp1(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.second<b.second;
}

std::vector<int> V;

int abs(int k)
{
	return k>0?k:-k;
}

std::map< std::pair<int,int> , int> M;
int func(int s, int t)
{
	if(M.find(std::make_pair(x[s].index,x[t].index))!=M.end()) return -1;
	M[std::make_pair(x[s].index,x[t].index)] = 1;
	M[std::make_pair(x[t].index,x[s].index)] = 1;
	
	int a = abs(x[s].first-x[t].first);
	int b = abs(x[s].second-x[t].second);
	return a>b?a:b;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]={b,c,i};
	}
	
	std::sort(x+1,x+a+1,cmp1);
	V.push_back(func(1,a));
	V.push_back(func(2,a));
	V.push_back(func(1,a-1));
	
	std::sort(x+1,x+a+1,cmp2);
	V.push_back(func(1,a));
	V.push_back(func(2,a));
	V.push_back(func(1,a-1));
	
	std::sort(V.begin(),V.end());
	printf("%d",V[V.size()-2]);
}