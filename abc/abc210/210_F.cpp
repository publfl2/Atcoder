#include <stdio.h>
#include <vector>

std::vector<int> V[2000010];
std::pair<int,int> P[30010];

std::vector< std::pair<int,int> > temp;
int check[30010][3],count[2000010];

std::vector<int> prime[2000010];
int check2[2000010];
int main()
{
	for(int i=2;i<=2000000;i++)
	{
		if(check2[i]==0)
		{
			for(int j=2*i;j<=2000000;j+=i) check2[j] = 1;
			for(int j=i;j<=2000000;j+=i) prime[j].push_back(i);
		}
	}
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
		V[b].push_back(i);
		V[c].push_back(i);
	}
	
	int C = 0;
	for(int i=2;i<=2000000;i++)
	{
		if(check2[i]==1) continue;
		temp.clear();
		
		for(int j=i;j<=2000000;j+=i)
		{
			for(int k=0;k<V[j].size();k++)
			{
				int t = V[j][k];
				
				if(P[t].first==j) temp.push_back(std::make_pair(t,2));
				if(P[t].second==j) temp.push_back(std::make_pair(t,1));
			}
		}
		
		for(int j=0;j<temp.size();j++)
		{
			int t;
			if(temp[j].second==1) t = P[temp[j].first].first;
			else t = P[temp[j].first].second;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]++;
				if(count[prime[t][k]]==2) C++;
			}
		}
		
		for(int j=0;j<temp.size();j++)
		{
			if(P[temp[j].first].first%i==0 && P[temp[j].first].second%i==0)
			{
				int t;
				if(temp[j].second==1) t = P[temp[j].first].first;
				else t = P[temp[j].first].second;
				for(int k=0;k<prime[t].size();k++)
				{
					count[prime[t][k]]--;
					if(count[prime[t][k]]==1) C--;
				}
				
				if(C>0) check[temp[j].first][3-temp[j].second] = 1;
				
				if(temp[j].second==1) t = P[temp[j].first].first;
				else t = P[temp[j].first].second;
				for(int k=0;k<prime[t].size();k++)
				{
					count[prime[t][k]]++;
					if(count[prime[t][k]]==2) C++;
				}
				
				continue;
			}
			
			
			int t;
			if(temp[j].second==1) t = P[temp[j].first].second;
			else t = P[temp[j].first].first;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]++;
				if(count[prime[t][k]]==2) C++;
			}
			
			if(temp[j].second==1) t = P[temp[j].first].first;
			else t = P[temp[j].first].second;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]--;
				if(count[prime[t][k]]==2) C--;
			}
			
			if(C>0) check[temp[j].first][3-temp[j].second] = 1;
			
			if(temp[j].second==1) t = P[temp[j].first].first;
			else t = P[temp[j].first].second;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]++;
				if(count[prime[t][k]]==2) C++;
			}
			
			if(temp[j].second==1) t = P[temp[j].first].second;
			else t = P[temp[j].first].first;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]--;
				if(count[prime[t][k]]==1) C--;
			}
		}
		
		for(int j=0;j<temp.size();j++)
		{
			int t;
			if(temp[j].second==1) t = P[temp[j].first].first;
			else t = P[temp[j].first].second;
			for(int k=0;k<prime[t].size();k++)
			{
				count[prime[t][k]]--;
				if(count[prime[t][k]]==1) C--;
			}
		}
	}
	
	
	for(int i=1;i<=a;i++)
	{
		if(check[i][1]==1 && check[i][2]==1)
		{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes");
}