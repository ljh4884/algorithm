#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

char name[100001];
int leng[100000];
int size;

void solve()
{
	int begin = 0;
	int match = 0;

	while(begin+match<size)
	{
		if(name[begin+match]==name[size-match-1])
		{
			match++;
		}
		else
		{
			name[begin]=match;
			begin++;
			match = 0;
		}
	}

}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%s",name);
		size = strlen(name);
		int check=0;
		int select=size-1;
		/*for(int i=0;i<size-1;i++)
		{
			check = 0;
			if(name[i]==name[size-1])
			{
				//for(int j=1;j<(size-i)/2;j++)
				for(int j=(size-i)/2-1;j>0;j--)
				{
					if(name[i+j]!=name[size-1-j])
					{
						check=1;
						break;
					}
				}
				if(check==0)
				{
					select = i;
					break;
				}
			}
		}*/
		solve();
		printf("%d\n",select+size);
	}
}
