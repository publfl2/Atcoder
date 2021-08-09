#include <stdio.h>
#include <map>

char win[110][110];
char x[110];
std::map< std::pair<char,char> , char > M;
int main()
{
	M[std::make_pair('R','R')] = 'R';
	M[std::make_pair('R','S')] = 'R';
	M[std::make_pair('R','P')] = 'P';
	M[std::make_pair('S','R')] = 'R';
	M[std::make_pair('S','S')] = 'S';
	M[std::make_pair('S','P')] = 'S';
	M[std::make_pair('P','R')] = 'P';
	M[std::make_pair('P','S')] = 'S';
	M[std::make_pair('P','P')] = 'P';
	
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x);
	for(int i=0;i<a;i++) win[i][0] = x[i];
	
	long long int S = 1;
	for(int i=1;i<=b;i++)
	{
		for(int j=0;j<a;j++)
		{
			char A = win[j][i-1];
			char B = win[(j+S)%a][i-1];
			win[j][i] = M[std::make_pair(A,B)];
		}
		S*=2;
		S%=a;
	}
	printf("%c",win[0][b]);
}
