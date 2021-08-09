#include <stdio.h>


int main()
{
	int arr[2000001];
	long long ans = 0;
	for(int i=0;i<2000001;i++)
		arr[i] = 0;

	for(int num=2;num<2000001;num++)
	{
		if(arr[num] == 1)
			continue;
		ans += num;
		int temp = num;
		while(1)
		{
			if(temp > 2000000)
				break;
			arr[temp] = 1;
			temp += num;
		}
	}
	printf("%lld\n",ans);
}
