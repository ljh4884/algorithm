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
	int C[200000];
	int D[200000]; //<< for A
	int E[200000]; //>> for A
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&B[i]);

		sort(A,A+n);
		sort(B,B+n);

		C[0] = abs(A[0] - B[0]);
		for(int i=1;i<n;i++)
		{
			C[i] = abs(A[i] - B[i]);
			C[i] = C[i] + C[i-1];
		}

		for(int i=0;i<(n-1);i++)
		{
			D[i] = abs(A[i+1] - B[i]);
			if(i>0)
				D[i] = D[i] + D[i-1];
		}
		D[n-1] = D[n-2];
		E[0] = 0;
		for(int i=1;i<n;i++)
		{
			E[i] = abs(A[i-1] - B[i]);
			E[i] = E[i] + E[i-1];
		}
		/*
		printf("C\n");
		for(int i=0;i<n;i++)
			printf("%d ",C[i]);
		printf("\nD\n");
		for(int i=0;i<n;i++)
			printf("%d ",D[i]);
		printf("\nE\n");
		for(int i=0;i<n;i++)
			printf("%d ",E[i]);
		printf("\n");
		*/
		long long ans = (long long)200000 * (long long)1000000000;

		long long temp_ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp_ans = 0;
				if(i<j)
				{
					if(i == 0)
					{
						temp_ans = D[j-1];
					}
					else
					{
						temp_ans = C[i-1];
						temp_ans += (D[j-1] - D[i-1]);
					}

					temp_ans += (C[n-1] - C[j]);
					

				}
				else if(i>j)
				{
					if(j == 0)
						temp_ans = 0;
					else
						temp_ans = C[j-1];
					temp_ans += (E[i] - E[j]);

					temp_ans += (C[n-1] - C[i]);
				}
				else
				{
					temp_ans = C[n-1] - abs(A[i] - B[i]);
				}
			
				if(temp_ans < ans)
					printf("%d %d %lld\n",i,j,temp_ans);
				ans = min(ans, temp_ans);
			}
		}

		printf("Case #%d\n",cnt++);
		printf("%lld\n",ans);


		
	}

}
