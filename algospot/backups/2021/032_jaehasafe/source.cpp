#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		int size = 0;
		char str[51][10001];
		int way = 0;
		int tic = 0;
		scanf("%d",&n);
		for(int i=0;i<n+1;i++)
			scanf("%s",str[i]);
		size = strlen(str[0]);

		for(int i=0;i<n;i++)
		{
			int check = 0;
			if(way)
			{
				for(int pos_next = 1;pos_next<size;pos_next++)
				{
					if(str[i+1][0] == str[i][pos_next])
					{
						check = 1;
						for(int j=1;j<size-pos_next;j++)
						{
							if(str[i+1][j] != str[i][pos_next+j])
							{
								check = 0;
								break;
							}
						}
						if(check == 1)
						{
							tic+=pos_next;
							break;
						}
					}				
				}
			}
			else
			{
				for(int pos_next = 1;pos_next<size;pos_next++)
				{
					if(str[i][0] == str[i+1][pos_next])
					{
						check = 1;
						for(int j=1;j<size-pos_next;j++)
						{
							if(str[i][j] != str[i+1][pos_next+j])
							{
								check = 0;
								break;
							}
						}
						if(check == 1)
						{
							tic+=pos_next;
							break;
						}
					}
				}
				//same cond check needed
			}
			way = !way;

		}
		printf("%d\n",tic);



	}
}
