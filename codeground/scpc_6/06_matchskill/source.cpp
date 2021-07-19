#include <stdio.h>
#include <algorithm>
#include <math.h>
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

		sort(A,A+n);
		sort(B,B+n);

			

		int max_v = 0;
		int max_i = 0;
		long long ans = 0;
		long long temp_ans = 0;
		for(int i=0;i<n;i++)
		{
			int value = abs(A[i] - B[i]);
			if(value > max_v)
			{
				max_v = value;
				max_i = i;
			}
			temp_ans += value;
		}

		int tt = A[max_i];
		A[max_i] = B[max_i];

		temp_ans -= max_v;

		int max_vv=0;
		int max_ii=0;
		for(int i=0;i<n;i++)
		{
			int value = abs(A[i] - B[i]);
			if(value > max_vv)
			{
				max_vv = value;
				max_ii = i;
			}
		}
		long long temp_ans2 = 0;

		if(max_ii < max_i)
		{
			for(int i = max_ii;i<max_i;i++)
			{
				A[i] = A[i+1];
			}

			A[max_i-1] = tt;
		
			for(int i=0;i<n;i++)
			{	
				temp_ans2 += abs(A[i] - B[i]);
			}
		}
		else if(max_ii > max_i)
		{
			for(int i = max_ii;i>max_i;i--)
			{
				A[i] = A[i-1];
			}
			A[max_i+1] = tt;
			for(int i=0;i<n;i++)
			{
				temp_ans2 += abs(A[i] - B[i]);
			}
		}
		ans = min(temp_ans, temp_ans2);




		printf("Case #%d\n",cnt++);
		printf("%lld\n",ans);
	}

}
