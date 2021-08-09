#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=3*a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	
	V.push_back(x[1]);
	V.push_back(x[2]);
	for(int i=3;i<3*a;i++)
	{
		if(x[i]==x[i+1]&&x[i+1]==x[i+2]) count++;
		else
		{
			V.push_back(x[i]);
			V.push_back(x[i+1]);
			V.push_back(x[i+2]);
		}
	}
	V.push_back(x[3*a]);
	if(V.size()==3)
	{
		if(V[0]==V[1]&&V[1]==V[2])
		{
			printf("%d",count+1);
			return 0;
		}
	}
	
	int ans = 0;
	if(V[2]==V[3]||V[2]==V[4])
	{
		if(V[1]==V[2])
		{
			int S = func(5,V[0],1)+1;
			ans = ans>S?ans:S;
		}
		else if(V[0]==V[2])
		{
			int S = func(5,V[1],1)+1;
			ans = ans>S?ans:S;
		}
		else
		{
			int S = func(5,V[0],2)+1;
			ans = ans>S?ans:S;
			int S = func(5,V[1],2)+1;
			ans = ans>S?ans:S;
		}
	}
}
