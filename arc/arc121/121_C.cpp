#include <stdio.h>
#include <vector>

std::vector<int> ans;
int x[510];
void swap(int k)
{
	ans.push_back(k);
	int t = x[k];
	x[k] = x[k+1];
	x[k+1] = t;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int c = 1;
		for(int i=1;i<=a-2;i++)
		{
			int p = 0;
			for(int j=i;j<=a;j++) if(x[j]==i) p = j;
			if(p>i)
			{
				if((p-1)%2==c%2) for(int j=p-1;j>=i;j--) swap(j),c++;
				else
				{
					if((a-1)%2==c%2)
					{
						if(p==a-1)
						{
							swap(a-1),c++;
							swap(a-2),c++;
							swap(a-1),c++;
							for(int j=p-1;j>=i;j--) swap(j),c++;
						}
						else
						{
							swap(a-1),c++;
							for(int j=p-1;j>=i;j--) swap(j),c++;
						}
					}
					else
					{
						if(p==a-2)
						{
							swap(a-2),c++;
							swap(a-1),c++;
							swap(a-2),c++;
							for(int j=a-1;j>=i;j--) swap(j),c++;
						}
						else
						{
							swap(a-2),c++;
							for(int j=p-1;j>=i;j--) swap(j),c++;
						}
					}
				}
			}
		}
		
		if(x[a-1]==a-1 && x[a]==a);
		else
		{
			if((a-1)%2==c%2) swap(a-1),c++;
			else
			{
				swap(a-2);
				swap(a-1);
				swap(a-2);
				swap(a-1);
				swap(a-2);
			}
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
}