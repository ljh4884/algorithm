#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

string array[15];
int k;
int rec[16][1<<15];
int save[16][1<<15];
string merge(string a,string b)
{
	int sa = a.size();
	int sb = b.size();
	int check = 1;
	for(int i=0;i<sa;i++)
	{
		if(a[i]==b[0])
		{
			check=0;
			int j=1;
			for(j=1;j+i<sa;j++)
			{
				if(j>=sb)
					break;
				if(a[i+j]!=b[j])
					check=1;
			}
			if(check==0)
			{
				b=b.substr(j);
			}
		}
	}
	a=a+b;
	return a;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int func(int last,int bit)
{
	int check=0;
	int max=999999;
	int temp;
	int tempsize;
	string result;
	if(save[last+1][bit]!=-1)
		return save[last+1][bit];
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			check=1;
			break;
		}
	}
	if(check==0)
		return 0;
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			if(last==-1)
				temp = array[i].size();
			else 
				temp = merge(array[last],array[i]).size()-array[last].size();
			tempsize = func(i,(bit|(1<<i)));
			if(max>temp+tempsize)
			{
				max = temp+func(i,(bit|(1<<i)));
				rec[last+1][bit]=i;
			}
		}
	}
	
	save[last+1][bit]=max;
	return max;
}
string recon(int last,int bit)
{
	int check=0;
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
			check=1;
	}
	if(check==0)
		return "";
	int temp = rec[last+1][bit];
	return merge(array[temp],recon(temp,bit|(1<<temp)));
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&k);
		
		for(int i=0;i<k;i++)
		{
			cin >> array[i];
			for(int j=0;j<i;j++)
			{
				if(array[j].compare(merge(array[j],array[i]))==0)
				{
					k--;
					i--;
					break;
				}
				if(array[i].compare(merge(array[i],array[j]))==0)
				{
					array[j]=array[i];
					k--;
					i--;
					break;
				}

			}
			for(int j=0;j<(1<<k);j++)
			{
				save[i][j]=-1;
			}
		}
		for(int i=0;i<(1<<k);i++)
		{
			save[k][i]=-1;
		}
		func(-1,0);
		cout<<recon(-1,0);

	}
}
