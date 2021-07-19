#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;


typedef struct data
{
	int type;
	int value[4];
}data;

bool compare(const data &d1, const data &d2)
{
	return (d1.value[3]+d1.value[2]) > (d2.value[3]+d2.value[2]);
}


int type_count[2];

int seg[100000];
data total[20000];

int n,m;

int main()
{
	int c;
	int cnt = 1;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		
		int size = 0;
		long long answer = 0;
		type_count[0] = 0;
		type_count[1] = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&size);
			for(int j=0;j<size;j++)
			{
				scanf("%d", &seg[j]);
			}
			sort(seg,seg+size);

			total[i].type = size%2;
			
			for(int j=0;j<4;j++)
				total[i].value[j] = seg[j];

			type_count[size%2]+=1;
		}
		sort(total,total+n,compare);
		if(((type_count[1] == 2) && (type_count[0] > 0))&&((total[0].type == 1) && (total[1].type == 1)))
		{
			long long ans1 = 0;
			long long ans2 = 0;

			for(int i=0;i<n;i++)
			{
				if(total[i].type == 0)
				{
					for(int j=0;j<4;j++)
						ans1 += total[i].value[j];	
					ans1 += total[i].value[0];
					ans1 += total[i].value[1];
				}
				else
				{
					for(int j=0;j<4;j++)
						ans1 += total[i].value[j];
					ans1 += total[i].value[0];
				}
			}

			ans1 -= total[0].value[2];
			ans1 -= total[0].value[3];
			ans1 -= total[1].value[2];
			ans1 -= total[1].value[3];


			for(int i=0;i<n;i++)
			{
				for(int j=0;j<4;j++)
					ans2 += total[i].value[j];
				if(total[i].type ==1)
					ans2 += total[i].value[0];
			}

			ans2 -= total[0].value[2];
			ans2 -= total[0].value[3];
			ans2 -= total[2].value[2];
			ans2 -= total[2].value[3];

			answer = min(ans1, ans2);

		}
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<4;j++)
					answer += total[i].value[j];

				if(total[i].type == 1)
					answer += total[i].value[0];
			}
			answer -= total[0].value[3];
			answer -= total[0].value[2];
			answer -= total[1].value[3];
			answer -= total[1].value[2];
		}

		printf("Case #%d\n",cnt++);
		printf("%lld\n",answer);


	}
}
