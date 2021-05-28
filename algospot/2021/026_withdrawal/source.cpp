#include <stdio.h>
#include <algorithm>

using namespace std;




typedef struct data
{
	double rank;
	double card;
	double divi;
}data;


bool compare(const data& d1, const data& d2)
{
	if(d1.divi == d2.divi)
		return d1.card > d2.card;
	return d1.divi < d2.divi;
}

int n,k;
data st[1000];
int check[1000];


double func(int count,double sum1,double sum2)
{
	if(count == n)
		return score;
	double temp = 1;
	double temp_index = -1;
	for(int i=0;i<n;i++)
	{
		if(check[i] == 1)
			continue;


		
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&st[i].rank,&st[i].card);
			st[i].divi = st[i].rank / st[i].card;
		}
	
		sort(st,st+n,compare);

		double sum1 = 0;
		double sum2 = 0;
		for(int i=0;i<k;i++)
		{
			sum1+=st[i].rank;
			sum2+=st[i].card;
		}


		printf("%lf\n",sum1/sum2);

	}
}
