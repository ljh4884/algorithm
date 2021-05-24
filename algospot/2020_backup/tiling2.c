#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int save[101];
int func(int n)
{
	if(save[n]==-1)
		save[n] = ((func(n-1)%1000000007)+(func(n-2)%1000000007))%1000000007;
	return save[n];

}

int main()
{
	int c;
	for(int i=0;i<101;i++)
	{
		save[i]=-1;
	}
	save[0]=1;
	save[1]=1;
	scanf("%d",&c);
	for(int i=0;i<c;i++)
	{
		int n;
		scanf("%d",&n);
		
		printf("%d\n",func(n));
	}
}
