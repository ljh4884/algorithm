#include <stdio.h>


int main()
{
	int i[10000];
	for(int cnt = 0;cnt<1000000000;cnt++)
	{
		i[cnt%10000] = 3;
	}
	
	
}
