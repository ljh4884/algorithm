#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char **plat,char *input,int x,int y)
{
	if(strlen(input)==0)
		return 1;
	else
	{
		if(x==0)
		{
			if(y==0)
			{
				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y+1);
				return temp;
			}
			else if(y==4)
			{
				int temp=0;
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y-1);
				return temp;

			}
			else
			{
				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y+1);
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x+1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y-1);
				return temp;

			}
		}
		else if(x==4)
		{
			if(y==0)
			{
				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y+1);
				return temp;
			}
			else if(y==4)
			{
				int temp=0;
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y-1);
				return temp;
			}
			else
			{
				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y+1);
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x-1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y-1);
				return temp;
			}
		}
		else
		{
			if(y==0)
			{

				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y+1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y+1);
				return temp;
			}
			else if(y==4)
			{
				int temp=0;
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y-1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y-1);
				return temp;
			}
			else
			{
				int temp=0;
				if(plat[x][y+1]==input[0])
					temp = temp|find(plat,&input[1],x,y+1);
				if(plat[x+1][y]==input[0])
					temp = temp|find(plat,&input[1],x+1,y);
				if(plat[x+1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y+1);
				if(plat[x][y-1]==input[0])
					temp = temp|find(plat,&input[1],x,y-1);
				if(plat[x-1][y]==input[0])
					temp = temp|find(plat,&input[1],x-1,y);
				if(plat[x-1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y-1);
				if(plat[x+1][y-1]==input[0])
					temp = temp|find(plat,&input[1],x+1,y-1);
				if(plat[x-1][y+1]==input[0])
					temp = temp|find(plat,&input[1],x-1,y+1);
				return temp;
			}
		}

	}
	return 0;
}

int start(char **plat,char* input)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(plat[i][j]==input[0])
			{
				if(find(plat,&input[1],i,j)==1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int c,n;
	
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		char **plat;
		char **input;
		plat = (char**)malloc(sizeof(char*)*5);
		for(int i=0;i<5;i++)
		{
			plat[i]=(char*)malloc(sizeof(char)*5);
			scanf("%s",plat[i]);
		}
		scanf("%d",&n);
		input = (char**)malloc(sizeof(char*)*n);
		for(int i=0;i<n;i++)
		{
			input[i]=(char*)malloc(sizeof(char)*10);
			scanf("%s",input[i]);
			if(start(plat,input[i])==1)
				printf("%s YES\n",input[i]);
			else
				printf("%s NO\n",input[i]);
		}

	}
}
