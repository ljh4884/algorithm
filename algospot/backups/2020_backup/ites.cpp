/* 쉽게 풀긴 하였지만
 * 너무 오래걸린다 최적화가 더 필요할듯
 *
 */

#include <stdio.h>
#include <queue>

using namespace std;
const long long pl = 2531011;
const long long mul = 214013;
const long long div = 4294967296;
int k,n;
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		queue<long long> q;
		long long sum = 1984;
		long long cur = 1983;
		long long next = 1983;
		int cnt=0;
		scanf("%d %d",&k,&n);
		q.push(cur);
		int count=1;
		while(1)
		{
			
			if(count==n+1)
				break;

			if(sum==k)
			{
				sum-=(q.front()%10000+1);
				q.pop();
				next = ((cur * mul + pl)%div);
				q.push(next);
				cur = next;
				sum +=(next%10000+1);
				cnt++;
				count++;
			}
			else if(sum>k)
			{
				sum-=(q.front()%10000+1);
				q.pop();

			}
			else if(sum<k)
			{
				
				next = ((cur * mul + pl)%div);
				q.push(next);
				cur=next;
				sum+=(next%10000+1);
				count++;
				
			}

		}
		printf("%d\n",cnt);
		

	}
}
