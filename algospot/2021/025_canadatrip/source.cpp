#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct data
{
	int start;
	int end;
	int cnt;
	int g;
	int cur;
}data;

bool compare(const data& d1,const data& d2)
{
	if(d1.start == d2.start)
		return d1.end < d2.end;
	return d1.start < d2.start;
	//return d1.end < d2.end;
}

data sign[5000];
int check[5000];
int n,k;
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int pos,m,g;
		scanf("%d %d",&n,&k);

		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&pos,&m,&g);

			sign[i].end = pos;
			sign[i].start = pos - m;
			sign[i].cnt = m/g + 1;
			sign[i].g = g;
			sign[i].cur = sign[i].start;
			check[i] = 0;
		}

		sort(sign,sign+n,compare);


		int cnt = 0;
		int end_pos = 8030001;
		int last_index = n;
		int start_pos = 0;
		for(int i=0;i<n;i++)
		{
			
			int sum = 0;
			int temp_start = 8030001;
			for(int j=0;j<i;j++)
			{
				if(check[j] == 0)
				{
					if(sign[j].end < sign[i].start)
					{
						check[j] = 1;
						temp_start = min(temp_start,sign[j].start);
						sum+=sign[j].cnt;
					}
				}
			}

			if(cnt+sum > k)
			{
				start_pos = temp_start;
				end_pos = sign[i].start;
				last_index = i;
				break;
			}
			
			cnt+=sum;

			for(int j=0;j<i;j++)
			{
				if(check[j] == 1)
					check[j] = 2;
			}
		}

		k-=cnt;
		int cond = 0;
		for(int pos = start_pos;pos<end_pos;pos++)
		{
			for(int i=0;i<n;i++)
			{
				if(k == 1)
				{
					cond = 1;
					break;
				}
				if(check[i] < 2)
				{
					if(pos == sign[i].cur)
					{
						k--;
						sign[i].cur+=sign[i].g;
						if(sign[i].cur > sign[i].end)
						{
							check[i] = 2;
						}

					}
				}
			}
			if(cond == 1)
			{
				printf("%d\n",pos);
				break;
			}
		}



		


	}

}
