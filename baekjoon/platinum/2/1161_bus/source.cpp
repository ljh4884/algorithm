#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
const int MIN_VALUE = -10000000;
int k,n,c;


map<int, vector<int>> bus_end;
map<int, vector<int>> bus_count;

int func(int pos, int count)
{
	if(pos == n)
		return 0;
	if(count > c)
		return MIN_VALUE;
}

int main()
{
	scanf("%d %d %d",&k,&n,&c);
	vector<int> temp_vec;
	for(int i=0;i<n;i++)
	{
		bus_end.insert({i,temp_vec});
	}
	int start,end,count;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&start,&end,&count);
		bus_end.find(start)->second.push_back(end);
		bus_count.find(start)->second.push_back(count);
		
	}
}
