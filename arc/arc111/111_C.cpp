#include <stdio.h>
#include <vector>
int x[200010],y[200010],p[200010];
std::vector<int> St;
int check[200010],inverse[200010];
std::vector< std::pair<int,int> > ans;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) scanf("%d",&p[i]);
	for(int i=1;i<=a;i++) inverse[p[i]] = i;
	for(int i=1;i<=a;i++)
	{
		St.clear();
		int t = i;
		while(check[t]==0)
		{
			St.push_back(t);
			check[t] = 1;
			t = p[t];
		}
		if(St.size()<=1) continue;
		
		for(int j=0;j<St.size();j++)
		{
			if(x[St[j]]<=y[p[St[j]]])
			{
				printf("-1");
				return 0;
			}
		}
		
		int min = 1234567890;
		for(int j=0;j<St.size();j++) min = min<y[St[j]]?min:y[St[j]];
		int k;
		for(int j=0;j<St.size();j++) if(y[St[j]]==min) k = St[j];
		k = inverse[k];
		
		for(int j=0;j+1<St.size();j++)
		{
			ans.push_back(std::make_pair(inverse[k],k));
			k = inverse[k];
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}
