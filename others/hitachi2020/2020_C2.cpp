#include <stdio.h>
#include <vector>

int a;
int inv(int k)
{
	if(k>a) return k-a;
	else return k+a;
}

std::vector<int> V[200010];
int p[200010];
int next[400010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int func2(int k, int prev)
{
	int control = 0;
	int count = 0;
	p[k] = prev;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		control = 1;
		int t = func2(V[k][i],k);
		if(t==1 && count<=1)
		{
			count++;
			std::vector<int> temp;
			for(int j=0;j<V[k].size();j++)
			{
				if(V[k][j]==prev) continue;
				if(j==i) continue;
				temp.push_back(V[k][j]);
			}
			for(int j=1;j<temp.size();j++)
			{
				int s = find(temp[j]);
				int t = find(temp[0]);
				next[s] = t;
				s = find(temp[j]+a);
				t = find(temp[0]+a);
				next[s] = t;
			}
		}
	}
	return control;
}

int dist[200010];
int check[400010],ans[200010];
int v[5];
void func(int k, int prev, int h)
{
	dist[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1);
	}
}

std::vector<int> s1,s2,s3;
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i+=3) s1.push_back(i);
	for(int i=2;i<=a;i+=3) s2.push_back(i);
	for(int i=3;i<=a;i+=3) s3.push_back(i);
	for(int i=1;i<=2*a;i++) next[i] = i;
	
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func(1,0,1);
	int ind = 0;
	int max = 0;
	for(int i=1;i<=a;i++)
	{
		if(max<dist[i])
		{
			max = dist[i];
			ind = i;
		}
	}
	
	func(ind,0,1);
	max = 0;
	for(int i=1;i<=a;i++) max = max>dist[i]?max:dist[i];
	if(max<=3)
	{
		for(int i=1;i<=a;i++) printf("%d ",i);
		return 0;
	}
	
	func2(1,0);
	for(int i=2;i<=a;i++)
	{
		if(V[p[i]].size()>=2)
		{
			std::vector<int> temp;
			for(int j=0;j<V[i].size();j++)
			{
				if(V[i][j]==p[i]) continue;
				temp.push_back(V[i][j]);
			}
			for(int j=1;j<temp.size();j++)
			{
				int s = find(temp[j]);
				int t = find(temp[0]);
				next[s] = t;
				s = find(temp[j]+a);
				t = find(temp[0]+a);
				next[s] = t;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		int k = p[p[i]];
		if(k>=1)
		{
			if(p[k]>=1)
			{
				int s = find(i);
				int t = find(p[k]+a);
				next[s] = t;
				s = find(i+a);
				t = find(p[k]);
				next[s] = t;
			}
			for(int j=0;j<V[k].size();j++)
			{
				if(V[k][j]==p[k]) continue;
				if(V[k][j]==p[i]) continue;
				int s = find(i);
				int t = find(V[k][j]+a);
				next[s] = t;
				s = find(i+a);
				t = find(V[k][j]);
				next[s] = t;
				break;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int s = find(i);
		int t = find(i+a);
		
		if(s==t)
		{
			printf("-1");
			return 0;
		}
	}
	
	for(int i=1;i<=a;i++) if(dist[i]==4) v[4] = i;
	for(int i=0;i<V[v[4]].size();i++) if(dist[V[v[4]][i]]==3) v[3] = V[v[4]][i];
	for(int i=0;i<V[v[3]].size();i++) if(dist[V[v[3]][i]]==2) v[2] = V[v[3]][i];
	for(int i=0;i<V[v[2]].size();i++) if(dist[V[v[2]][i]]==1) v[1] = V[v[2]][i];
	//printf("%d %d %d %d!!\n",v[1],v[2],v[3],v[4]);
	v[1] = find(v[1]);
	v[2] = find(v[2]);
	v[3] = find(v[3]);
	v[4] = find(v[4]);
	
	for(int i1=1;i1<=2;i1++)
	{
		for(int i2=1;i2<=2;i2++)
		{
			for(int i3=1;i3<=2;i3++)
			{
				for(int i4=1;i4<=2;i4++)
				{
					check[v[1]] = check[v[2]] = check[v[3]] = check[v[4]] = 0;
					
					check[v[1]] = i1, check[inv(v[1])] = 3-i1;
					if(check[v[2]]==0 || check[v[2]]==i2) check[v[2]] = i2, check[inv(v[2])] = 3-i2;
					else continue;
					if(check[v[3]]==0 || check[v[3]]==i3) check[v[3]] = i3, check[inv(v[3])] = 3-i3;
					else continue;
					if(check[v[4]]==0 || check[v[4]]==i4) check[v[4]] = i4, check[inv(v[4])] = 3-i4;
					else continue;
					
					for(int j=1;j<=a;j++) ans[j] = 0;
					for(int j=1;j<=a;j++)
					{
						int t = find(j);
						ans[j] = check[t];
					}
					int S1 = 0, S2 = 0;
					for(int j=1;j<=a;j++)
					{
						if(ans[j]==1) S1++;
						else S2++;
					}
					if(S1 >= s1.size() && S2>=s2.size())
					{
						for(int j=1;j<=a;j++)
						{
							if(ans[j]==1)
							{
								if(s1.size()==0)
								{
									printf("%d ",s3.back());
									s3.pop_back();
								}
								else
								{
									printf("%d ",s1.back());
									s1.pop_back();
								}
							}
							else
							{
								if(s2.size()==0)
								{
									printf("%d ",s3.back());
									s3.pop_back();
								}
								else
								{
									printf("%d ",s2.back());
									s2.pop_back();
								}
							}
						}
						return 0;
					}
					else if(S1 >= s2.size() && S2>=s1.size())
					{
						for(int j=1;j<=a;j++)
						{
							if(ans[j]==1)
							{
								if(s2.size()==0)
								{
									printf("%d ",s3.back());
									s3.pop_back();
								}
								else
								{
									printf("%d ",s2.back());
									s2.pop_back();
								}
							}
							else
							{
								if(s1.size()==0)
								{
									printf("%d ",s3.back());
									s3.pop_back();
								}
								else
								{
									printf("%d ",s1.back());
									s1.pop_back();
								}
							}
						}
						return 0;
					}
				}
			}
		}
	}
	printf("-1");
}