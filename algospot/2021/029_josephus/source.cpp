#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int number;
	data *next;
}data;

int n,k;

data *make(int number)
{
	data *temp;
	temp = (data*)malloc(sizeof(data));
	temp->number = number;
	return temp;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{

		scanf("%d %d",&n,&k);

		data *start;
		start = make(1);
		data *temp = start;
		for(int i=2;i<n+1;i++)
		{
			temp->next = make(i);
			temp = temp->next;
		}
		temp->next = start;
	
		for(int i=0;i<n-2;i++)
		{
			temp->next = temp->next->next;	
			for(int j=0;j<k-1;j++)
				temp = temp->next;
		}


		int a = temp->number;
		int b = temp->next->number;

		if(a>b)
			printf("%d %d\n",b,a);
		else
			printf("%d %d\n",a,b);

	}

}
