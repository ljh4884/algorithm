/* 
 * 오답이 나던 이유 
 * double로 형변형 한걸 다시 int로 형변환 할경우  예)  (double)57 = 56.9999 일수가 있는데 이걸 다시 int로 형변환 하면 56이 되어버림
 * 그래서 그냥 전부다 longlong 을 써서 double로 형변환 하지 않도록 함
 */

#include <stdio.h>
#include <stdlib.h>

long long n,m,z;

bool func(long long input)
{
	
	long long newn=n+input;
	long long newm=m+input;
	long long newz = (newm*100)/newn;
	return newz>z;
}

long long opt()
{
	long long start = 0;
	long long end = 2000000001;
	for(int i=0;i<100;i++)
	{
		long long mid = (start+end)/2;
		if(func(mid))
			end=mid;
		else
			start=mid;
	}
	return end;
}



int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lld %lld",&n,&m);
		z = (m*100)/n;
		long long temp = opt();
		if(temp!=2000000001)
			printf("%lld\n",temp);
		else
			printf("-1\n");
	}
}
