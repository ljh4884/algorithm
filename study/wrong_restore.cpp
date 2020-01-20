#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

int k;
string array[15];
string save[1<<16];
string merge(string a,string b)
{
	int sa = a.size();
	int sb = b.size();
	int check;
	int check2=1;
	for(int i=0;i<sa;i++)
	{
		if(a[i]==b[0])
		{
			check=0;
			int j;
			for(j=i+1;j<sa;j++)
			{
				if(j-i>=sb)
					break;
				if(a[j]!=b[j-i])
				{
					check=1;
				}
			}
			if(check==0)
			{
				
				check2=0;
				b=b.substr(j-i);
				a = a+b;
			}
			
		}
	}
	if(check2==1)
	{
		a = a+b;
	}
	return a;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

string func(string input,int bit)
{
	string tempstr;
	string result;
	int temp;
	int max=9999999;
	int check=0;

	if(save[bit]!="-")
		return save[bit];
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
			check=1;
	}
	if(check==0)
	{
		return input;
	}
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			tempstr = func(merge(input,array[i]),bit|(1<<i));
			temp = tempstr.size();
			
			if(temp<max)
			{
				max = temp;
				result = tempstr;
			}
		}
	}
	save[bit]=result;
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
			cin>>array[i];
		}
		for(int i=0;i<(1<<16);i++)
		{
			save[i]="-";
		}
		cout << func("",0)+"\n";

	}
}
