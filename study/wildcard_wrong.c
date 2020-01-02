#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *wild, char *name);

int check_under(char *wild, char *name)
{
	
	int sn = strlen(name);
	if(strlen(wild)==1)
		return 1;

	for(int i=0;i<sn;i++)
	{
		if(check(&wild[1],&name[i])==1)
			return 1;
		
	}

	return 0;
}

int check(char *wild, char *name)
{
	if(strlen(wild)==1)
	{
		if(strlen(name)==1)
		{
			if(wild[0]=='?')
			{
				return 1;
			}
			else if(wild[0]==name[0])
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	if(wild[0]!='*')
	{
		if(wild[0]=='?')
		{
			return check(&wild[1],&name[1]);	
		}
		else
		{
			if(wild[0]==name[0])
			{
				return check(&wild[1],&name[1]);
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return check_under(&wild[0],&name[0]);
	}
	
}

void swap(char *a, char *b)
{
	char temp[101];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);

}

int main()
{
	int c,n;
	
	char name[50][101];
	char wildcard[101];
	char result[50][101];
	int rcnt;
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		rcnt=0;
		scanf("%s",wildcard);
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			scanf("%s",name[i]);
			if(check(wildcard,name[i])==1)
			{
				strcpy(result[rcnt],name[i]);
				rcnt++;
			}
		}

		for(int i=0;i<rcnt-1;i++)
		{
			for(int j=i+1;j<rcnt;j++)
			{
				if(strcmp(result[i],result[j])>0)
					swap(result[i],result[j]);
			}
		}
		for(int i=0;i<rcnt;i++)
			printf("%s\n",result[i]);

		
		
	}
}
