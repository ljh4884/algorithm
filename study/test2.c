#include <stdio.h>

int func(int b)
{
	if(b==1)
		return 1;
	return b+func(b-1);
}

int main()
{
	printf("%d\n",func(100000));

}
