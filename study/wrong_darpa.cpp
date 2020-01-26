#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <list>
#include <iomanip>
using namespace std;


int n,m;
double position[200];
double dis[200];
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int size;
		double result=9999;
		list<double> lt;
		lt.clear();
		scanf("%d %d",&n,&m);
			
		for(int i=0;i<m;i++)
		{
			scanf("%lf",&position[i]);		
		}
		for(int i=0;i<m-1;i++)
		{
			lt.push_back(position[i+1]-position[i]);
			//printf("%lf\n",position[i+1]-position[i]);
		}
		size = m-1;
		while(size>n-1)
		{
			double minsum=9999;
			list<double>::iterator iter=lt.begin();
			list<double>::iterator pos;
			list<double>::iterator pre;
			list<double>::iterator next;
			for(;iter!=lt.end();iter++)
			{
			
				if(*iter<minsum)
				{

					minsum = *iter;
					pos = iter;
				}
			}
			pre = pos;
			next= pos;
			next++;
			pre--;
			if(next==lt.end())
			{
				double temp = *pre;
				temp+=*pos;
				
				pre=lt.erase(pre);
				pre=lt.erase(pre);
				pre=lt.insert(pre,temp);
				
			}
			else if(pos==lt.begin())
			{
				double temp =*next;
				temp += *pos;
				pos=lt.erase(pos);
				pos = lt.erase(pos);
				pos = lt.insert(pos,temp);
			}
			else
			{
				if(*pre<*next)
				{
					double temp = *pre;
					temp+=*pos;
					pre=lt.erase(pre);
					pre=lt.erase(pre);
					pre=lt.insert(pre,temp);
				}
				else
				{
					double temp =*next;
					temp+=*pos;
					pos=lt.erase(pos);
					pos =lt.erase(pos);
					pos = lt.insert(pos,temp);
				}
			}
			size--;
		}
		list<double>::iterator iter;
		
		for(iter = lt.begin();iter!=lt.end();iter++)
		{
			//printf("%lf\n",*iter);
			result = min<double>(*iter,result);
		}
		//cout << result << setprecision(2)<< endl;
		result = result*100.0;
		result = round(result);
		result = result/100.0;
		printf("%.2lf\n",result);
	}
}
