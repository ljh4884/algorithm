#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef struct min_heap
{
	int size;
	int value[50000];
}heap;
typedef struct node
{
	int p,q;
	//priority_queue<int,vector<int>,greater<int>> left;
	//priority_queue<int,vector<int>,greater<int>> right;
	heap *l;
	heap *r;
}node;


node *root;
int lsize;
int rsize;
void heap_push(int value, heap *pq)
{
	int size = pq->size;
	pq->value[size]=value;
	int pos = size;
	while(pos>0)
	{
		if(pq->value[pos]<pq->value[(pos-1)/2])
		{
			int temp = pq->value[pos];
			pq->value[pos]=pq->value[(pos-1)/2];
			pq->value[(pos-1)/2]=temp;
		}
		else
		{
			break;
		}
		pos = (pos-1)/2;
	}

	pq->size++;
}

int heap_top(heap *pq)
{
	return pq->value[0];
}

void heap_pop(heap *pq)
{
	if(pq->size==0)
	{
		printf("full heap\n");
		return;
	}
	pq->value[0]=pq->value[pq->size];
	pq->size--;

	int pos = 0;
	int left = 1;
	int right = 2;
	while(1)
	{
		left = pos*2+1;
		right = pos*2+2;
		if(pq->size<left)
		{
			break;
		}
		else if(pq->size==left)
		{
			if(pq->value[pos]>pq->value[left])
			{
				int temp = pq->value[pos];
				pq->value[pos]=pq->value[left];
				pq->value[left]=temp;
				pos = left;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(pq->value[left]<pq->value[right])
			{
				if(pq->value[left]<pq->value[pos])
				{
					int temp = pq->value[left];
					pq->value[left]=pq->value[pos];
					pq->value[pos]=temp;
					pos=left;
				}
				else
					break;
			}
			else
			{
				if(pq->value[right]<pq->value[pos])
				{
					int temp=pq->value[right];
					pq->value[right]=pq->value[pos];
					pq->value[pos]=temp;
					pos=right;
				}
				else
					break;
			}
		}
	}


}

node *insert_node(int p,int q)
{
	if(root==NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->p=p;
		root->q=q;
		root->l = (heap*)malloc(sizeof(heap));
		root->l->size=0;
		root->r = (heap*)malloc(sizeof(heap));
		root->r->size=0;
		return root;
	}
	else if(p>root->p&&q<root->q)
	{

		//root->left.push(p);
		heap_push(p,root->l);
	}
	else if(p<root->p&&q>root->q)
	{
		//root->right.push(q);
		heap_push(p,root->r);
	}
	else if(p>root->p&&q>root->q)
	{
		root->p=p;
		root->q=q;
		while(root->l->size!=0)
		{
			if(heap_top(root->l)<p)
				heap_pop(root->l);
			else
				break;
		}
		while(root->r->size!=0)
		{
			if(heap_top(root->r)<q)
				heap_pop(root->r);
			else
				break;
		}
	}

	return root;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		int sum=0;
		scanf("%d",&n);
		root =NULL;
		while(n--)
		{
			int p,q;
			scanf("%d %d",&p,&q);
			root=insert_node(p,q);
			sum += (root->l->size+root->r->size+1);
			printf("%d %d %d\n",root->l->size,root->r->size,root->l->size+root->r->size+1);
		}
		printf("\n");
		printf("%d\n",sum);
	}
}

