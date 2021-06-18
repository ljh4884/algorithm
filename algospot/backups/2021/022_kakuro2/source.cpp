#include <stdio.h>
#include <iostream>

using namespace std;

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




int func(int pos)
{
	int x = hint[pos].x;
	int y = hint[pos].y;
	return 1;
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

			int cond_min = 0;
			int cond_max = 0;
			for(int j=1;j<hint[i].count;j++)
			{
				cond_min+=j;
				cond_max+=(10-j);
			}
			cond_min = min(hint[i].value - cond_min, 9);
			cond_max = max(cond_amx - hint[i].value, 1);

			for(int j=1;j<cond_max;j++)
				check[j] = 1;
			for(int j=cond_min+1;j<10;j++)
				check[j] = 1;

		}





	


	}
}
