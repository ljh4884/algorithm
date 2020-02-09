/*
 * 밑에 주석으로 표시해둔 부분이 가장 어려웠다.
 * 전위 순회와 중위순회를 보고 어떻게 트리를 구성하냐를 판단하기가 어려운듯
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	node * l;
	node * r;
	node * par;
}node;

int n;
int pre[100];
int mid[100];

void print(node * t)
{
	if(t==NULL)
		return;
	print(t->l);
	print(t->r);
	printf("%d ",t->val);
}



int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		node * tree;
		tree = (node*)malloc(sizeof(node));
		node *pos = tree;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pre[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&mid[i]);
		}
		int j=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			pos->val = pre[i];
			if(pre[i]==mid[j])
			{
				if(i==n-1)
					break;
				
				if(pre[i+1]==mid[j+1])
				{
					pos->r = (node*)malloc(sizeof(node));
					pos->r->par = pos;
					pos = pos->r;
					j++;
				}
				else
				{
					/* 
					 *
					 *
					 *
					 *
					 *  제일 어려웠던 부분 
					 */
					while(1)
					{
						j++;
						int check=0;
						for(int k=0;k<i;k++)
						{
							if(pre[k]==mid[j])
							{
								check=1;
								break;
							}
						}
						if(check==0)
							break;
					}
					while(mid[j-1]!=pos->val)
					{
						pos = pos->par;
					}

					/*
					 *여기까지
					 *
					 */
					pos->r = (node*)malloc(sizeof(node));
					pos->r->par = pos;
					pos = pos->r;
					
				}
				
				
				
			}
			else
			{
				if(i==n-1)
				{
					break;
				}
				pos->l = (node*)malloc(sizeof(node));
				pos->l->par = pos;
				pos = pos->l;
			}

		}
		print(tree);
		printf("\n");
	}

}
