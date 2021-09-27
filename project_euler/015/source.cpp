#include <stdio.h>


long long cache[21][21];
int end = 20;
long long func(int y, int x) {
	long long ret = 0;
	if(cache[y][x] != -1)
		return cache[y][x];
	if(y == end && x == end) {
		return 1;
	}
	if(y != end) {
		ret += func(y+1,x);
	}
	if(x != end) {
		ret += func(y,x+1);
	}
	cache[y][x] = ret;
	return ret;
}

int main() {
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			cache[i][j] = -1;

	for(int i=1;i<=20;i++)
	{
		for(int j=0;j<21;j++)
			for(int k=0;k<21;k++)
				cache[j][k] = -1;
		end = i;
		printf("%lld\n",func(0,0));
	}
}
