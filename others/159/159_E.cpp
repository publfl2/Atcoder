#include <stdio.h>
#include <vector>

int a,b,c;
std::vector<int> cut;
int sum[1010][1010],x[1010][1010];
int area(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}
int ans = 12345678;
int check[1010];
void func(int k)
{
	if(k>=a)
	{
		cut.push_back(k);
		int count = cut.size()-2;
		for(int i=1;i<cut.size();i++) check[i] = 0;
		for(int j=1;j<=b;j++)
		{
			for(int i=1;i<cut.size();i++) check[i] += area(cut[i-1]+1,j,cut[i],j);
			for(int i=1;i<cut.size();i++)
			{
				if(check[i]>c)
				{
					count++;
					for(int k=1;k<cut.size();k++)
					{
						check[k] = area(cut[k-1]+1,j,cut[k],j);
						if(check[k]>c)
						{
							cut.pop_back();
							return;
						}
					}
				}
			}
		}
		ans = ans<count?ans:count;
		cut.pop_back();
	}
	else
	{
		func(k+1);
		cut.push_back(k);
		func(k+1);
		cut.pop_back();
	}
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%1d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) sum[i][j] = sum[i][j-1] + x[i][j];
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) sum[i][j] += sum[i-1][j];
	cut.push_back(0);
	func(1);
	printf("%d",ans);
}
