#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m,cnt;
double camera[200];
double list[20000];

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%lf",&camera[i]);

		cnt = 0;
		for(int i=0;i<m-1;i++)
			for(int j=i+1;j<m;j++)
				list[cnt++] = camera[i] - camera[j];
			

		sort(list,list+cnt);
		double prev_list = -1;
		double value = -1;
		int temp = 1;
		int cond = 0;
		double prev = 0;
		for(int i=0;i<cnt;i++)
		{
			value = -list[i];
			if(prev_list == value)
				continue;
			prev_list = value;
			temp = 1;
			cond = 0;
			prev = camera[0];
			for(int i=1;i<m;i++)
			{
				if((camera[i] - prev) >= value)
				{
					prev = camera[i];
					temp++;
				}

				if(temp >= n)
				{
					cond = 1;
					break;
				}

			}

			if(cond)
			{
				printf("%.2lf\n",value);
				break;
			}
		}
	}
}
