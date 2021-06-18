#include <stdio.h>
#include <stdlib.h>


#define left tree_pos=tree_pos*2


int main()
{
	int c;
	scanf("%d",&c);
	int tree_pos = 1;
	left;
	printf("%d\n",tree_pos);
	while(c--)
	{
		int n;
		int pre[100];
		int mid[100];
		int tree[101];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&pre[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&mid[i]);


	}
}
