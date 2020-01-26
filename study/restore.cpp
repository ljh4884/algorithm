/* 아쉽게도 한문자열 조각이 다른 문자열 조각에 포함될 경우를 해결하지 못하여
 * 다른 코드들을 참고하였다.
 * 여태까지 푼 문제들중 가장 긴시간을 소요한것 같다.
 * 알고리즘의 문제라기보단 중복된 문자열을 찾아 지우는 과정이 문제라고 생각한다.
 * 그냥 merge함수에 문제가 있는듯?
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int k;
string array[15];
int save[15][1<<15];
int over[15][15];

string merge(string a, string b)
{
	int sa = a.size();
	int sb = b.size();

	for(int i=0;i<sa;i++)
	{
		if(a[i]==b[0])
		{
			int j;
			for(j=1;i+j<sa;j++)
			{
				if(j==sb)
					break;
				if(a[i+j]!=b[j])
					break;
			}
			if(j==sb||i+j==sa)
			{
				b=b.substr(j);
			}
		}
	}
	a=a+b;
	return a;
}

int func(int last, int bit)
{
	if(bit==(1<<k)-1)
		return 0;
	int& ret = save[last][bit];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			int temp = over[last][i]+func(i,bit+(1<<i));
			ret = max(ret,temp);
		}
	}
	return ret;
}

string recon(int last,int bit)
{
	if(bit==(1<<k)-1)
		return "";
	for(int i=0;i<k;i++)
	{
		if(bit&(1<<i))
			continue;
		int use = func(i,bit+(1<<i)) + over[last][i];
		if(func(last,bit)==use)
			return (array[i].substr(over[last][i])+recon(i,bit+(1<<i)));
	}
	return "SSIBAL";
}
int getover(string a,string b)
{
	for(int i=min(a.size(),b.size());i>0;i--)
	{
		if(a.substr(a.size()-i)==b.substr(0,i))
			return i;
	}
	return 0;
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int ret = -1;
		int start;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			cin>>array[i];
			/*for(int j=0;j<i;j++)
			{
				if(array[j].compare(merge(array[j],array[i]))==0)
				{
					i--;
					k--;
					break;
				}
				if(array[i].compare(merge(array[i],array[j]))==0)
				{
					array[j]=array[i];
					i--;
					k--;
					break;
				}
			}*/
		}
		while(1)
		{
			bool remove = false;
			for(int i=0;i<k&&!remove;i++)
			{
				for(int j=0;j<k;j++)
				{
					if(i!=j&&array[i].find(array[j])!=string::npos)
					{
						array[j]=array[k-1];
						k--;
						remove = true;
					}
				}
			}
			if(!remove)
				break;
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				//over[i][j]=getover(array[i],array[j]);
				over[i][j]=array[i].size()+array[j].size()-merge(array[i],array[j]).size();
			}
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<(1<<15);j++)
			{
				save[i][j]=-1;
			}
		}
		for(int i=0;i<k;i++)
		{
			if(ret<func(i,(1<<i)))
			{
				ret = func(i,(1<<i));
				start = i;
			}
		}
		cout << array[start]+recon(start,(1<<start))+"\n";

	}
}
