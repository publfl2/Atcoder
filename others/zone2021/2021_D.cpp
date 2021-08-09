#include <stdio.h>
#include <deque>
#include <vector>
#include <algorithm>
#include <string.h>

char x[500010];
std::vector<char> ans;
std::deque<char> D;
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int type = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='R') type = 1-type;
		else
		{
			if(type==0) D.push_back(x[i]);
			else D.push_front(x[i]);
		}
	}
	if(type==1) std::reverse(D.begin(),D.end());
	for(int i=0;i<D.size();i++)
	{
		if(ans.empty()) ans.push_back(D[i]);
		else if(ans.back()==D[i]) ans.pop_back();
		else ans.push_back(D[i]);
	}
	
	for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
}