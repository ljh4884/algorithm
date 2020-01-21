#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int k;
string array[15];
int save[16][1<<16];

string merge(string a, string b)
{
	int sa = a.size();
	int sb = b.size();
	int check=1;
	for(int i=0;i<sa;i++)
	{
		if(a[i]==b[0])
		{
			check=0;
			int j;
			for(j=1;i+j<sa;j++)
			{
				if(j==sb)
					break;
				if(a[i+j]!=b[j])
				{
					check=1;
					break;
				}

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
	if(save[last+1][bit]!=-1)
		return save[last+1][bit];
	int max =99999;
	int temp;
	if(bit==(1<<k)-1)
		return 0;
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			if(last==-1)
				temp = array[i].size();
			else
				temp = merge(array[last],array[i]).size()-array[last].size();
			temp = temp+func(i,bit|(1<<i));
			if(temp<max)
			{
				max= temp;
			}
		}
	}
	save[last+1][bit]=max;
	return max;
}
string recon()
{
	int bit = 0;
	int temp;
	int max=99999;
	int str;
	string result="";
	for(int i=0;i<k;i++)
	{
		max=99999;
		for(int j=0;j<k;j++)
		{
			if((bit&(1<<j))==0)
			{
				//temp = array[j].size()+func(j,bit|(1<<j));
				temp = merge(result,array[j]).size()+func(j,bit|(1<<j));
				//printf("%d %d\n",j,temp);
				if(temp<max)
				{
					
					max = temp;
					str = j;
				}
			}
		}
		bit = bit+(1<<str);
		result = merge(result,array[str]);
	}
	return result;
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
			array[i].clear();
			cin >> array[i];
			/*for(int j=0;j<i;j++)
			{
				if(array[j].compare(merge(array[j],array[i]))==0)
				{
					k--;
					i--;
				}
				else if(array[i].compare(merge(array[i],array[j]))==0)
				{
					array[j]=array[i];
					k--;
					i--;

				}
			}	*/
		}
		for(int i=0;i<k+1;i++)
		{
			for(int j=0;j<(1<<15);j++)
			{
				save[i][j]=-1;
			}
		}
		//func(-1,0);
		cout << recon()+"\n";
	}
}
