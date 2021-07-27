#include <stdio.h>

int n;
int A[100001];
int arr[100001];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i+1]);
	for(int i=1;i<=n;i++)
		arr[i] = 100001;
	for(int i=1;i<=n;i++)
	{
		int count = 0;
		for(int j=1;j<=n;j++)
		{
			if(arr[j] > i)
			{

			}
		}

	}
}
