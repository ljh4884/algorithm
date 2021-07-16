#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct fort
{
	int x,y,r;
	int size;
	int dep;
	fort *child[100];

}fort;

int n;

fort *make_fort()
{
	fort *ret;
	ret = (fort*)malloc(sizeof(fort));
	ret->size = 0;
	ret->dep = 0;
	return ret;
}

bool isInside(int x,int y,int r, fort *des)
{
	return ((des->x - des->r < x - r) &&
			(des->x + des->r > x + r) &&
			(des->y - des->r < y - r) &&
			(des->y + des->r > y + r));
}

fort * insert_fort(int x,int y,int r, fort *des)
{
	if(des==NULL)
	{
		des = make_fort();
		des->x = x;
		des->y = y;
		des->r = r;
		return des;
	}
	if(isInside(x,y,r,des))
	{
		if(des->size==0)
		{
			des->child[0]=insert_fort(x,y,r,des->child[0]);
			des->size=1;
			des->dep = 1;
			return des;
		}
		for(int i=0;i<des->size;i++)
		{
			if(isInside(x,y,r,des->child[i]))
			{
				des->child[i]=insert_fort(x,y,r,des->child[i]);
				des->dep = max(des->dep,des->child[i]->dep+1);

				return des;
			}
		}
		// it is array but change to linked list is better
		fort *temp = make_fort();
		temp->x=x;
		temp->y=y;
		temp->r=r;
		int dessize=0;
		//dep has to be changed
		for(int i=0;i<des->size;i++)
		{
			if(isInside(des->child[i]->x,des->child[i]->y,des->child[i]->r,temp))
			{
				temp->child[temp->size]=des->child[i];
				temp->dep = max(temp->dep,des->child[i]->dep+1);
				temp->size++;
			}
			else
			{
				des->child[dessize]=des->child[i];
				dessize++;
			}
		}
		if(temp->size!=0)
		{
			des->child[dessize]=temp;
			des->size = dessize+1;
			des->dep = max(des->dep,temp->dep+1);
			return des;
		}
		else
		{
			des->child[des->size]=insert_fort(x,y,r,des->child[des->size]);
			des->size++;
		}


	}
	return des;
}

int find(fort *temp)
{
	if(temp->size==0)
	{
		return 0;
	}
	else if(temp->size==1)
	{
		return find(temp->child[0]);
	}
	else
	{
		int max1=0;
		for(int i=0;i<temp->size;i++)
		{
			int max2 = find(temp->child[i]);
			for(int j=i+1;j<temp->size;j++)
			{
				max1 = max(2+temp->child[i]->dep+temp->child[j]->dep,max1);
			}
			max1 = max(max1,max2);
		}
		return max1;
	}
}


int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		fort *root =NULL;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x,y,r;
			scanf("%d %d %d",&x,&y,&r);
			root = insert_fort(x,y,r,root);
		}
		if(root->size==0)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",max(root->dep,find(root)));
			
		}
	}
}
