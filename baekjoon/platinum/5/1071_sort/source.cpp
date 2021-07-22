#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[50];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	sort(arr,arr+n);

	int i = 0;
	int temp = 0;
	while(i != n-1)
	{
		if(arr[i] + 1 == arr[i+1])
		{
			int cond = 0;
			for(int j = i+2;j<n;j++)
			{
				if((arr[i] + 1 != arr[j]) && (arr[i] < arr[j]))
				{
					cond = 1;
					temp = arr[i+1];
					arr[i+1] = arr[j];
					arr[j] = temp;
					break;
				}
			}
			if(cond == 0)
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				i-=2;
			}
		}
		i++;
	}



	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
