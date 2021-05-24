#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int p,q;
	int size;
	node *child[2];
}node;

int n;
int cnt;

node *insert_node(int p,int q,node *temp);

node *make_node()
{
	node *ret;
	ret = (node*)malloc(sizeof(node));
	ret->size =1;
	return ret;
}



void recond(node *temp, node *ret)
{
	if(temp==NULL)
		return;
	ret = insert_node(temp->p,temp->q,ret);
	recond(temp->child[0],ret);
	recond(temp->child[1],ret);

}

node *insert_node(int p,int q,node *temp)
{
	if(temp==NULL)
	{
		temp = make_node();
		temp->p=p;
		temp->q=q;
		return temp;
	}
	else if(p<temp->p&&q>temp->q)
	{
		temp->child[0]=insert_node(p,q,temp->child[0]);
		if(temp->child[1]==NULL)
			temp->size = temp->child[0]->size+1;
		else
			temp->size = temp->child[0]->size+temp->child[1]->size+1;
		return temp;
	}
	else if(p>temp->p&&q<temp->q)
	{
		temp->child[1]=insert_node(p,q,temp->child[1]);
		if(temp->child[0]==NULL)
			temp->size = temp->child[1]->size+1;
		else
			temp->size = temp->child[0]->size+temp->child[1]->size+1;
		return temp;
	}
	else if(p>temp->p&&q>temp->q)
	{
		node *ret = make_node();
		ret->p=p;
		ret->q=q;
		recond(temp->child[0],ret);
		recond(temp->child[1],ret);
		return ret;
	}
	else
	{
		return temp;
	}

}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		int sum=0;
		node * root=NULL;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			root = insert_node(a,b,root);
			sum+=root->size;
		}
		printf("%d\n",sum);
	}
}
