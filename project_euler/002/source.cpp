#include <stdio.h>

int main()
{
	int arr[10000];
	long long ans = 2;
	arr[0] = 1;
	arr[1] = 2;

	for(int i=2;i<10000;i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
		if(arr[i] > 4000000)
			break;
		if(arr[i] % 2 == 0)
			ans += arr[i];
	}
	printf("%lld\n",ans);
}
