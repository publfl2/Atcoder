#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int size[200010],next[300010];
int find(int k)
{
	if(next[k]==k) return k;
	else return next[k] = find(next[k]);
}

int p[200010];
int func(int k, int prev)
{
	p[k] = prev;
	int control = 0;
	int count = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		control = 1;
		int t = func(V[k][i],k);
		if(t==1)
		{
			if(count<=1)
			{
				count++;
				for(int j=0;j<V[k].size();j++)
				{
					if(V[k][j]==prev) continue;
					if(j==i) continue;
					int s = find(prev);
					int t = find(V[k][j]);
					if(s==t) continue;
					next[s] = t;
					size[t] += size[s];
				}
			}
		}
	}
	
	return control;
}

int ans[200010];
int check[200010];
std::vector<int> s1,s2,s3;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) next[i] = i, size[i] = 1;
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func(1,0);
	for(int i=2;i<=a;i++)
	{
		if(V[p[i]].size()>=2)
		{
			
			for(int j=0;j<V[i].size();j++)
			{
				if(V[i][j]==p[i]) continue;
				
			}
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",find(i));
	printf("!!\n");
	
	for(int i=1;i<=a;i+=3) s1.push_back(i);
	for(int i=2;i<=a;i+=3) s2.push_back(i);
	for(int i=3;i<=a;i+=3) s3.push_back(i);
	int count1 = s1.size(), count2 = s2.size(), count3 = s3.size();
	
	/*int t = find(0);
	if(size[t]-1<=count1+count3)
	{
		check[t] = 1;
		if(count1>=size[t]-1) count1 -= (size[t]-1);
		else
		{
			count3 -= (size[t]-1-count1);
			count1 = 0;
		}
	}
	else if(size[t]-1<=count2+count3)
	{
		check[t] = 2;
		if(count2>=size[t]-1) count2 -= (size[t]-1);
		else
		{
			count3 -= (size[t]-1-count2);
			count2 = 0;
		}
	}
	else
	{
		printf("-1");
		return 0;
	}*/
	
	for(int i=0;i<=a;i++)
	{
		int t = find(i);
		if(check[t]==0)
		{
			if(count1>=count2)
			{
				if(size[t]<=count1+count3)
				{
					check[t] = 1;
					if(count1>=size[t]) count1 -= size[t];
					else
					{
						count3 -= (size[t]-count1);
						count1 = 0;
					}
				}
				else if(size[t]<=count2+count3)
				{
					check[t] = 2;
					if(count2>=size[t]) count2 -= size[t];
					else
					{
						count3 -= (size[t]-count2);
						count2 = 0;
					}
				}
				else
				{
					printf("-1");
					return 0;
				}
			}
			else
			{
				if(size[t]<=count2+count3)
				{
					check[t] = 2;
					if(count2>=size[t]) count2 -= size[t];
					else
					{
						count3 -= (size[t]-count2);
						count2 = 0;
					}
				}
				else if(size[t]<=count1+count3)
				{
					check[t] = 1;
					if(count1>=size[t]) count1 -= size[t];
					else
					{
						count3 -= (size[t]-count1);
						count1 = 0;
					}
				}
				else
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = find(i);
		if(check[t]==1)
		{
			if(s1.size()>0)
			{
				printf("%d ",s1.back());
				s1.pop_back();
			}
			else
			{
				printf("%d ",s3.back());
				s3.pop_back();
			}
		}
		else
		{
			if(s2.size()>0)
			{
				printf("%d ",s2.back());
				s2.pop_back();
			}
			else
			{
				printf("%d ",s3.back());
				s3.pop_back();
			}
		}
	}
}