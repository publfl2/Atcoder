#include <stdio.h>
#include <vector>

std::vector<int> V,V2;
int check[10010];
int main()
{
	for(int i=6;i<=10000;i+=6) check[i] = 1;
	for(int i=10;i<=10000;i+=10) check[i] = 1;
	for(int i=15;i<=10000;i+=15) check[i] = 1;
	check[6] = 0, check[10] = 0, check[15] = 0;
	V.push_back(6);
	V.push_back(10);
	V.push_back(15);
	for(int i=1;i<=10000;i++) if(check[i]==1) V2.push_back(i);
	
	//printf("%d\n",V2.size());
	int a;
	scanf("%d",&a);
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
	for(int i=0;i<a-3;i++) printf("%d ",V2[i]);
}