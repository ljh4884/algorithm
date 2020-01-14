#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,q;
int array[200000];
int check,x,y,d;

int func(int x,int y,int d)
{

}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n-1;i++)
		scanf("%d",&array[i]);
	for(int cnt=0;cnt<q;cnt++)
	{
		scanf("%d",&check);
		if(check==0)
		{
			scanf("%d %d",&x,&y);
			x = x-1;
			y = y-1;
			if(x>y)
			{
				int temp=x;
				x=y;
				y=temp;
			}
			int temp=0;
			for(int i=x;i<y;i++)
			{
				temp = temp^array[i]; 
			}
			printf("%d\n",temp);
		}
		else
		{
			scanf("%d %d %d",&x,&y,&d);
			int temp = d;
			x = x -1;
			y = y -1;
			if(x>y)
			{
				int temp=x;
				x=y;
				y = temp;
			}
			for(int i = x;i<y;i++)
			{
				temp=temp^array[i];
			}
			printf("%d\n",temp);
		}
	}
}
