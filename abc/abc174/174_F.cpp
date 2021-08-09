#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
	int index;
	int ans;
}y[500010];
bool cmp(str a, str b)
{
	if(a.x0/700==b.x0/700) return a.y0<b.y0;
	return (a.x0/700)<(b.x0/700);
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

int C = 0;
int count[500010];
void func(int k)
{
	if(count[k]==0) C++;
	count[k]++;
}
void func2(int k)
{
	if(count[k]==1) C--;
	count[k]--;
}

int x[500010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		y[i]={c,d,i,0};
	}
	std::sort(y+1,y+b+1,cmp);
	
	for(int i=y[1].x0;i<=y[1].y0;i++) func(x[i]);
	y[1].ans = C;
	
	int L = y[1].x0, R = y[1].y0;
	for(int i=2;i<=b;i++)
	{
		if(y[i].y0>=R) while(R<y[i].y0) func(x[++R]);
		else while(R>y[i].y0) func2(x[R--]);
		
		if(y[i].x0<=L) while(L>y[i].x0) func(x[--L]);
		else while(L<y[i].x0) func2(x[L++]);
		
		y[i].ans = C;
	}
	std::sort(y+1,y+b+1,cmp2);
	for(int i=1;i<=b;i++) printf("%d\n",y[i].ans);
}
