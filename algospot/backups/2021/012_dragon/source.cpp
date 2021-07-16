#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int pow[501];
int n,p,l;
const int max_val = 1000000001;



string make(string s)
{
	string ret = "";
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == 'X')
			ret += "X+YF";
		else if(s[i] == 'Y')
			ret += "FX-Y";
		else
			ret += s[i];
	}
	return ret;
}

char func(int gen,int skip,string s)
{
	if(gen == 0)
	{
		return s[skip-1];
	}
	
	string cur = make(s);
	int pick = pow[gen-1] + 1;
	if(skip > pick)
		return func(gen-1,skip - pick,cur.substr(3));
	else if(skip < pick)
		return func(gen-1,skip,cur.substr(0,2));
	else
		return cur[2];

}


int main()
{


	pow[0] = 2;
	for(int i=1;i<501;i++)
		pow[i] = min(max_val,pow[i-1] * 2 + 1);

	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d",&n,&p,&l);

		for(int i=p;i<p+l;i++)
			printf("%c",func(n,i,"FX"));
		printf("\n");
	}
}
