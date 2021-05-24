#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int save[201][201];
int n,m,k;

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

string generate(int n ,int m,int skip)
{
	if(n==0) return string(m,'o');
	if(skip<save[n+m-1][n-1])
		return "-"+generate(n-1,m,skip);
	return "o"+generate(n,m-1,skip-save[n+m-1][n-1]);

}


int main()
{
	int c;
	for(int i=0;i<201;i++)
	{
		save[i][i]=1;
		save[i][0]=1;
		for(int j=1;j<i;j++)
		{
			save[i][j]=min(1000000100,save[i-1][j-1]+save[i-1][j]);
		}
	}
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d %d %d",&n,&m,&k);
		string s = generate(n,m,k-1);
		cout << s +"\n";		
	}

}
