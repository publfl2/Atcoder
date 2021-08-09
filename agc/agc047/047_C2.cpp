#include <stdio.h>
#include <complex>
#include <vector>
#define PI 3.1415926535897932384626
#define MOD 200003

void FFT(std::vector< std::complex<long double> > &V, std::complex<long double> root, bool type)
{
	if(V.size()==1) return;
	
	//printf("%d?\n",V.size());
	std::vector< std::complex<long double> > V1,V2;
	for(int i=0;i<V.size();i+=2)
	{
		V1.push_back(V[i]);
		V2.push_back(V[i+1]);
	}
	std::complex<long double> newRoot = root*root;
	FFT(V1,newRoot,type);
	FFT(V2,newRoot,type);
	
	int n = V.size();
	std::complex<long double> p = 1;
	
	for(int i=0;i<n/2;i++)
	{
		V[i] = V1[i] + p*V2[i];
		p*=root;
	}
	for(int i=0;i<n/2;i++)
	{
		V[n/2+i] = V1[i] + p*V2[i];
		p*=root;
	}
	if(type)
	{
		for(int i=0;i<n;i++) V[i]/=2;
	}
}

int count[200010],position[200010];
long long int ans[600010];
std::vector< std::complex<long double> > V1,V2,V3;
int main()
{
	int p = 1;
	for(int i=0;i<MOD;i++)
	{
		position[p] = i;
		p*=2, p%=MOD;
	}
	long long int C = 0;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==0) continue;
		C += ((long long int)b*b)%MOD;
		count[position[b]]++;
	}
	int n = 524288;
	for(int i=0;i<MOD;i++) V1.push_back(count[i]);
	for(int i=MOD;i<n;i++) V1.push_back(0);
	std::complex<long double> root = std::exp(std::complex<long double>(0,(2*PI)/n));
	FFT(V1,root,false);
	for(int i=0;i<n;i++) V3.push_back(V1[i]*V1[i]);
	FFT(V3,std::complex<long double>(1,0)/root,true);
	for(int i=0;i<V3.size();i++) ans[i] = (long long int)((V3[i].real())+0.5);
	
	long long int sum = 0;
	long long int k = 1;
	for(int i=0;i<n;i++)
	{
		sum += k*ans[i];
		k*=2, k%=MOD;
	}
	printf("%lld",(sum-C)/2);
}
