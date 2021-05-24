#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char array[10000];
int **save;
int n;

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}


int func(int i,int j)
{
	int temp;
	int temp2;
	int temp3;
	int temp4;
	int comp;
	if(i>=n)
	{
		return 0;
	}
	if(n-i<3)
	{
		return 999999999;
	}
	if(save[i][j-i-2]!=-1)
		return save[i][j-i-2];
	//1
	temp=0;
	temp2=0;
	temp3=0;
	temp4=0;
	comp = array[i+1]-array[i];
	for(int cnt=i+1;cnt<=j;cnt++)
	{
		if(array[i]==array[cnt])
			temp++;
		if(array[cnt-1]+1==array[cnt])
			temp2++;
		if(array[cnt-1]-1==array[cnt])
			temp3++;
		if(array[cnt-1]+comp==array[cnt])
			temp4++;
		
	}
	if(temp==j-i)
	{
		save[i][j-i-2] = 1+min(func(j+1,j+3),min(func(j+1,j+4),func(j+1,j+5)));
		return save[i][j-i-2];
	}	
	if(temp2==j-i||temp3==j-i)
	{
		return 2+min(func(j+1,j+3),min(func(j+1,j+4),func(j+1,j+5)));
		return save[i][j-i-2];
	}
	temp=0;
	for(int cnt=i+2;cnt<=j;cnt++)
	{
		if(array[cnt]==array[cnt-2])
			temp++;
	}
	if(temp==j-i-1)
	{

		save[i][j-i-2] = 4+min(func(j+1,j+3),min(func(j+1,j+4),func(j+1,j+5)));
		return save[i][j-i-2];
	}
	if(temp4==j-i)
	{
		save[i][j-i-2] = 5+min(func(j+1,j+3),min(func(j+1,j+4),func(j+1,j+5)));
		return save[i][j-i-2];
	}

	save[i][j-i-2] = 10+min(func(j+1,j+3),min(func(j+1,j+4),func(j+1,j+5)));
	return save[i][j-i-2];




}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		
		
		scanf("%s",array);
		n = strlen(array);
		save=(int**)malloc(sizeof(int*)*n);
		for(int i=0;i<n;i++)
		{
			save[i]=(int*)malloc(sizeof(int)*3);
			for(int j=0;j<3;j++)
			{
				save[i][j]=-1;
			}
		}
		printf("%d\n",min(func(0,2),min(func(0,3),func(0,4))));
	}
	return 0;
}




