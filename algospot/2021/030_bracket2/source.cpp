#include <stdio.h>
#include <string.h>
char str[10001];
char stack[10000];
int size = 0;

void push(char s)
{
	if(s == '(')
		s = ')';
	else if(s == '{')
		s = '}';
	else
		s = ']';
	stack[size] = s;
	size++;
}

char pop()
{
	if(size == 0)
		return -1;
	size--;
	return stack[size];
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int str_size = 0;
		int cond = 1;
		size = 0;
		scanf("%s",str);
		str_size = strlen(str);
		for(int i=0;i<str_size;i++)
		{
			if((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
			{	
				push(str[i]);
			}
			else
			{
				if(pop() != str[i])
				{
					cond = 0;
					break;
				}
			}
		}
		if(size != 0)
			cond = 0;
		if(cond)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
