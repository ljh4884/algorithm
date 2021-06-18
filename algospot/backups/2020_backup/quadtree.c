#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define T struct tree

int current = 0;

struct tree{
	char data;
	T *child[4];
};

void swap(T* a,T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

struct tree *func(int size,char *s,T *t)
{
	if(current == size)
		return NULL;
	if(s[current]!='x')
	{
		t->data = s[current];
		current++;
		return t;
	}
	else
	{
		t->data = 'x';	
		t->child[0] = (T*)malloc(sizeof(T));
		t->child[1] = (T*)malloc(sizeof(T));
		t->child[2] = (T*)malloc(sizeof(T));
		t->child[3] = (T*)malloc(sizeof(T));
		current++;
		t->child[0]=func(size,s,t->child[0]);
		t->child[1]=func(size,s,t->child[1]);
		t->child[2]=func(size,s,t->child[2]);
		t->child[3]=func(size,s,t->child[3]);
		return t;
	}
}

void func2(T* t)
{
	if(t==NULL)
	{
		printf("end\n");
		return;
	}
	if(t->data != 'x')
		printf("%c",t->data);
	else
	{
		printf("x");
		func2(t->child[2]);
		func2(t->child[3]);
		func2(t->child[0]);
		func2(t->child[1]);
	}
}


int main()
{
	char s[1000];
	int c;
	int size;
	
	T *quad;
	quad = (T*)malloc(sizeof(T));
	scanf("%d",&c);

	for(int cnt=0;cnt<c;cnt++)
	{
		current = 0;
		scanf("%s",s);
		size = strlen(s);
		quad = func(size,s,quad);
		func2(quad);
		printf("\n");
	}
	
}
