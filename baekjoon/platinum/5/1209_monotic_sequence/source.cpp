#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int A[2000];
int A_sort[2000];

long long inc(int pos, int inc_pos)
{
	if(pos == n)
		return 0;
	if(A_sort[inc_pos] >= A[pos])
		return (A_sort[inc_pos] - A[pos]) + inc(pos+1, inc_pos);

	long long ret = (long long)1000000000 * (long long)2000;
	long long cur_ret;
	for(int i=inc_pos;i<n;i++)
	{
		if(A_sort[i] > A[pos])
			break;
		cur_ret = (A[pos] - A_sort[i]) + inc(pos+1, i);
		ret = min(ret, cur_ret);
	}
	return ret;
}

long long dec(int pos, int dec_pos)
{
	if(pos == n)
		return 0;
	if(A_sort[dec_pos] <= A[pos])
		return (A[pos] - A_sort[dec_pos]) + dec(pos+1, dec_pos);

	long long ret = (long long)1000000000 * (long long)2000;
	long long cur_ret;
	for(int i=dec_pos;i>=0;i--)
	{
		if(A_sort[i] < A[pos])
			break;
		cur_ret = (A_sort[i] - A[pos]) + dec(pos+1, i);
		ret = min(ret, cur_ret);
	}

	return ret;
}

int main()
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
		A_sort[i] = A[i];
	}

	sort(A_sort, A_sort+n);

	printf("%lld\n",min(inc(0,0),dec(0,n-1)));

}
