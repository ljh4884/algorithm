#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int array[101];
int func(int n)
{
	if(array[n]==-1)
		array[n] = ((func(n-1)%1000000007)+(func(n-2)%1000000007))%1000000007;
	return array[n];
}

int main()
{
	int c;
	for(int i=0;i<101;i++)
	{
		array[i]=-1;
	}
	array[0]=1;
	array[1]=1;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int n;
		int temp;
		scanf("%d",&n);

		if(n%2==0)
		{
			int temp = func(n)-func(n/2);
			if(temp<0)
				temp+=1000000007;
			temp = temp - func(n/2-1);
			if(temp<0)
				temp+=1000000007;
			printf("%d\n",temp);
		}
		else
		{
			int temp = func(n)-func(n/2);
			if(temp<0);
				temp+=1000000007;
			printf("%d\n",temp);
		}
		
	}
}
