#include <stdio.h>
#include <string.h>
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		char temp[103];
		char left[51];
		char right[51];
		for(int i=0;i<51;i++)
		{
			left[i]=0;
			right[i]=0;
			temp[i]=0;
		}
		for(int i=51;i<103;i++)
			temp[i]=0;
		int n;
		scanf("%s",temp);
		n=strlen(temp);
		for(int i=0;i<n/2+1;i++)
		{
			left[i]=temp[2*i];
			right[i]=temp[2*i+1];
		}
		printf("%s%s\n",left,right);
	}
}
