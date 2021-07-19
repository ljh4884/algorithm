#include <stdio.h>
#include <vector>

using namespace std;

vector<int> edge[501];

int A[2000];
int B[2000];
int visit[501];
char ans[2001];

int n,m,k;

int cycle(int pos)
{
	if(visit[pos] == -1)
		return 1; //cycle
	if(visit[pos] == 1)
		return 0; //not

	visit[pos] = -1;

	for(int i=0;i<edge[pos].size();i++)
	{
		if(cycle(edge[pos][i]) == 1)
			return 1;
	}
	visit[pos] = 1;
	return 0;
}

int solve(int a, int b)
{
	int ret;
	edge[a].push_back(b);
	for(int i=0;i<=n;i++)
		visit[i] = 0;
	ret = cycle(a);
	//edge[a].pop_back();
	return ret;
}

int main()
{
	int c;
	int cnt=1;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d %d",&n,&m,&k);
		
		
		for(int i=0;i<=n;i++)
			edge[i].clear();
			
		int a,b;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			edge[a].push_back(b);
		}
		for(int i=0;i<k;i++)
			scanf("%d %d",&A[i],&B[i]);

		for(int i=0;i<k;i++)
		{
			if(solve(A[i],B[i]) == 0)
			{
				ans[i] = '0';
			}
			else
			{
				edge[A[i]].pop_back();
				edge[B[i]].push_back(A[i]);
				ans[i] = '1';
			}
		}

		ans[k] = '\0';
		printf("Case #%d\n",cnt++);
		printf("%s\n",ans);



	}
}
