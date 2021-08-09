#include <stdio.h>
#include <vector>
#include <string.h>

char x[200010];
std::vector<int> V[5];
char check[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V[0].clear();
		V[1].clear();
		scanf("%s",x+1);
		x[0] = 'b';
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) V[x[i]-'a'].push_back(i);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		if(V[1].size()==0)
		{
			for(int i=1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
		else
		{
			int L,R;
			for(int i=1;i<=a;i++)
			{
				if(x[i]=='b')
				{
					L = i;
					break;
				}
			}
			for(int i=a;i>=1;i--)
			{
				if(x[i]=='b')
				{
					R = i;
					break;
				}
			}
			
			int count1 = 0 ,count2 = 0,  count3 = 0;
			for(int i=1;i<=R;i++)
			{
				if(x[i-1]=='b'&&x[i]=='a')
				{
					if(x[i+1]=='b') count1++;
					else count2++;
				}
			}
			for(int i=R+1;i<=a;i++) if(x[i]=='a') count3++;
			
			if(count3>0)
			{
				if(count1%2==0)
				{
					int t = V[0].size()-2*count2-count1;
					if(t<0) t = 0;
					for(int i=0;i<V[1].size();i++) printf("b");
					for(int i=0;i<t;i++) printf("a");
					printf("\n");
				}
				else
				{
					int t = V[0].size()-2*count2-count1-1;
					if(t<0) t = 0;
					for(int i=0;i<V[1].size();i++) printf("b");
					for(int i=0;i<t;i++) printf("a");
					printf("\n");
				}
			}
			else
			{
				if(count2==0&&count1==0)
				{
					for(int i=0;i<V[1].size();i++) printf("b");
					printf("\n");
				}
				else
				{
					std::vector<char> W1,W2;
					for(int i=0;i<V[1].size();i++) check[V[1][i]] = 'b';
					if(V[0].size()%2==1) check[V[0].back()] = 'a';
					for(int i=1;i<=a;i++) if(check[i]>0) W1.push_back(check[i]);
					
					for(int i=L;i<=R;i++)
					{
						if(x[i]=='a')
						{
							if(x[i+1]=='a')
							{
								if(count1%2==0)
								{
									int t = V[0].size()-2*(count2-1)-count1;
									if(t<0) t = 0;
									for(int i=0;i<V[1].size()-2;i++) W2.push_back('b');
									for(int i=0;i<t;i++) W2.push_back('a');
									goto u;
								}
								else
								{
									int t = V[0].size()-2*(count2-1)-count1-1;
									if(t<0) t = 0;
									for(int i=0;i<V[1].size()-2;i++) W2.push_back('b');
									for(int i=0;i<t;i++) W2.push_back('a');
									goto u;
								}
							}
						}
					}
					
					for(int i=L;i<=R;i++)
					{
						if(x[i]=='a')
						{
							if(x[i+1]=='b')
							{
								count1--;
								if(count1%2==0)
								{
									int t = V[0].size()-2*count2-count1;
									if(t<0) t = 0;
									for(int i=0;i<V[1].size()-2;i++) W2.push_back('b');
									for(int i=0;i<t;i++) W2.push_back('a');
									goto u;
								}
								else
								{
									int t = V[0].size()-2*count2-count1-1;
									if(t<0) t = 0;
									for(int i=0;i<V[1].size()-2;i++) W2.push_back('b');
									for(int i=0;i<t;i++) W2.push_back('a');
									goto u;
								}
							}
						}
					}
					for(int i=0;i<W1.size();i++) printf("%c",W1[i]);
					printf("\n");
					continue;
					
					u:;
					for(int i=0;i<W1.size()||W2.size();i++)
					{
						if(i==W2.size() || W1[i]>W2[i])
						{
							for(int j=0;j<W1.size();j++) printf("%c",W1[j]);
							printf("\n");
							goto v;
						}
						if(i==W1.size() || W1[i]<W2[i])
						{
							for(int j=0;j<W2.size();j++) printf("%c",W2[j]);
							printf("\n");
							goto v;
						}
					}
					for(int j=0;j<W1.size();j++) printf("%c",W1[j]);
					printf("\n");
					v:;
				}
			}
		}
	}
}