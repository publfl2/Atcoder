#include <stdio.h>
#include <vector>
#include <stack>

int count[1000010];
std::vector<int> V[100010];
std::vector<int> St;
int check[100010];
void func(int k, int prev)
{
	St.push_back(k);
	if(check[k]==1)
	{
		int i;
		for(i=0;i<St.size();i++) if(St[i]==k) break;
		for(;i<St.size()-1;i++)
		{
			int s = St[i], t = St[i+1];
			std::vector<int> ::iterator it;
			
			for(it = V[s].begin();it!=V[s].end();it++)
			{
				if((*it)==t)
				{
					V[s].erase(it);
					count[s]--;
					break;
				}
			}
			for(it = V[t].begin();it!=V[t].end();it++)
			{
				if((*it)==s)
				{
					V[t].erase(it);
					count[t]--;
					break;
				}
			}
		}
		return;
	}
	
	check[k] = 1;
	if(prev==V[k][0]) func(V[k][1],k);
	else func(V[k][0],k);
}

int check2[100010];
void func2(int k, int color)
{
	if(check2[k]) return;
	check2[k] = color;
	for(int i=0;i<V[k].size();i++) func2(V[k][i],color);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
		count[c]++, count[d]++;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(count[i]%2==1)
		{
			printf("No");
			return 0;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(count[i]>=6)
		{
			printf("Yes");
			return 0;
		}
	}
	int ans = 0;
	for(int i=1;i<=a;i++) if(count[i]>=4) ans++;
	if(ans>=3)
	{
		printf("Yes");
		return 0;
	}
	if(ans<=1)
	{
		printf("No");
		return 0;
	}
	func(1,0);
	
	for(int i=1;i<=a;i++)
	{
		if(count[i]>=4)
		{
			printf("Yes");
			return 0;
		}
	}
	
	int color = 1;
	for(int i=1;i<=a;i++)
	{
		if(count[i]>0&&check2[i]==0)
		{
			func2(i,color++);
		}
	}
	if(color>=3) printf("Yes");
	else printf("No");
}
