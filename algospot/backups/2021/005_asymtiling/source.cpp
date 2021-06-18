#include <stdio.h>


int n;
int save[101];
const int num = 1000000007;

int main()
{
	int c;
	save[0] = 1;
	save[1] = 1;
	save[2] = 2;
	for(int i=3;i<101;i++)
		save[i] = (save[i-1] + save[i-2])%num;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		if(n%2 == 1)
			printf("%d\n",save[n] - save[n/2]);
		else
			printf("%d\n",((save[n]+num - save[n/2])%num + num - save[(n/2) - 1])%num);

	}
}
