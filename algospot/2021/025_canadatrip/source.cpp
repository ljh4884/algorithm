#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct data
{
	int start;
	int end;
	int cnt;
	int g;
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
int n;
int k;



int func(int start, int end)
{
	int mid = (start+end)/2;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(sign[i].end <= mid)
			cnt += sign[i].cnt;
		else if(sign[i].start <= mid)
			cnt += (mid - sign[i].start) / sign[i].g + 1;
	}
	return cnt;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int pos,m,g;
		int end = 0;
		scanf("%d %d",&n,&k);

		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&pos,&m,&g);

			sign[i].end = pos;
			sign[i].start = pos - m;
			sign[i].cnt = m/g + 1;
			sign[i].g = g;
			check[i] = 0;
			end = max(end,sign[i].end);
		}

		sort(sign,sign+n,compare);	
		int start = -1;
		while(1)
		{
			int cnt = func(start,end);
			int mid = (start+end)/2;
			
			if(start + 1 == end)
			{
				printf("%d\n",end);
				break;
			}

			if(cnt < k)
				start = mid;
			else
				end = mid;
			
			
		

		}
		
		

	}

}
