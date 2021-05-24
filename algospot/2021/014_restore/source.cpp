#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string temp_name[15];
string name[15];
int n;
int size;
int save[1<<15][16];

string make(string prev, string next)
{
	int p_size = prev.size();
	int n_size = next.size();
	
	int check = 0;
	for(int i=0;i<p_size;i++)
	{
		if(prev[i] == next[0])
		{
			check = 1;
			int j = 0;
			for(;j<n_size;j++)
			{
				if(i+j >= p_size)
				{
					break;
				}
				if(prev[i+j] != next[j])
				{
					check = 0;
					break;
				}
			}
			if(check == 1)
			{
				if(j == n_size)
					return prev;
				return prev + next.substr(j);
			}
		}
	}
	return prev+next;
}


int func(int bit,int pos,int prev)
{
	if(pos == size)
		return 0;

	int cur_bit;
	int ret = 10000;

	if(save[bit][prev+1] != -1)
		return save[bit][prev+1];

	for(int i=0;i<size;i++)
	{
		cur_bit = 1<<i;

		if((bit & cur_bit) == 0)
		{
			if(prev == -1)
				ret = min(ret,(int)name[i].size() + func(cur_bit,1,i));
			else
				ret = min(ret,(int)make(name[prev],name[i]).size() - (int)name[prev].size() + func(bit|cur_bit,pos+1,i));
		}
	}
	save[bit][prev+1] = ret;
	return ret;
}

string func_2(int bit,int pos,int prev,string s)
{
	if(pos == size)
		return s;
	int cur_bit;
	for(int i=0;i<size;i++)
	{
		cur_bit = 1<<i;

		if((bit & cur_bit) == 0)
		{
			if(prev == -1)
			{
				if(func(bit,pos,prev) == (int)name[i].size() + func(cur_bit,1,i))
					return func_2(cur_bit,1,i,name[i]);
			}
			else
			{
				if(func(bit,pos,prev) == (int)make(name[prev],name[i]).size() - (int)name[prev].size() + func(bit|cur_bit,pos+1,i))
					return func_2(bit|cur_bit,pos+1,i,make(s,name[i]));
			}
		}
	}
	return "";
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int check[15];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			cin >> temp_name[i];

		for(int i=0;i<n;i++)
			check[i] = 0;

		for(int i=0;i<n;i++)
		{
			if(check[i] == 1)
				continue;
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				if(temp_name[i] == make(temp_name[i],temp_name[j]))
					check[j] = 1;
			}
		}

		size = 0;
		for(int i=0;i<n;i++)
		{
			if(check[i] == 0)
			{
				name[size] = temp_name[i];
				size++;
			}
		}

		for(int i=0;i<(1<<size);i++)
			for(int j=0;j<size+1;j++)
				save[i][j] = -1;

		cout << func_2(0,0,-1,"") << endl;
		


	}
}
