#include <stdio.h>
#include <map>

std::map< std::pair<int,int> , int> check;
struct str{
	int x0;
	int y0;
	int type;
}dest;
long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		check.clear();
		int a,b,c,d,e,f;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		check[std::make_pair(a,b)] = 1;
		check[std::make_pair(c,d)] = 1;
		check[std::make_pair(e,f)] = 1;
		int min1 = a<c?a<e?a:e:c<e?c:e;
		int max1 = a>c?a>e?a:e:c>e?c:e;
		int min2 = b<d?b<f?b:f:d<f?d:f;
		int max2 = b>d?b>f?b:f:d>f?d:f;
		
		if(check[std::make_pair(min1,min2)]==0) dest = {max1,max2,3};
		if(check[std::make_pair(min1,max2)]==0) dest = {max1,min2,1};
		if(check[std::make_pair(max1,min2)]==0) dest = {min1,max2,4};
		if(check[std::make_pair(max1,max2)]==0) dest = {min1,min2,2};
		
		if(dest.x0==1&&dest.y0==1&&dest.type==3)
		{
			printf("1\n");
			continue;
		}
		
		long long int A,B;
		int start1, start2;
		
		if(dest.x0<0)
		{
			if(dest.type==1||dest.type==3) start1 = 1, A = 2*abs(dest.x0)+1;
			else start1 = 1, A = 2*abs(dest.x0);
		}
		else if(dest.x0==0)
		{
			if(dest.type==1||dest.type==3) start1 = 1, A = 2*abs(dest.x0)+1;
			else start1 = -1, A = 2*abs(dest.x0);
		}
		else
		{
			if(dest.type==2||dest.type==4) start1 = 2, A = 2*abs(dest.x0);
			else start1 = 2, A = 2*abs(dest.x0)-1;
		}
		
		if(dest.y0<0)
		{
			if(dest.type==3||dest.type==4) start2 = 2, B = 2*abs(dest.y0)+1;
			else start2 = 2, B = 2*abs(dest.y0);
		}
		else if(dest.y0==0)
		{
			if(dest.type==3||dest.type==4) start2 = 2, B = 2*abs(dest.y0)+1;
			else start2 = -1, B = 2*abs(dest.y0);
		}
		else
		{
			if(dest.type==1||dest.type==2) start2 = 1, B = 2*abs(dest.y0);
			else start2 = 1, B = 2*abs(dest.y0)-1;
		}
		
		if(start1==-1||start2==-1) printf("%lld\n",max(A,B));
		else if(start1==start2) printf("%lld\n",max(A,B));
		else
		{
			long long int S = max(A,B+1);
			long long int T = max(A+1,B);
			printf("%lld\n",S<T?S:T);
		}
	}
}
