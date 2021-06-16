#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		int way = 0;
		int tic = 0;
		int size = 0;
		string str[51];
		scanf("%d",&n);
		
		for(int i=0;i<n+1;i++)
			cin >> str[i];
		size = str[0].length();
		for(int i=0;i<n;i++)
		{
			string prev = str[i];
			while(1)
			{
				
				if(way == 0)
				{
					string temp = prev.substr(size-1);
					prev = temp + prev.substr(0,size-1);
				}
				else
				{
					string temp = prev.substr(0,1);
					prev = prev.substr(1) + temp;
				}

				tic++;
				int cond = prev.compare(str[i+1]);
				if(cond == 0)
					break;

			}
			way = !way;
		}

		printf("%d\n",tic);
	}
}
