/*********************************
 * 난이도: 하
 * page: 150p
 * 유형: 완전탐색 -> DP (완전탐색으로는 시간초과가 난다고하여 DP)
 *********************************/

#include <stdio.h>
#include <string.h>

char game[5][6];   // boggle 게임판
char word[10][11]; // 알고 있는 단어
int check;		   // 정답이 나왔으면 종료하기 위한 변수
int size;		   // 현재 단어의 길이

int cache[5][5][10];

int func(int y, int x,int order, int pos)
{
	if(check)
		return 0;
	if(pos == size)
	{
		check = 1;
		return 1;
	}
	if(cache[y][x][pos] != -1)
		return cache[y][x][pos];

	for(int i=-1;i<2;i++)
	{
		for(int j=-1;j<2;j++)
		{
			if((i == 0) && (j == 0))
				continue;
			if(game[y+i][x+j] == word[order][pos])
			{
				if(func(y+i,x+j,order,pos+1) == 1)
				{
					cache[y][x][pos] = 1;
					return 1;
				}
			}
		}
	}
	cache[y][x][pos] = 0;
	return 0;
	
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		for(int i=0;i<5;i++)
			scanf("%s",game[i]);
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",word[i]);

		for(int i=0;i<n;i++)
		{
			check = 0;
			size = strlen(word[i]);
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					for(int k=0;k<size;k++)
						cache[i][j][k] = -1;
			for(int y=0;y<5;y++)
			{
				if(check == 1)
					break;
				for(int x=0;x<5;x++)
				{
					if(check == 1)
						break;
					if(game[y][x] == word[i][0])
					{
						func(y,x,i,1);
					}

				}
			}
			if(check == 1)
				printf("%s YES\n",word[i]);
			else
				printf("%s NO\n",word[i]);
		}


	}	
}
