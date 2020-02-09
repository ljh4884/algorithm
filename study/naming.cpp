#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> array;

void func(char *name)
{
	int check=0;
	int size = strlen(name);
	if(size<1)
		return;
	array.push_back(size);
	for(int i=1;i<size;i++)
	{
		if(name[0]==name[i])
		{
			check=0;
			for(int j=0;j<size-i;j++)
			{
				if(name[j]!=name[i+j])
				{
					check=1;
					break;
				}

			}
			if(check==0)
			{
				func(&name[i]);
				break;
			}
		}
	}
}

int main()
{
	char fa[400001];
	char mo[400001];
	scanf("%s",fa);
	scanf("%s",mo);
	strcpy(&fa[strlen(fa)],mo);
	
	func(fa);
	for(unsigned int i = array.size();i>-1;i--)
	{
		printf("%d ",array[i]);
		
	}
	printf("\n");
}
