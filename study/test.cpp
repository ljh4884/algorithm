

#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string &N)
{
	int m = N.size();
	vector<int> pi(m,0);
	int begin = 1, matched = 0;

	while(begin+matched < m)
	{
		if(N[begin+matched] == N[matched])
		{
			++matched;
			pi[begin+matched-1]=matched;
		}
		else
		{
			if(matched == 0)
				++begin;
			else
			{
				begin+=matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> getPrefixSuffix(const string &s)
{
	vector<int> ret,pi = getPartialMatch(s);
	int k = s.size();
	while(k>0)
	{
		ret.push_back(k);
		k=pi[k-1];
	}
	return ret;
}

int main()
{
	string a;
	string b;
	cin >> a;
	cin >> b;

	vector<int> array = getPrefixSuffix(a+b);
	for(int i=array.size();i>0;i--)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
