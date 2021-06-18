/*기본적으로 풀었다.
 * 오래걸려서 최적화를 시도하려했으나
 * 그건 나중으로 미루겠다.`
 */

#include <stdio.h>
#include <math.h>
int n,lo,hi;
int hi_lo;
int array[10000001];

int main()
{
	int c;
	scanf("%d",&c);
	for(int i=1;i<5000000+1;i++)
	{
		array[i]=1;
	}
	for(int i=5000000+1;i<10000000+1;i++)
	{
		array[i]=2;
	}
	for(int i=2;i<5000000+1;i++)
	{
		for(int j=i;j<10000000+1;j=j+i)
		{
			array[j]++;
		}
	}
	while(c--)
	{
		int cnt=0;
		scanf("%d %d %d",&n,&lo,&hi);
		for(int i=lo;i<hi+1;i++)
		{
			if(array[i]==n)
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
