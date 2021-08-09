#include <stdio.h>
#include <string.h>

char str[201];
int n;


int func(int pos)
{
	if(pos == n)
		return 1;
	if(str[pos] == '1')
	{
		if(pos+1 == n)
			return 0;
		if(str[pos+1] != '0')
			return 0;
		if(pos+2 == n)
			return 0;
		if(str[pos+2] != '0')
			return 0;
		
		pos+=3;

		while(1)
		{
			if(pos == n)
				return 0;
			if(str[pos] == '1')
				break;
			pos+=1;
		}
		
		pos+=1;
		if(pos == n)
			return 1;
		
		int ret = 0;
		while(1)
		{
			if(pos == n)
				return 1;
			if(str[pos] == '0')
			{
				ret = ret || func(pos);
				break;
			}
			else
			{
				ret = ret || func(pos);
			}
			pos+=1;
		}
		return ret;

	}
	else
	{
		if(pos+1 == n)
			return 0;
		if(str[pos+1] == '1')
			return func(pos+2);

	}
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%s",str);
		n = strlen(str);
		if(func(0) == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
