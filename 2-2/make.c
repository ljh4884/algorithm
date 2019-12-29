#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *output;

	int vn=atoi(argv[2]);
	int en=atoi(argv[3]);
	output = fopen(argv[1],"w");
	srand(time(NULL));

	fprintf(output,"%d\n",vn);
	fprintf(output,"%d\n",en);
	for(int i=0;i<en;i++)
		fprintf(output,"%d %d %d\n",rand()%vn,rand()%vn,rand()%100+1);




}
