#include <stdio.h>
#include <algorithm>

using namespace std;

long double water[1000];
long double matter[1000];
int n;
long double m;

struct data
{
	long double water;
	long double matter;
	long double density;
};

struct data sol[1000];


bool compare(const struct data &d1, const struct data &d2)
{
	return d1.density < d2.density;
}

int main()
{
	long double temp_1;
	long double temp_2;

	long double sum_matter = 0;
	long double sum_water = 0;

	long double ans = 0;

	scanf("%d %Lf",&n,&m);
	
	m /= 100.0;
	for(int i=0;i<n;i++)
	{
		scanf("%Lf %Lf",&temp_1,&temp_2);
		sol[i].matter = (temp_2 * temp_1) / 100.0;
		sol[i].water = temp_2 - sol[i].matter;
		sol[i].density = temp_1; 

		sum_water += sol[i].water;
		sum_matter += sol[i].matter;
	}

	sort(sol,sol+n,compare);


	if(sol[n-1].density/100.0 < m)
	{
		printf("0.0\n");
	}
	else if(sol[0].density/100.0 > m)
	{
		printf("0.0\n");
	}
	else if( sum_matter/(sum_matter + sum_water) > m)
	{
		int i = n-1;
		for(; i>=0; i--)
		{
			if( (sum_matter - sol[i].matter) / (sum_matter - sol[i].matter + sum_water - sol[i].water) <= m )
			{
				break;
			}
			sum_matter -= sol[i].matter;
			sum_water -= sol[i].water;
		}
		double x = (m * sum_water + m * sum_matter - sum_matter) /
					(m * sol[i].matter + m * sol[i].water - sol[i].matter);
		ans = (sum_matter - x * sol[i].matter)/m;
		printf("%Lf\n",ans);
	}
	else if( sum_matter/(sum_matter + sum_water) < m)
	{
		int i = 0;
		for(; i<n; i++)
		{
			if( (sum_matter - sol[i].matter) / (sum_matter - sol[i].matter + sum_water - sol[i].water) >= m )
			{
				break;
			}
			sum_matter -= sol[i].matter;
			sum_water -= sol[i].water;
		}

		long double x = (m * sum_water + m * sum_matter - sum_matter) /
					(m * sol[i].matter + m * sol[i].water - sol[i].matter);
		ans = (sum_matter - x * sol[i].matter)/m;
		printf("%Lf\n",ans);
	}
	else
	{
		printf("%Lf\n",sum_water+sum_matter);
	}
	

}

