#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char e[16];
char r[16];
int m;
int size;
int check[10];
int cnt;
int save[1<<14][20][2];
int func(int *array,int taken,int pos,int pre,int pl)
{
	int ret=0;
	if(save[taken][pre][pl]!=-1)
		return save[taken][pre][pl];
	if(pos==size)
	{
		if(pl==1)
		{
			return 0;
		}
		if(pre%m==0)
		{
			return 1;
		}
		return 0;
	}
	for(int i=0;i<10;i++)
	{
		int new[10];
		int temp;
		int rpl=pl;
		int ntaken;
		if(i>r[pos]&&pl==1)
			break;
		if(i<r[pos])
			rpl=0;
		if(array[i]==0)
			continue;
		for(int j=0;j<10;j++)
		{
			new[j]=array[j];
		}
		temp = pre*10+i;
		temp = temp%m;
		new[i]--;
		ntaken=taken|(1<<size);
		ret=(ret+func(new,ntaken,pos+1,temp,rpl))%1000000007;
	}
	save[taken][pre][pl]=ret%1000000007;
	return ret%1000000007;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		cnt=0;
		scanf("%s %d",e,&m);
		size = strlen(e);
		for(int i=0;i<10;i++)
		{
			check[i]=0;
		}
		for(int i=0;i<size;i++)
		{
			r[i]= e[i]-48;
			check[r[i]]++;
		}
		for(int i=0;i<1<<14;i++)
		{
			for(int j=0;j<19;j++)
			{
				save[i][j][0]=-1;
				save[i][j][1]=-1;
			}
		}
		printf("%d\n",func(check,1,0,0,1));

	}
}
