#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define o struct ocr
struct ocr
{
	float p;
	int array[500];
};

float M[500][500];
float T[500][500];

int n,m,q;
float S[500];
char array[500][11];
char this[500][11];



float max(float a,float b)
{
	if(a>b)
		return a;
	else
		return b;
}
int change(char *name)
{
	for(int i=0;i<m;i++)
	{
		if(strcmp(array[i],name)==0)
			return i;
	}
	return -1;
}

o func(int pos,o input)
{
	int pre = input.array[pos-1];
	float table[m];
	o ans;
	float result;
	if(pos==0)
	{
		result=0;
		for(int i=0;i<m;i++)
		{
			o temp;
			temp.array[0]=i;
			temp.p=S[i];
			temp=func(pos+1,temp);
			if(result<temp.p)
			{
				memcpy(&ans,&temp,sizeof(o));
			}
		}
		return ans;
	}
	if(pos==n)
		return input;
	result=0;
	for(int i=0;i<m;i++)
	{
		
		o temp;
		temp.array[pos]=i;
		table[i] = T[pre][i]*M[change(this[pos])][i];
		temp.p = temp.p*table[i];
		temp = func(pos+1,temp);
		if(result<temp.p)
		{
			memcpy(&ans,&temp,sizeof(o));
		}
		printf("%f\n",table[i]);

	}
	printf("%f\n",ans.p);
	return ans;
}

int main()
{
	scanf("%d %d",&m,&q);
	for(int i=0;i<m;i++)
		scanf("%s",array[i]);
	for(int i=0;i<m;i++)
		scanf("%f",&S[i]);
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			scanf("%f",&T[i][j]);
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			scanf("%f",&M[i][j]);


	for(int cnt=0;cnt<q;cnt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",this[i]);
		o temp;
		temp = func(0,temp);
		for(int i=0;i<n;i++)
		{
			printf("%s ",array[temp.array[i]]);
		}
		printf("\n");
	}
	
		

}
