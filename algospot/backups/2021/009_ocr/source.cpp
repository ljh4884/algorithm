#include <stdio.h>
#include <string.h>
int m,q;
char word[500][11];
double B[500];
double T[500][500];
double M[500][500];

int n;
char test[20][100][11];


int w2i(char *input)
{
	for(int i=0;i<m;i++)
		if(strcmp(input,word[i]) == 0)
			return i;
	return -1;
}

char *i2w(int input)
{
	return word[input];
}

void func(int pos, int prev)
{
	int input = w2i(word[pos]);
	double max = 0;
	int max_i = -1;
	double ret = 0;
	if(pos == 0)
	{
		for(int i=0;i<m;i++)
		{
			ret = B[i] * M[i][input];
			if(ret > max)
			{
				max = ret;
				max_i = i;
			}
		}
		printf("%s ",i2w(max_i));
		func(pos+1,max_i);
		return;
	}
	if(pos == n)
		return;
	
	for(int i=0;i<m;i++)
	{
		ret = M[i][input] * T[prev][i];
		if(ret > max)
		{
			max = ret;
			max_i = i;
		}
	}
	
	printf("%s ",i2w(max_i));
	func(pos+1,max_i);
	return;
}

int main()
{
	scanf("%d %d",&m,&q);
	
	for(int i=0;i<m;i++)
		scanf("%s",word[i]);
	
	for(int i=0;i<m;i++)
		scanf("%lf",&B[i]);
	
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			scanf("%lf",&T[i][j]);
	
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			scanf("%lf",&M[i][j]);

	for(int cnt=0;cnt<q;cnt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",test[cnt][i]);
		func(0,-1);
		printf("\n");
	}



	

}
