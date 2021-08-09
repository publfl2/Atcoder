#include <stdio.h>
#include <vector>
#include <queue>

struct str{
	int first;
	int second;
	int value;
};
std::queue<str> Q;
int check[1010][1010];
std::vector<int> V[1010][30];
char e[10];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) check[i][i] = 1, Q.push({i,i,1});
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		scanf("%s",e+1);
		V[c][e[1]-'a'].push_back(d);
		V[d][e[1]-'a'].push_back(c);
		check[c][d] = check[d][c] = 2, Q.push({c,d,2});
	}
	
	
	while(!Q.empty())
	{
		int s = Q.front().first;
		int t = Q.front().second;
		int k = Q.front().value;
		Q.pop();
		
		for(int i=0;i<26;i++)
		{
			for(int j1=0;j1<V[s][i].size();j1++)
			{
				for(int j2=0;j2<V[t][i].size();j2++)
				{
					int s2 = V[s][i][j1];
					int t2 = V[t][i][j2];
					if(check[s2][t2]==0)
					{
						check[s2][t2] = check[t2][s2] = k+2;
						Q.push({s2,t2,k+2});
					}
				}
			}
		}
	}
	
	if(check[1][a]==0) printf("-1");
	else printf("%d",check[1][a]-1);
}