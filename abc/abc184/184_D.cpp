#include <stdio.h>

int check[110][110][110];
double check2[110][110][110];

double func(int s, int t, int k)
{
	if(s>=100) return 0;
	if(t>=100) return 0;
	if(k>=100) return 0;
	if(check[s][t][k]) return check2[s][t][k];
	
	double s1 = (func(s+1,t,k)+1)*s/(s+t+k);
	double s2 = (func(s,t+1,k)+1)*t/(s+t+k);
	double s3 = (func(s,t,k+1)+1)*k/(s+t+k);
	check[s][t][k] = 1;
	return check2[s][t][k] = s1+s2+s3;
}


int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%.12lf",func(a,b,c));
}
