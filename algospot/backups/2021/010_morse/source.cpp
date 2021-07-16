#include <stdio.h>

int n,m;
int skip, save[201][201];

const int num = 1000000001;

typedef struct data
{
	char array[201];
	int size;
}data;

int min(long long a,long long b)
{
	if(a<b)
		return a;
	else
		return b;
}

void func(int arg_1,int arg_2,data output)
{
	if(skip<0)
		return;
	if(arg_1 == 0 && arg_2 == 0)
	{
		for(int i=0 ;i<output.size;i++)
		{
			if(output.array[i] == 0)
				printf("%c",'-');
			else
				printf("%c",'o');
		}
		printf("\n");
		skip-=1;
		return;
	}
	if(save[arg_1+arg_2][arg_1] <= skip)
	{
		skip-=save[arg_1+arg_2][arg_1];
		return;
	}
	if(arg_1 > 0)
	{
		output.array[output.size] = 0;
		output.size +=1;
		func(arg_1 - 1, arg_2, output);
		output.size -=1;
	}
	if(arg_2 > 0)
	{
		output.array[output.size] = 1;
		output.size +=1;
		func(arg_1, arg_2 - 1, output);
		output.size -=1;
	}
}

int main()
{
	for(int i=0;i<201;i++)
	{
		save[i][0] = 1;
		save[i][i] = 1;
		for(int j=1;j<i;++j)
			save[i][j] = min(num,save[i-1][j-1] + save[i-1][j]);
	}

	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d",&n,&m,&skip);
		skip-=1;
		data temp;
		temp.size = 0;
		
		func(n,m,temp);

	}
}
