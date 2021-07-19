#include <stdio.h>
#include <algorithm>

using namespace std;
int main()
{
	int c;
	int cnt = 1;
	scanf("%d",&c);
	int n;
	int A[200000];
	int B[200000];
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&B[i]);

		if(n > 5000)
		{
			printf("0\n");
			continue;
		}
		sort(A,A+n);
		sort(B,B+n);

		long long ans = (long long)200000*(long long)1000000000;
		for(int pivot=0;pivot<n;pivot++)
		{
			int temp = 0;
			long long cur_ans = 0;
			for(int i=0;i<n;i++)
			{
				if(pivot == i)
				{
					temp = 1;
					continue;
				}
				cur_ans += max((A[i+temp] - B[i]),(B[i] - A[i+temp]));

			}
			ans = min(ans, cur_ans);

		}
		printf("Case #%d\n",cnt++);
		printf("%lld\n",ans);
	}

}
