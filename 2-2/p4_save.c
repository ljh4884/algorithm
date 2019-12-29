#include <stdio.h>
#include <stdlib.h>



struct data
{
	int v1;
	int v2;
	int d;
	struct data * next;
};

struct m_data
{
	int point;
	int distance;
};

void swap(struct m_data *a, struct m_data *b)
{
	struct m_data temp = *a;
	*a = *b;
	*b = temp;
}

struct minheap
{
	struct m_data tree[10000000];
	int size;
};

void insert_tree(struct minheap *a ,struct m_data *b)
{
	int check = a->size;
	a->tree[check]=*b;
	while(1)
	{
		if(check==0)
		{
			break;
		}
		else if(a->tree[check].distance < a->tree[check/2].distance)
		{
			swap(&a->tree[check],&a->tree[check/2]);
		}
		else
		{
			break;
		}
		check = check/2;
	}
	a->size++;
}

struct m_data pop_tree(struct minheap *a)
{
	struct m_data temp = a->tree[0];
	int check = 1;

	a->size--;
	swap(&a->tree[0],&a->tree[a->size]);
	while(1)
	{
		if(check*2 > a->size)
		{
			break;
		}
		else if(check*2 == a->size)
		{
			if(a->tree[check*2-1].distance < a->tree[check-1].distance)
			{
				swap(&a->tree[check-1],&a->tree[check*2-1]);
				check = check * 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(a->tree[check*2-1].distance < a->tree[check*2].distance)
			{
				if(a->tree[check*2-1].distance < a->tree[check-1].distance)
				{
					swap(&a->tree[check-1],&a->tree[check*2-1]);
					check = check * 2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(a->tree[check*2].distance < a->tree[check-1].distance)
				{
					swap(&a->tree[check-1],&a->tree[check*2]);
					check = check * 2 + 1;
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


void insert(struct data* a,struct data* b,int v1, int v2, int d)
{
	struct data* temp = a;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = (struct data*)malloc(sizeof(struct data));
	temp->next->v1=v1;
	temp->next->v2=v2;
	temp->next->d=d;
	
	temp = b;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = (struct data*)malloc(sizeof(struct data));
	temp->next->v1=v2;
	temp->next->v2=v1;
	temp->next->d=d;
}

int main(int argc, char* argv[])
{
	FILE *fp;

	int vn;
	int en;
	int pn;
	int hn;
	int *array;

	int cnt;

	int v1;
	int v2;
	int d;
	struct data **edge1;
	struct data **edge2;

	fp = fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("%s\n",argv[1]);
		return 0;
	}
	fscanf(fp,"%d",&vn);
	fscanf(fp,"%d",&en);

	edge1=(struct data**)malloc(sizeof(struct data*)*vn);
	edge2=(struct data**)malloc(sizeof(struct data*)*vn);

	for(int i=0;i<vn;i++)
	{
		edge1[i]=(struct data*)malloc(sizeof(struct data));
		edge2[i]=(struct data*)malloc(sizeof(struct data));
	}

	for(int i=0;i<en;i++)
	{
		fscanf(fp,"%d %d %d",&v1,&v2,&d);
		insert(edge1[v1],edge2[v2],v1,v2,d);
	}

	fscanf(fp,"%d",&pn);
	for(int i=0;i<pn;i++)
	{
		fscanf(fp,"%d",&hn);
		array = (int*)malloc(sizeof(int)*hn);
		for(int j=0;j<hn;j++)
		{
			fscanf(fp,"%d",&array[j]);
		}

		for(int j=0;j<hn;j++)
		{
			struct minheap *H;
			int *distance;
			int *check;
			struct m_data temp;

			distance=(int*)malloc(sizeof(int)*vn);
			check = (int*)malloc(sizeof(int)*vn);
			H = (struct minheap*)malloc(sizeof(struct minheap));
			
			for(int k=0;k<vn;k++)
			{
				struct m_data *temp;
				temp = (struct m_data*)malloc(sizeof(struct m_data));
				temp->point = k;
				
				distance[k]=1000000000;
				check[k]=0;
				if(k==array[j])
				{
					distance[k]=0;
					check[k]=1;
				}
				temp->distance=distance[k];
				insert_tree(H,temp);
				
			}
			
			while(1)
			{

				temp = pop_tree(H);
				printf("%d %d\n",temp.point,temp.distance);
				distance[temp.point]=temp.distance;
				check[temp.point]=1;
				struct data *tmp =edge1[temp.point]->next;
				while(tmp->v1==temp.point)
				{
					if(tmp==NULL)
						break;
					struct m_data *tp;
					tp = (struct m_data*)malloc(sizeof(struct m_data));
					tp->point=tmp->v2;
					tp->distance=tmp->d;
					insert_tree(H,tp);
					if(check[temp.point]==1)
					{
						tmp = tmp->next;
						continue;
					}
					tmp = tmp->next;
					if(tmp==NULL)
					{
						break;
					}
				}
				tmp = edge2[temp.point]->next;
				while(tmp->v1==temp.point)
				{
					if(tmp==NULL)
						break;
					struct m_data *tp;
					tp = (struct m_data*)malloc(sizeof(struct m_data));
					tp->point=tmp->v2;
					tp->distance=tmp->d;
					if(check[temp.point]==1)	
					{
						tmp = tmp->next;
						continue;
					}
					insert_tree(H,tp);
					tmp = tmp->next;
					if(tmp==NULL)
					{
						break;
					}
				}

				cnt = 0;
				for(int k=0;k<hn;k++)
				{
					if(check[array[k]]==1)
					{
						cnt++;
					}
				}
				if(cnt==hn)
				{
					break;
				}
			}
			
			
		}

		


	}
	
	
	
	
}
