#include <stdio.h>


typedef struct data
{
	int y;
	int x;
	int type;
	int value;
	int count;
	int check;
}data;

int game[20][20];

int min_num[20][20];
int max_num[20][20];
int n,q;
data hint[800];


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
				hint[i][j][0] = 0;
				hint[i][j][1] = 0;
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
			hint[i].check = 0;

			if(t == 0)
			{
				x+=1;
				while(game[y][x])
				{
					hint[i].count++;
					x+=1;
				}


				int min_sum = 0;
				int max_sum = 0;
				for(int sum=0;sum<hint[i].count-1;sum++)
				{
					min_sum+= (sum+1);
					max_sum+= (9-sum);
				}
				
				x = hint[i].x + 1;
				for(int pos = 0;pos<hint[i].count;
				{
					
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



		}





	


	}
}
