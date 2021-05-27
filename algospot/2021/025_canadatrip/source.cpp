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
			check[i] = 0;
		}

		sort(sign,sign+n,compare);

		


	}

}
