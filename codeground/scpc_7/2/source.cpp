#include <stdio.h>
int n,t;
int B[50000];
int A[50000];
int main()
{
	int c;
	int cnt=1;
	scanf("%d",&c);
	while(c--)
	{
		char temp[50002];
		scanf("%d %d",&n,&t);
		scanf("%s",temp);
		for(int i=0;i<n;i++)
		{
			B[i] = temp[i]-48;
			A[i] = 0;
		}

		for(int i=0;i<t;i++)
		{
			if(t+i>=n)
				break;
			A[t+i] = B[i];
		}
		for(int i=0;i<t;i++)
		{
			if(n-1-t-i<0)
				break;
			A[n-1-t-i] = B[n-1-i];
		}

		for(int i=t;i<(n-t);i++)
		{
			if(B[i] == 1)
			{
				if((A[i-t] == 0) && (A[i+t] == 0))
				{
					if(i+t+t < n)
					{
						if(B[i+t+t] == 1)
						{
							A[i+t] = 1;
						}
						else
						{
							A[i-t] = 1;
						}
					}
					else
					{
						A[i+t] = 1;
					}
				}
			}
		}



		printf("Case #%d\n",cnt++);
		for(int i=0;i<n;i++)
			printf("%d",A[i]);
		printf("\n");
	}
}
