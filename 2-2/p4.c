#include <stdio.h>
#include <stdlib.h>

#define D struct data
#define I struct info
#define H struct heap

struct data
{
	int v1;
	int v2;
	int d;
	struct data *next;

};

struct info
{
	int pos;
	int dis;
	int sta;
};


struct heap
{
	int size;
	I **tree;
};


void insert(D **e1,int v1,int v2,int d);
void insert_heap(H *heap,int pos,int dis,int sta,int max);
I *pop_heap(H *haep);
void swap(I *a, I *b);


int main(int argc, char* argv[])
{
	FILE *fp;

	int vn;
	int en;
	int pn;
	int hn;


	int *array;
	int v1,v2,d;

	D **e;

	fp=fopen(argv[1],"r");

	fscanf(fp,"%d",&vn);
	fscanf(fp,"%d",&en);

	e=(D**)malloc(sizeof(D*)*vn);
	for(int i=0;i<vn;i++)
	{
		e[i]=(D*)malloc(sizeof(D));
	}

	for(int i=0;i<en;i++)
	{
		fscanf(fp,"%d %d %d",&v1,&v2,&d);
		insert(e,v1,v2,d);
	}
	fscanf(fp,"%d",&pn);
	for(int cnt=0;cnt<pn;cnt++)
	{
		fscanf(fp,"%d",&hn);
		array = (int *)malloc(sizeof(int)*hn);
		for(int cnt2=0;cnt2<hn;cnt2++)
		{
			fscanf(fp,"%d",&array[cnt2]);
		}

		/*problem start*/
		int min =100000000;
		/*init heap*/
		for(int i=0;i<hn;i++)
		{
			int *che;
			int *dis;
			en = 10000000;
			H *min_heap = (H*)malloc(sizeof(H));
			min_heap->tree = (I**)malloc(sizeof(I*)*en);
			min_heap->size = 0;
			for(int i=0;i<en;i++)
			{
				min_heap->tree[i] = (I*)malloc(sizeof(I));
			}

			dis = (int*)malloc(sizeof(int)*vn);
			che = (int*)malloc(sizeof(int)*vn);
			for(int j=0;j<vn;j++)
			{
				dis[j]=1000000000;
				che[j]=0;
			}
			insert_heap(min_heap,array[0],0,array[0],en);

			while(1)
			{
				int count;
				I *temp = pop_heap(min_heap);
				if(che[temp->pos]==1)
					continue;
				else if(dis[temp->pos]<temp->dis)
					continue;
				else
				{
					D *tmp = e[temp->pos]->next;
					dis[temp->pos]=temp->dis;
					che[temp->pos]=1;
					while(tmp!=NULL)
					{
						insert_heap(min_heap,tmp->v2,dis[temp->pos]+tmp->d,tmp->v1,en);
						tmp = tmp->next;
					}
					
				}


				/* need to patch*/
				count = 0;
				for(int j=0;j<hn;j++)
				{
					if(che[array[j]]==1)
						count++;
				}
				if(count==hn)
				{
					for(int j=0;j<hn;j++)
					{
						if(min>dis[array[j]])
						{
							if(dis[array[j]]==0)
								continue;
							min = dis[array[j]];
						}
					}
					break;
				}
			}

		}

		printf("%d\n",min);	

		

	}

	fclose(fp);
	return 0;
}
I *pop_heap(H *heap)
{
	int index=1;
	if(heap->size ==0)
	{
		printf("emptry heap\n");
		return NULL;
	}

	I *temp=(I*)malloc(sizeof(I));
	temp->dis=heap->tree[0]->dis;
	temp->pos=heap->tree[0]->pos;

	heap->tree[0]->dis=heap->tree[heap->size-1]->dis;
	heap->tree[0]->pos=heap->tree[heap->size-1]->pos;
	heap->tree[0]->sta=heap->tree[heap->size-1]->sta;

	while(1)
	{
		if(index*2>heap->size)
			break;
		else if(index*2==heap->size)
		{
			if(heap->tree[index-1]->dis<heap->tree[index*2-1]->dis)
				swap(heap->tree[index-1],heap->tree[index*2-1]);
			index = index*2;
		}
		else
		{
			if(heap->tree[index*2-1]->dis < heap->tree[index*2]->dis)
			{
				if(heap->tree[index*2-1]->dis<heap->tree[index-1]->dis)
				{
					swap(heap->tree[index*2-1],heap->tree[index-1]);
					index = index*2;
				}
				else
					break;
			}
			else
			{
				if(heap->tree[index*2]->dis < heap->tree[index-1]->dis)
				{
					swap(heap->tree[index*2],heap->tree[index-1]);
					index = index * 2 + 1;
				}
				else
					break;
			}
		}
	}
	
	heap->size--;
	return temp;
}

void swap(I *a, I *b)
{
	I temp = *a;
	*a = *b;
	*b = temp;
}
void insert_heap(H *heap,int pos, int dis,int sta,int max)
{
	if(heap->size==max)
	{
		printf("full heap");
		return;
	}
	int index = heap->size;
	heap->tree[index]->pos=pos;
	heap->tree[index]->dis=dis;
	heap->tree[index]->sta=sta;

	while(1)
	{
		if(index==0)
			break;
		else if(heap->tree[index]->dis < heap->tree[index/2]->dis)
			swap(heap->tree[index],heap->tree[index/2]);
		else
			break;
		index = index/2;
	}
	heap->size++;

}

void insert(D **e1,int v1,int v2, int d)
{
	D *temp = e1[v1];
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = (D*)malloc(sizeof(D));
	temp->next->v1=v1;
	temp->next->v2=v2;
	temp->next->d=d;

	temp = e1[v2];
	while(temp->next!=NULL)
		temp = temp->next;

	temp->next = (D*)malloc(sizeof(D));
	temp->next->v1 =v2;
	temp->next->v2 = v1;
	temp->next->d= d;
	
}

