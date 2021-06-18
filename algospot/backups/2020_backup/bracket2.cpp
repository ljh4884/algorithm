/*
 * 기본적인 문제 
 * 하지만 [[[[ 나 ]]]] 처럼 특이 케이스는 따로 처리가 필요함
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

char array[10001];
int size;
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		stack<char> s;
		int check=0;
		scanf("%s",array);
		size = strlen(array);
		
		for(int i=0;i<size;i++)
		{
			char cur = array[i];

			if(cur=='('||cur=='{'||cur=='[')
			{
				s.push(cur);
			}
			else
			{
				if(s.empty())
				{
					check=1;
					break;
				}
				if(cur==')')
				{
					if(s.top()!='(')
					{
						check=1;
						break;
					}
					s.pop();
				}
				else if(cur=='}')
				{
					if(s.top()!='{')
					{
						check=1;
						break;
					}
					s.pop();
				}
				else
				{
					if(s.top()!='[')
					{
						check=1;
						break;
					}
					s.pop();
				}
				
			}
		}
		if(!s.empty())
			check=1;
		if(check==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
