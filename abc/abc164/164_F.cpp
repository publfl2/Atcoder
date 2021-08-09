#include <stdio.h>
#include <vector>

int type1[510],type2[510];
int value1[110][510],value2[110][510];
long long int x[510],y[510];
std::vector<int> V1,V2;

int ans[110][510][510];
long long int ans2[510][510];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&type1[i]);
	for(int i=1;i<=a;i++) scanf("%d",&type2[i]);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		x[i] = b;
		for(int j=0;j<64;j++) value1[j][i] = b%2, b/=2;
	}
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		y[i] = b;
		for(int j=0;j<64;j++) value2[j][i] = b%2, b/=2;
	}
	for(int p=0;p<64;p++) for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[p][i][j] = -1;
	
	for(int p=0;p<64;p++)
	{
		V1.clear();
		V2.clear();
		int C1 = 0, C2 = 0, C3 = 0 ,C4 = 0; 
		for(int i=1;i<=a;i++)
		{
			if(type1[i]==0 && value1[p][i]==1)
			{
				C1 = 1;
				for(int j=1;j<=a;j++)
				{
					if(ans[p][i][j]==0)
					{
						printf("-1");
						return 0;
					}
					ans[p][i][j] = 1;
				}
			}
			else if(type1[i]==1 && value1[p][i]==0)
			{
				C2 = 1;
				for(int j=1;j<=a;j++)
				{
					if(ans[p][i][j]==1)
					{
						printf("-1");
						return 0;
					}
					ans[p][i][j] = 0;
				}
			}
			else V1.push_back(i);
		}
		
		for(int j=1;j<=a;j++)
		{
			if(type2[j]==0 && value2[p][j]==1)
			{
				C3 = 1;
				for(int i=1;i<=a;i++)
				{
					if(ans[p][i][j]==0)
					{
						printf("-1");
						return 0;
					}
					ans[p][i][j] = 1;
				}
			}
			else if(type2[j]==1 && value2[p][j]==0)
			{
				C4 = 1;
				for(int i=1;i<=a;i++)
				{
					if(ans[p][i][j]==1)
					{
						printf("-1");
						return 0;
					}
					ans[p][i][j] = 0;
				}
			}
			else V2.push_back(j);
		}
		
		if(V1.size()==1)
		{
			int k = 0;
			for(int j=0;j<V2.size();j++)
			{
				if(type2[V2[j]]==0 && C2==0) ans[p][V1[0]][V2[j]] = 0, k=1;
				if(type2[V2[j]]==1 && C1==0) ans[p][V1[0]][V2[j]] = 1, k=0;
			}
			
			for(int j=0;j<V2.size();j++)
			{
				if(ans[p][V1[0]][V2[j]]==-1)
				{
					ans[p][V1[0]][V2[j]] = k++;
					k%=2;
				}
			}
		}
		else if(V2.size()==1)
		{
			int k = 0;
			for(int i=0;i<V1.size();i++)
			{
				if(type1[V1[i]]==0 && C4==0) ans[p][V1[i]][V2[0]] = 0, k=1;
				if(type1[V1[i]]==1 && C3==0) ans[p][V1[i]][V2[0]] = 1, k=0;
			}
			
			for(int i=0;i<V1.size();i++)
			{
				if(ans[p][V1[i]][V2[0]]==-1)
				{
					ans[p][V1[i]][V2[0]] = k++;
					k%=2;
				}
			}
		}
		else for(int i=0;i<V1.size();i++) for(int j=0;j<V2.size();j++) ans[p][V1[i]][V2[j]] = (i+j)%2;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			long long int S = 0;
			for(int p=63;p>=0;p--)
			{
				S*=2;
				S += ans[p][i][j];
			}
			ans2[i][j] = S;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(type1[i]==0)
		{
			long long int S = ans2[i][1];
			for(int j=2;j<=a;j++) S &= ans2[i][j];
			if(S!=x[i])
			{
				printf("-1");
				return 0;
			}
		}
		else
		{
			long long int S = ans2[i][1];
			for(int j=2;j<=a;j++) S |= ans2[i][j];
			if(S!=x[i])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	for(int j=1;j<=a;j++)
	{
		if(type2[j]==0)
		{
			long long int S = ans2[1][j];
			for(int i=2;i<=a;i++) S &= ans2[i][j];
			if(S!=y[j])
			{
				printf("-1");
				return 0;
			}
		}
		else
		{
			long long int S = ans2[1][j];
			for(int i=2;i<=a;i++) S |= ans2[i][j];
			if(S!=y[j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%lld ",ans2[i][j]);
		printf("\n");
	}
}
