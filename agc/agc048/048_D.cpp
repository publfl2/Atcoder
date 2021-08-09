#include <stdio.h>
#include <vector>

int mex(std::vector<int>& V)
{
	int check[11]={};
	for(int i=0;i<V.size();i++) if(V[i]<=10) check[V[i]] = 1;
	for(int i=0;i<=10;i++) if(check[i]==0) return i;
}
int x[110];
int func(int s, int t, int type1, int type2)
{
	if(type1==0) return func(s+1,t,3,type2);
	if(type2==0) return func(s,t-1,type1,3);
	if(x[s]==1&&type1!=1) return func(s,t,1,type2);
	if(x[s]==2&&type1!=2) return func(s,t,2,type2);
	if(x[t]==1&&type2!=1) return func(s,t,type1,1);
	if(x[t]==2&&type2!=2) return func(s,t,type1,2);
	if(s==t)
	{
		if(type1==1||type2==1) return 1;
		else if(type1==2||type2==2) return 2;
		else return 3;
	}
	
	int h1 = x[s], h2 = x[t];
	std::vector<int> V;
	for(int i=0;i<=2&&i<type1;i++) V.push_back(func(s,t,i,type2));
	for(int j=0;j<=2&&j<type2;j++) V.push_back(func(s,t,type1,j));
	return mex(V);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int k = func(1,a,3,3);
		printf("%s\n",k==0?"Second":"First");
	}
}
