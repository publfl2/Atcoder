#include <stdio.h>
#include <vector>

std::pair<long long int, long long int> func2(long long int A, long long int B)
{
	if(A==0) return std::make_pair(0,-1);
	if(B==0) return std::make_pair(1,0);
	
	if(A>B)
	{
		long long int k = A/B;
		std::pair<long long int, long long int> P = func2(A%B,B);
		return std::make_pair(P.first,k*P.first+P.second);
	}
	else
	{
		long long int k = B/A;
		std::pair<long long int, long long int> P = func2(A,B%A);
		return std::make_pair(P.first+k*P.second,P.second);
	}
}

long long int A=1, B=1;
long long int ans = 1;
std::vector<long long int> V;
void func(int k)
{
	if(k==V.size())
	{
		long long int C1,C2,C3,S;
		std::pair<long long int, long long int> P = func2(A,B);
		
		if(P.first<0)
		{
			long long int C = (-P.first)/B;
			C++;
			P.first += C*B;
			P.second += C*A;
		}
		if(P.second<0)
		{
			long long int C = (-P.second)/A;
			C++;
			P.first += C*B;
			P.second += C*A;
		}
		C1 = (P.first-1)/B;
		C2 = (P.second-1)/A;
		C3 = C1<C2?C1:C2;
		P.first -= C3*B;
		P.second -= C3*A;
		S = P.second*B;
		ans = ans<S?ans:S;
		
		long long int temp = B;
		B = A;
		A = temp;
		
		P = func2(A,B);
		
		if(P.first<0)
		{
			long long int C = (-P.first)/B;
			C++;
			P.first += C*B;
			P.second += C*A;
		}
		if(P.second<0)
		{
			long long int C = (-P.second)/A;
			C++;
			P.first += C*B;
			P.second += C*A;
		}
		C1 = (P.first-1)/B;
		C2 = (P.second-1)/A;
		C3 = C1<C2?C1:C2;
		P.first -= C3*B;
		P.second -= C3*A;
		S = P.second*B;
		ans = ans<S?ans:S;
		
		temp = B;
		B = A;
		A = temp;
		return;
	}
	else
	{
		A*=V[k];
		func(k+1);
		A/=V[k];
		B*=V[k];
		func(k+1);
		B/=V[k];
	}
}
int main()
{
	for(int i=1;i<=18;i++) ans*=10;
	long long int a;
	scanf("%lld",&a);
	
	long long int b = 2*a;
	for(long long int i=2;i*i<=2*a;i++)
	{
		if(b%i==0)
		{
			long long int S = 1;
			while(b%i==0) S*=i, b/=i;
			V.push_back(S);
		}
	}
	if(b>1) V.push_back(b);
	
	func(0);
	printf("%lld",ans);
}
