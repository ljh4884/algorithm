#include <stdio.h>

int arr[15][15];
int cache[15][15];
int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}

int func(int y, int x) {
	if(y == 15) {
		return 0;
	}
	if(x<0 || x > y) {
		return -1000000;
	}
	if(cache[y][x] != -1)
		return cache[y][x];

	cache[y][x] = arr[y][x] + max(func(y+1, x), func(y+1, x+1));
	return cache[y][x];
}

int main() {
	for(int i=0;i<15;i++)
		for(int j=0;j<i+1;j++)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<15;i++)
		for(int j=0;j<i+1;j++)
			cache[i][j] = -1;
	printf("%d\n",func(0,0));
}
