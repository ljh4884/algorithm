#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D struct data
#define H struct heap
#define I struct info
#define max 2000000

struct data
{
	int v;
	int d;
	D* next;
};

struct info
{
	int v1;
	int v2;
	int d;
};

struct heap
{
	int size;
	I** tree;
};

void func(D* edge,int v2,int d)
{
	while(edge->next!=NULL)
		edge=edge->next;
	edge->next = (D*)malloc(sizeof(D));
	edge->next->v = v2;
	edge->next->d = d;
}

H* make_heap(H* h)
{
	h = (H*)malloc(sizeof(H));
	h->size=0;
	h->tree = (I**)malloc(sizeof(I*)*max);
	for(int i=0;i<max;i++)
	{
		h->tree[i]=(I*)malloc(sizeof(I));
	}
	return h;
}

void swap(I *a,I *b)
{
	I temp = *a;
	*a = *b;
	*b = temp;
}

void push(H *h,int v1,int v2,int d)
{
	if(h->size == max)
	{
		printf("full heap\n");
		return;
	}
	else
	{
		int size = h->size;

		h->tree[h->size]->v1=v1;
		h->tree[h->size]->v2=v2;
		h->tree[h->size]->d=d;

		while(size>0)
		{
			if(h->tree[size]->d<h->tree[size/2]->d)
			{
				swap(h->tree[size],h->tree[size/2]);
				size = size/2;
			}
			else
				break;
		}
		h->size++;
	}
}


I* pop(H *h)
{
	if(h->size == 0)
	{
		//printf("empty heap\n");
		return NULL;
	}
	else
	{
		int size = 1;
		I* temp = (I*)malloc(sizeof(I));
		int v1 = h->tree[0]->v1;
		int v2 = h->tree[0]->v2;
		int d = h->tree[0]->d;
		h->size--;
		swap(h->tree[h->size],h->tree[0]);
		
		while(1)
		{
			if(size*2>h->size)
			{
				break;
			}
			else if(size*2==h->size)
			{
				if(h->tree[size-1]->d>h->tree[size*2-1]->d)
				{
					swap(h->tree[size-1],h->tree[size*2-1]);
					size = size*2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(h->tree[size*2-1]->d<h->tree[size*2]->d)
				{
					if(h->tree[size*2-1]->d<h->tree[size-1]->d)
					{
						swap(h->tree[size*2-1],h->tree[size-1]);
						size = size*2;
					}
					else
						break;
				}
				else
				{
					if(h->tree[size*2]->d<h->tree[size-1]->d)
					{
						swap(h->tree[size*2],h->tree[size-1]);
						size = size*2+1;
					}
					else
						break;
				}
			}
		}
				
		temp->v1 = v1;
		temp->v2 = v2;
		temp->d = d;
		return temp;
	}
}

int main(int argc,char* argv[])
{
	FILE *fp;
	int v,e,p,n;
	int v1,v2;
	int d;

	int *array;
	int *dis;
	int *check;
	int out;
	D** edge;

	fp = fopen(argv[1],"r");

	fscanf(fp,"%d",&v);
	fscanf(fp,"%d",&e);

	edge = (D**)malloc(sizeof(D*)*v);
	for(int i=0;i<v;i++)
	{
		edge[i]=(D*)malloc(sizeof(D));
	}

	for(int cnt=0;cnt<e;cnt++)
	{
		fscanf(fp,"%d %d %d",&v1,&v2,&d);
		func(edge[v1],v2,d);
		func(edge[v2],v1,d);
	}
	fscanf(fp,"%d",&p);
	H *h;
	h=make_heap(h);
	for(int cnt=0;cnt<p;cnt++)
	{
		int min=1000000000;
		D* temp;
		h->size = 0;
		fscanf(fp,"%d",&n);
		array = (int*)malloc(sizeof(int)*n);
		dis =(int*)malloc(sizeof(int)*v);
		check = (int*)malloc(sizeof(int)*v);
		for(int i=0;i<v;i++)
		{
			dis[i]=1000000000;
		}
		for(int i=0;i<n;i++)
		{
			fscanf(fp,"%d",&array[i]);
		}
		for(int i=0;i<2;i++)
		{
			h->size = 0;
			for(int j=0;j<v;j++)
			{
				dis[j]=1000000000;
				check[j]=0;
			}
			out = 0;
			dis[array[i]]=0;
			for(int j=0;j<n;j++)
			{
				push(h,array[j],array[j],1000000000);
			}
			temp = edge[array[i]]->next;
			while(temp!=NULL)
			{
				push(h,array[0],temp->v,temp->d);
				dis[temp->v]=temp->d;
				temp = temp->next;
			}
			while(1)
			{
				int j;
				out=0;
				for(j=i+1;j<n;j++)
				{
					if(check[array[j]]==1)
						out++;
					if(dis[array[j]]<min)
						min = dis[array[j]];
				}
				if(out==(j-i-1))
					break;
				I *temp2=pop(h);
				if(temp2 == NULL)
				{
					break;
				}
				if(check[temp2->v2]==0)
				{
					check[temp2->v2]=1;
					if(dis[temp2->v2]>temp2->d)
						dis[temp2->v2]=temp2->d;
					
					temp = edge[temp2->v2]->next;
					while(temp!=NULL)
					{
						push(h,temp2->v2,temp->v,temp->d+dis[temp2->v2]);
						if(dis[temp->v]>temp->d+dis[temp2->v2])
							dis[temp->v]=temp->d+dis[temp2->v2];
						temp = temp->next;
					}
				}
				else
				{
					continue;
				}
			}
		}
		printf("%d\n",min);
			

	}
}
