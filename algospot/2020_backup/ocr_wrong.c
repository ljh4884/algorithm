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
}
o func(int i,o input)
{
	if(i==n)
		return input;
	float table[m];
	float sum=0;
	int pre = input.array[i-1];
	float result=0;
	int index;

	
		for(int j=0;j<m;j++)
		{
			table[j] = T[pre][j]*M[change(this[i])][j];
			sum+=table[j];
		}
		if(sum!=0)
		{
			for(int j=0;j<m;j++)
				table[j] = table[j]/sum;
		}
	
	o ans;
	for(int j=0;j<m;j++)
	{
		float p;
		o temp; 
		memcpy(&temp,&input,sizeof(o));
		temp.p = temp.p*table[j];
		temp.array[i]=j;
		temp = func(i+1,temp);
		if(result<temp.p)
		{
			memcpy(&ans,&temp,sizeof(o));
			result = temp.p;
		}
	
	}
	return ans;
	
	
}

int main()
{
	char temp[6000];
	int i=0;
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
		o des;
		float result=0;
		char temp[6000];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",this[i]);
		for(int i=0;i<m;i++)
		{
			o ans;
			ans.p=S[i];
			ans.array[0] = i;
			ans = func(1,ans);
			if(ans.p>result)
			{
				memcpy(&des,&ans,sizeof(o));
			}
			printf("%d %f %f\n",i,S[i],ans.p);
		}
		for(int i=0;i<n;i++)
			printf("%s ",array[des.array[i]]);
		printf("\n");
		

		
	}
	
		

}
