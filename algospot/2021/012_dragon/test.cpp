#include <stdio.h>

int main()
{
	unsigned long long a[51];

	a[0] = 2;
	for(int i=1;i<51;i++)
		a[i] = (a[i-1]*2 + 1);

	for(int i=0;i<51;i++)
		printf("%llu\n",a[i]);
}
