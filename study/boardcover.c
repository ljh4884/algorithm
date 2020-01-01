#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkr(int **array,int h,int w)
{
	int i=0;
	int temp=0;
	for(i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(array[i][j]==0)
			{
				temp = 1;
				break;
			}
		}
		if(temp==1)
			break;
	}
	return i;
}

int checkc(int *array,int w)
{
	int i=0;
	for(i=0;i<w;i++)
	{
		if(array[i]==0)
			break;
	}
	return i;
}
int **make(int **array,int h,int w)
{
	int **temp = (int**)malloc(sizeof(int*)*h);
	for(int i=0;i<h;i++)
	{
		temp[i] = (int*)malloc(sizeof(int)*w);
		for(int j=0;j<w;j++)
		{
			temp[i][j]=array[i][j];
		}
	}
	return temp;
}

int check(int **array,int h,int w)
{
	int i=0;
	int sum=0;
	if((i=checkr(array,h,w))==h)
	{
		return 1;
	}
	else
	{
		int j = checkc(array[i],w);
		int **temp;
		if(i>0)
		{
			if(j>0)
			{
				if(array[i-1][j]==0&&array[i][j-1]==0)
				{
					temp = make(array,h,w);
					temp[i][j]=1;
					temp[i-1][j]=1;
					temp[i][j-1]=1;
					sum = sum+check(temp,h,w);
				}
				if(array[i-1][j-1]==0)
				{
					//1
					if(array[i-1][j]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i-1][j-1]=1;
						temp[i-1][j]=1;
						sum = sum+check(temp,h,w);
					}
					//2
					if(array[i][j-1]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i-1][j-1]=1;
						temp[i][j-1]=1;
						sum = sum+check(temp,h,w);
					}
				}
				

			}
			if(j!=w-1)
			{
				if(array[i-1][j]==0&&array[i][j+1]==0)
				{
					temp = make(array,h,w);
					temp[i][j]=1;
					temp[i-1][j]=1;
					temp[i][j+1]=1;
					sum = sum+check(temp,h,w);
				}
				
				if(array[i-1][j+1]==0)
				{
					if(array[i-1][j]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i-1][j+1]=1;
						temp[i-1][j]=1;
						sum = sum+check(temp,h,w);
					}
					if(array[i][j+1]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i-1][j+1]=1;
						temp[i][j+1]=1;
						sum = sum+ check(temp,h,w);
					}
				
				}
			}

		}
		if(i!=h-1)
		{
			if(j>0)
			{
				if(array[i][j-1]==0&&array[i+1][j]==0)
				{
					temp = make(array,h,w);
					temp[i][j]=1;
					temp[i][j-1]=1;
					temp[i+1][j]=1;
					sum = sum+check(temp,h,w);
				}
				if(array[i+1][j-1]==0)
				{
					if(array[i][j-1]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i+1][j-1]=1;
						temp[i][j-1]=1;
						sum = sum +check(temp,h,w);
					}
					if(array[i+1][j]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i+1][j-1]=1;
						temp[i+1][j]=1;
						sum = sum + check(temp,h,w);
					}
				}
			}
			if(j!=w-1)
			{
				if(array[i+1][j]==0&&array[i][j+1]==0)
				{
					temp = make(array,h,w);
					temp[i][j]=1;
					temp[i+1][j]=1;
					temp[i][j+1]=1;
					sum = sum+check(temp,h,w);
				}
				if(array[i+1][j+1]==0)
				{
					if(array[i][j+1]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i+1][j+1]=1;
						temp[i][j+1]=1;
						sum = sum +check(temp,h,w);
					}
					if(array[i+1][j]==0)
					{
						temp = make(array,h,w);
						temp[i][j]=1;
						temp[i+1][j+1]=1;
						temp[i+1][j]=1;
						sum=sum+check(temp,h,w);
					}
				}
			}
		}
	}
	return sum;
}

int main()
{
	int c,h,w;


	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int **array;
		int size=0;
		char temp[20];
		scanf("%d %d",&h,&w);

		array = (int**)malloc(sizeof(int*)*h);
		for(int i=0;i<h;i++)
		{
			array[i] = (int*)malloc(sizeof(int)*w);
		}

		for(int i=0;i<h;i++)
		{
			scanf("%s",temp);
			for(int j=0;j<w;j++)
			{
				if(temp[j]=='#')
					array[i][j]=1;
				else
				{
					array[i][j]=0;
					size++;
				}
			}
		}

		if(size%3!=0)
		{
			printf("%d\n",0);
		}
		else
		{
			printf("%d\n",check(array,h,w));
		}
	}
}
