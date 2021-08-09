#include <stdio.h>
#include <vector>
#include <algorithm>
int size[100010];
std::vector<int> V[100010];
int getSize(int k, int prev)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	return size[A.first]-2*A.second < size[B.first]-2*B.second;
}

int func(int k, int prev)
{
	std::vector< std::pair<int,int> > odd,even;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(getSize(V[k][i],k)%2==1) odd.push_back(std::make_pair(V[k][i],func(V[k][i],k)));
		else even.push_back(std::make_pair(V[k][i],func(V[k][i],k)));
	}
	if(odd.size()==0)
	{
		int ans = 1;
		for(int i=0;i<even.size();i++) ans += even[i].second;
		return ans;
	}
	else
	{
		int ans = 1;
		for(int i=0;i<even.size();i++)
		{
			std::pair<int,int> t = even[i];
			if(size[t.first]-t.second>t.second) ans += t.second;
		}
		std::sort(odd.begin(),odd.end(),cmp);
		if(odd.size()%2==1)
		{
			for(int i=odd.size()-1;i>=0;i-=2) ans += odd[i].second;
			for(int i=(int)odd.size()-2;i>=0;i-=2) ans += (size[odd[i].first]-odd[i].second);
			for(int i=0;i<even.size();i++)
			{
				std::pair<int,int> t = even[i];
				if(size[t.first]-t.second<=t.second) ans += (size[t.first]-t.second);
			}
		}
		else
		{
			for(int i=odd.size()-1;i>=0;i-=2) ans += odd[i].second;
			for(int i=(int)odd.size()-2;i>=0;i-=2) ans += (size[odd[i].first]-odd[i].second);
			for(int i=0;i<even.size();i++)
			{
				std::pair<int,int> t = even[i];
				if(size[t.first]-t.second<=t.second) ans += t.second;
			}
		}
		return ans;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
		V[i].push_back(b);
	}
	getSize(1,0);
	printf("%d",func(1,0));
}