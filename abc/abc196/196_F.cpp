#include <stdio.h>
#include <string.h>
#include <vector>
#include <atcoder/convolution>

std::vector<int> V1,V2,V3,V4,V5,V6;
char x[1000010],y[1000010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	for(int i=1;i<=a;i++) V1.push_back(0);
	for(int i=1;i<=a;i++) V2.push_back(0);
	for(int i=1;i<=b;i++) V3.push_back(0);
	for(int i=1;i<=b;i++) V4.push_back(0);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0') V1[i-1] = 1;
		else V2[i-1] = 1;
	}
	for(int i=1;i<=b;i++)
	{
		if(y[i]=='0') V3[i-1] = 1;
		else V4[i-1] = 1;
	}
	
	std::reverse(V3.begin(),V3.end());
	std::reverse(V4.begin(),V4.end());
	
	V5 = atcoder::convolution(V1,V3);
	V6 = atcoder::convolution(V2,V4);
	
	int ans = 0;
	for(int i=b-1;i<=a-1;i++)
	{
		int t = V5[i]+V6[i];
		ans = ans>t?ans:t;
	}
	printf("%d",b-ans);
}