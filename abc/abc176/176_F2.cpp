#include <stdio.h>
#include <vector>
#define MIN -12345678

struct str{
	int x0;
	int y0;
	int value;
};
std::vector<str> temp;
int DP[2010][2010];
int x[6010];
int max[2010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=3*a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) DP[i][j] = MIN;
	DP[x[1]][x[2]] = 0;
	DP[x[2]][x[1]] = 0;
	
	for(int i=1;i<=a;i++) max[i] = MIN;
	max[x[1]] = max[x[2]] = 0;
	int max0 = 0;
	int count = 0;
	
	for(int i=3;i<3*a;i+=3)
	{
		if(x[i]==x[i+1]&&x[i+1]==x[i+2]) count++;
		else
		{
			temp.clear();
			if(x[i]==x[i+1])
			{
				for(int j=1;j<=a;j++)
				{
					temp.push_back({j,x[i+2],DP[j][x[i]]+1});
					temp.push_back({x[i+2],j,DP[j][x[i]]+1});
				}
			}
			else if(x[i]==x[i+2])
			{
				for(int j=1;j<=a;j++)
				{
					temp.push_back({j,x[i+1],DP[j][x[i]]+1});
					temp.push_back({x[i+1],j,DP[j][x[i]]+1});
				}
			}
			else if(x[i+1]==x[i+2])
			{
				for(int j=1;j<=a;j++)
				{
					temp.push_back({j,x[i],DP[j][x[i+1]]+1});
					temp.push_back({x[i],j,DP[j][x[i+1]]+1});
				}
			}
			
			temp.push_back({x[i],x[i+1],DP[x[i+2]][x[i+2]]+1});
			temp.push_back({x[i+1],x[i],DP[x[i+2]][x[i+2]]+1});
			temp.push_back({x[i],x[i+2],DP[x[i+1]][x[i+1]]+1});
			temp.push_back({x[i+2],x[i],DP[x[i+1]][x[i+1]]+1});
			temp.push_back({x[i+2],x[i+1],DP[x[i]][x[i]]+1});
			temp.push_back({x[i+1],x[i+2],DP[x[i]][x[i]]+1});
			
			temp.push_back({x[i],x[i+1],max0});
			temp.push_back({x[i+1],x[i],max0});
			temp.push_back({x[i],x[i+2],max0});
			temp.push_back({x[i+2],x[i],max0});
			temp.push_back({x[i+1],x[i+2],max0});
			temp.push_back({x[i+2],x[i+1],max0});
			
			for(int j=1;j<=a;j++)
			{
				temp.push_back({j,x[i],max[j]});
				temp.push_back({x[i],j,max[j]});
				temp.push_back({j,x[i+1],max[j]});
				temp.push_back({x[i+1],j,max[j]});
				temp.push_back({j,x[i+2],max[j]});
				temp.push_back({x[i+2],j,max[j]});
			}
			
			for(int j=0;j<temp.size();j++)
			{
				int x0 = temp[j].x0;
				int y0 = temp[j].y0;
				int value = temp[j].value;
				if(DP[x0][y0]<value)
				{
					DP[x0][y0] = value;
					max0 = max0>value?max0:value;
					max[x0] = max[x0]>value?max[x0]:value;
					max[y0] = max[y0]>value?max[y0]:value;
				}
			}
			
		}
	}
	
	int max1 = DP[x[3*a]][x[3*a]]+1;
	printf("%d",(max0>max1?max0:max1)+count);
}
