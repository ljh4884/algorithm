/* c언어로 짠 버전 
 * 직접 min heap을 구현하여 시도하였으나
 * c++에 구현된 min heap보다 over head가 커서 느린것 같다
 * c++로도 같은 알고리즘을 사용하여 구현하였더니 3배정도 빨라졌다..
 */

#include <stdio.h>
#include <stdlib.h>

int array[100];
int size;
int n;

void push(int a)
{
	int s=size;
	array[size]=a;
	while(1)
	{
		int par = (s-1)/2;
		if(s==0)
			break;
		else if(array[s]<array[par])
		{
			int temp = array[s];
			array[s] = array[par];
			array[par] = temp;
		}
		else
			break;
		s = par;
	}
	size++;
}

int pop()
{
	int temp = array[0];
	if(size==0)
	{
		printf("empty\n");
	}
	array[0] = array[size-1];
	size--;
	int pos=0;
	while(1)
	{
		int left = pos*2+1;
		int right = pos*2+2;
		if(left>size-1)
			break;
		else if(right>size-1)
		{
			if(array[left]<array[pos])
			{
				int temp = array[left];
				array[left] = array[pos];
				array[pos] = temp;
				pos = left;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(array[left]<array[right])
			{
				if(array[left]<array[pos])
				{
					int temp = array[left];
					array[left] = array[pos];
					array[pos] = temp;
					pos = left;
				}
				else
					break;
			}
			else
			{
				if(array[right] < array[pos])
				{
					int temp = array[right];
					array[right]=array[pos];
					array[pos] = temp;
					pos = right;
				}
				else
				{
					break;
				}

			}
		}
	}
	return temp;

}




int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int temp;
		int sum=0;
		size=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			push(temp);
		}
		for(int i=0;i<n;i++)
		{
			int input1;
			int input2;
			if(size==1)
			{
				printf("%d\n",sum);
				break;
			}
			input1=pop();
			input2=pop();
			sum+=(input1+input2);
			push(input1+input2);
		}

	}
	
}
