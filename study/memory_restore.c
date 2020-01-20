#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int k;
char array[15][41];
char *merge(char *a,char *b)
{
	int sa = strlen(a);
	int sb = strlen(b);
	int check;
	char *result = (char*)malloc(sizeof(char)*(sa+sb));
	int check2=0;
	strcpy(result,a);
	for(int i=0;i<sa;i++)
	{
		
		if(a[i]==b[0])
		{
			check =1;
			for(int j=1;j<sb;j++)
			{
				if(i+j>=sa)
					break;
				if(a[i+j]!=b[j])
				{
					check=0;
					break;
				}
			}
			if(check==1)
			{
				for(int j=0;j<i;j++)
				{
					result[j]=a[j];
				}
				for(int j=0;j<sb;j++)
				{
					result[i+j]=b[j];
				}
				check2=1;
				break;
			}
		}
	}
	if(check2==0)
	{
		int i=0;
		for(i=0;i<sa;i++)
		{
			result[i]=a[i];
		}
		for(int j=0;j<sb;j++)
		{
			result[i+j]=b[j];
		}
	}

	

	return result;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

char *func(char *input,int bit)
{
	int check=0;
	char *result = (char*)malloc(sizeof(char)*(strlen(input)+40));
	int max=9999999;
	int temp;
	char * tempstr = (char*)malloc(sizeof(char)*(strlen(input)+40));
	int nbit;
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			check=1;
			break;
		}
	}
	if(check==0)
	{
		return input;
	}
	for(int i=0;i<k;i++)
	{
		if((bit&(1<<i))==0)
		{
			nbit =bit;
			nbit = nbit | (1<<i);
			strcpy(tempstr,func(merge(input,array[i]),nbit));
			temp = strlen(tempstr);
			if(max>temp)
			{
				max = temp;
				strcpy(result,tempstr);
			}
		}
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
			scanf("%s",array[i]);
		printf("%s\n",func("",0));			
	}
}
