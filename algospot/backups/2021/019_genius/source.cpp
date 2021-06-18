#include<stdio.h>

double save[5][50];

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n,k,m;
		scanf("%d %d %d",&n,&k,&m);
		int music_len[50];
		for(int i=0;i<n;i++)
			scanf("%d",&music_len[i]);
		double music_prob[50][50];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lf",&music_prob[i][j]);

		for(int i=0; i<5;i++)
			for(int j=0;j<n;j++)
				save[i][j] = 0;
		save[0][0] = 1;
		for(int cur_time = 1; cur_time <= k; cur_time++)
		{
			for(int i=0;i<n;i++)
			{
				save[cur_time%5][i] = 0;
				for(int j=0;j<n;j++)
					save[cur_time%5][i] += (save[(cur_time - music_len[j] + 5 )% 5][j] * music_prob[j][i]);
			}
		}

		int temp;
		double ret = 0;

		for(int ans=0;ans<m;ans++)
		{
			scanf("%d",&temp);
			ret = 0;
			for(int i = k-music_len[temp]+1;i<=k;i++)
				ret += save[(i+5)%5][temp];
			printf("%.8lf ",ret);
		}
		printf("\n");




		

		

		
	}
}
