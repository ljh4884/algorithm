#include <stdio.h>
#include <vector>
using namespace std;
int n,k;
int point[100001];
typedef struct data
{
	int kijun;
	int CF;
	vector<int> node;
	vector<int> value;

}data;

vector<data> total;

int main()
{
	int c;
	int cnt = 1;
	scanf("%d",&c);
	while(c--)
	{
		int cond = 0;
		printf("Case #%d\n",cnt++);
		int pointer = 0;
		scanf("%d %d",&n,&k);
		if(n>2001)
			cond = 1;
		total.clear();
		for(int i=0;i<=n;i++)
		{
			point[i] = -1;
		}
		for(int count=0;count<k;count++)
		{
			int op = 0;
			int a,b,c;
			scanf("%d",&op);
			if(op == 1)
			{
				scanf("%d %d %d",&a,&b,&c);
				if(cond == 1)
					continue;
				if((point[a] == -1) && (point[b] == -1))
				{
					data temp;

					point[a] = pointer;
					point[b] = pointer;
					temp.kijun = a;
					temp.CF = 0;
					temp.node.push_back(a);
					temp.value.push_back(0);
					temp.node.push_back(b);
					temp.value.push_back(c);
					pointer++;
					total.push_back(temp);
				}
				else if((point[a] == -1) && (point[b] != -1))
				{
					int temp;
					point[a] = point[b];
					for(int i=0;i<total[point[a]].node.size();i++)
					{
						if(total[point[a]].node[i] == b)
						{
							temp = total[point[a]].value[i];
							break;
						}
					}
					total[point[a]].node.push_back(a);
					total[point[a]].value.push_back(temp - c);

				}
				else if((point[a] != -1) && (point[b] == -1))
				{
					int temp;
					point[b] = point[a];
					for(int i=0;i<total[point[a]].node.size();i++)
					{
						if(total[point[a]].node[i] == a)
						{
							temp = total[point[a]].value[i];
							break;
						}
					}
					total[point[a]].node.push_back(b);
					total[point[a]].value.push_back(temp + c);
				}
				else if(point[a] == point[b])
				{
					int value1, value2;

					for(int i=0;i<total[point[a]].node.size();i++)
					{
						if(total[point[a]].node[i] == a)
							value1 = total[point[a]].value[i];
						else if(total[point[a]].node[i] == b)
							value2 = total[point[a]].value[i];
					}

					if((value2 - value1) != c)
						total[point[a]].CF = 1;
				}
				else //point[a] != point[b]
				{
					int value1,value2,value3;

					for(int i=0;i<total[point[a]].node.size();i++)
					{
						if(total[point[a]].node[i] == a)
						{
							value1 = total[point[a]].value[i];
							break;
						}
					}
					for(int i=0;i<total[point[b]].node.size();i++)
					{
						if(total[point[b]].node[i] == b)
						{
							value2 = total[point[b]].value[i];
							break;
						}
					}
					value3 = c + value1 - value2;

					for(int i=0;i<total[point[b]].node.size();i++)
					{
						total[point[a]].node.push_back(total[point[b]].node[i]);
						total[point[a]].value.push_back(total[point[b]].value[i] + value3);
					}

					if(total[point[b]].CF == 1)
						total[point[a]].CF = 1;
				}
			}
			else
			{
				scanf("%d %d",&a,&b);
				if(cond)
					printf("NC\n");
				if(point[a] == -1)
					printf("NC\n");
				else if(point[b] == -1)
					printf("NC\n");
				else if(point[a] == point[b])
				{
					if(total[point[a]].CF == 1)
					{
						printf("CF\n");
					}
					else
					{
						int value1,value2;
						for(int i=0;i<total[point[a]].node.size();i++)
						{
							if(total[point[a]].node[i] == a)
								value1 = total[point[a]].value[i];
							if(total[point[a]].node[i] == b)
								value2 = total[point[a]].value[i];
						}
						printf("%d\n",value2-value1);
					}
				}
				else
				{
					printf("NC\n");
				}
			}
		}
	}
}
