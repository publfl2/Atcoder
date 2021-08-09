#include <stdio.h>
#include <vector>

std::vector<int> save,trash;
char x[500010],y[500010];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	y[a+1] = '1';
	long long int ans = 0;
	int C = -1;
	for(int i=1;i<=a+1;i++)
	{
		if(y[i]=='1')
		{
			if(C==-1)
			{
				if(save.size()%2==1)
				{
					for(int j=0;j+1<save.size();j+=2) ans += (save[j+1]-save[j]);
					trash.push_back(save.back());
					ans++;
					save.clear();
					C = i;
				}
				else
				{
					for(int j=0;j+1<save.size();j+=2) ans += (save[j+1]-save[j]);
					save.clear();
					C = i;
				}
			}
			else
			{
				if(save.size()%2==1)
				{
					for(int j=1;j+1<save.size();j+=2) ans += (save[j+1]-save[j]);
					ans += (save[0]-C);
					save.clear();
					C = i;
				}
				else
				{
					if(save.size()==0)
					{
						trash.push_back(C);
						ans++;
						C = i;
					}
					else
					{
						for(int j=1;j+1<save.size();j+=2) ans += (save[j+1]-save[j]);
						ans += (save[0]-C);
						trash.push_back(save.back());
						ans++;
						save.clear();
						C = i;
					}
				}
			}
		}
		if(x[i]=='1')
		{
			if(trash.size()==0) save.push_back(i);
			else
			{
				ans += (i-trash.back()-1);
				trash.pop_back();
			}
		}
		//printf("%d %lld!!\n",i,ans);
	}
	if(trash.size()>0) printf("-1");
	else printf("%lld",ans);
}
