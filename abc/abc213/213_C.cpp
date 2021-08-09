#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

std::pair<int,int> P[100010];
std::vector<int> index1,index2;
std::map<int,int> hash1, hash2;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i] = std::make_pair(d,e);
	}
	
	for(int i=1;i<=c;i++) index1.push_back(P[i].first);
	for(int i=1;i<=c;i++) index2.push_back(P[i].second);
	std::sort(index1.begin(),index1.end());
	std::sort(index2.begin(),index2.end());
	index1.erase(std::unique(index1.begin(),index1.end()),index1.end());
	index2.erase(std::unique(index2.begin(),index2.end()),index2.end());
	for(int i=0;i<index1.size();i++) hash1[index1[i]] = i+1;
	for(int i=0;i<index2.size();i++) hash2[index2[i]] = i+1;
	
	for(int i=1;i<=c;i++) printf("%d %d\n",hash1[P[i].first],hash2[P[i].second]);
}