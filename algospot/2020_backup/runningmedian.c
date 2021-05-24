#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define L struct linkedlist 
struct linkedlist
{
	int num;
	L *pre;
	L *next;
};

int compare(const void* a,const void* b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1<num2)
		return -1;
	else if(num1==num2)
		return 0;
	else
		return 1;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n,a,b;
		int sum=1983;
		int temp=1983;
		int odd=1;
		L *mid;
		L *pos;
		mid = (L*)malloc(sizeof(L));
		mid->num=1983;
		pos=mid;

		scanf("%d %d %d",&n,&a,&b);
		for(int i=1;i<n;i++)
		{
			int temp2=temp;
			temp=0;
			for(int j=0;j<a;j++)
			{
				temp = (temp+temp2)%20090711;
			}
			temp = (temp+b)%20090711;
			odd=!odd;
			if(temp>mid->num)
			{
				pos=mid;
				while(1)
				{
					if(pos->next==NULL)
					{
						pos->next=(L*)malloc(sizeof(L));
						pos->next->num=temp;
						pos->next->pre=pos;
						break;
					}
					else if(pos->next->num>temp)
					{
						L* tempos = (L*)malloc(sizeof(L));
						tempos->num=temp;
						tempos->pre = pos;
						pos->next->pre =tempos;
						tempos->next = pos->next;
						pos->next = tempos;
						break;
					}
					pos=pos->next;
				}
				if(odd)
				{
					mid=mid->next;
				}
			}
			else
			{
				pos = mid;
				while(1)
				{
					if(pos->pre==NULL)
					{
						pos->pre=(L*)malloc(sizeof(L));
						pos->pre->num=temp;
						pos->pre->next=pos;
						break;
					}
					else if(pos->pre->num<temp)
					{
						L* tempos = (L*)malloc(sizeof(L));
						tempos->num=temp;
						tempos->next = pos;
						pos->pre->next = tempos;
						tempos->pre = pos->pre;
						pos->pre = tempos;
						break;
					}
					pos=pos->pre;
				}
				if(!odd)
				{
					mid = mid->pre;
				}
			}
			sum=(sum+mid->num)%20090711;
			
		}
		
		printf("%d\n",sum);
	}
}
