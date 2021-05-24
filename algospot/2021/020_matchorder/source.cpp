#include <stdio.h>
#include <algorithm>

using namespace std;

int russia[100];
int korea[100];
int n;

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&russia[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&korea[i]);
		sort(russia,russia+n);
		sort(korea,korea+n);
		int ret = 0;
		int j = 0;
		for(int i=0;i<n;i++)
		{
			if(russia[j] <= korea[i])
			{
				ret+=1;
				j+=1;
			}

		}
		printf("%d\n",ret);
	}
}
