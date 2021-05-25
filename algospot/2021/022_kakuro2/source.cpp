#include <stdio.h>


typedef struct data
{
	int y;
	int x;
	int type;
	int value;
	int count;
	int check[10];
}data;

int game[20][20];

int n,q;
data hint[800];


int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
			
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&game[i][j]);
			}
		}
		
		scanf("%d",&q);
		int x,y,t,v;
		for(int i=0;i<q;i++)
		{
			scanf("%d %d %d %d",&y,&x,&t,&v);
			hint[i].y = y;
			hint[i].x = x;
			hint[i].type = t;
			hint[i].value = v;
			hint[i].count = 0;
			for(int j=0;j<10;j++)
				hint[i].check[j] = 0;

			if(t == 0)
			{
				x+=1;
				while(game[y][x])
				{
					hint[i].count++;
					x+=1;
				}

				int temp = 0;
				temp = min(9,hint[i].value - (hint[i].count - 1));

				for(int j=temp+1;j<10;j++)
					hint[i].check[j] = 1;

				temp = max(1, hint[i].value - 9 * (hint[i].count - 1));

				

				
			}
			else
			{
				y+=1;
				while(game[y][x])
				{
					hint[i].count++;
					y+=1;
				}
			}



		}





	


	}
}
