#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

char x[110];
std::vector<int> V[1000010],V2[1000010];
int check[1000010];

int func2(char a, char b, char c)
{
	int a2,b2,c2;
	if('a'<=a&&a<='z') a2 = a-'a';
	else a2 = a-'A'+26;
	if('a'<=b&&b<='z') b2 = b-'a';
	else b2 = b-'A'+26;
	if('a'<=c&&c<='z') c2 = c-'a';
	else c2 = c-'A'+26;
	return a2*52*52+b2*52+c2;
}

int y[200010];
std::queue<int> Q;
int inQueue[1000010];
int count[1000010];

int main()
{
	int MAX = 52*52*52;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		int s = func2(x[1],x[2],x[3]);
		int t = func2(x[b-2],x[b-1],x[b]);
		V[s].push_back(t);
		V2[t].push_back(s);
		y[i] = t;
	}
	
	for(int i=0;i<MAX;i++) count[i] = V[i].size();
	for(int i=0;i<MAX;i++)
	{
		if(count[i]==0)
		{
			inQueue[i] = 1;
			Q.push(i);
		}
	}
	
	while(!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		
		check[t] = 1; // lose
		for(int i=0;i<V2[t].size();i++)
		{
			int k = V2[t][i];
			if(inQueue[k]==1) continue;
			
			check[k] = 2; // win
			inQueue[k] = 1;
			for(int j=0;j<V2[k].size();j++)
			{
				if(inQueue[V2[k][j]]==0)
				{
					count[V2[k][j]]--;
					if(count[V2[k][j]]==0)
					{
						inQueue[V2[k][j]] = 1;
						Q.push(V2[k][j]);
					}
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check[y[i]]==0) printf("Draw\n");
		if(check[y[i]]==1) printf("Takahashi\n");
		if(check[y[i]]==2) printf("Aoki\n");
	}
}