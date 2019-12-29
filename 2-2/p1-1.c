#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quick(int *a, int l, int r)
{
	int p = l;
	if(l>r)
	{
		return;
	}
	

}


int main()
{
	FILE* fp;
	int n;
	int *array;

	fp=fopen("input.txt","rt");

	fscanf(fp,"%d",&n);
	
	array =(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%d",&array[i]);
	}
}
