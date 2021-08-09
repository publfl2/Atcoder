#include <stdio.h>
#include <vector>

int MAX = (1e31) - 1;

int func2(int k, std::vector<int> &V1, std::vector<int> &V2)
{
	if(k<0) return 0;
	if(V1.empty()) return MAX;
	if(V2.empty()) return MAX;
	
	int h = (1<<k);
	
	std::vector<int> V11,V12,V21,V22;
	for(int i=0;i<V1.size();i++)
	{
		if(V1[i]>=h) V11.push_back(V1[i]-h);
		else V12.push_back(V1[i]);
	}
	for(int i=0;i<V2.size();i++)
	{
		if(V2[i]>=h) V21.push_back(V2[i]-h);
		else V22.push_back(V2[i]);
	}
	
	if(V11.size()==0 && V22.size()==0) return h + func2(k-1,V12,V21);
	else if(V12.size()==0 && V21.size()==0) return h + func2(k-1,V11,V22);
	else
	{
		int s1 = func2(k-1,V11,V21);
		int s2 = func2(k-1,V12,V22);
		return s1<s2?s1:s2;
	}
}

int func(int k, std::vector<int> &V)
{
	if(V.size()==0) return 0;
	if(k<0) return 0;
	
	int h = (1<<k);
	std::vector<int> V1,V2;
	for(int i=0;i<V.size();i++)
	{
		if(V[i]>=h) V1.push_back(V[i]);
		else V2.push_back(V[i]);
	}
	
	if(V1.size()%2==0 && V2.size()%2==0)
	{
		for(int i=0;i<V1.size();i++) V1[i] -= h;
		int s1 = func(k-1,V1);
		int s2 = func(k-1,V2);
		return (s1>s2?s1:s2);
	}
	else
	{
		for(int i=0;i<V1.size();i++) V1[i] -= h;
		return h + func2(k-1,V1,V2);
	}
}

std::vector<int> V;
int x[400010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=2*a;i++) V.push_back(x[i]);
	printf("%d",func(29,V));
}