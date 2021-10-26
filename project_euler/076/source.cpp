#include <stdio.h>

int cache[101];

int min(int a, int b) {
	if(a<b)
		return a;
	return b;
}

int func(int n, int max) {
	int ret = 0;

	for(int i=n;i>0;i--) {
		if(i > max) {
			ret += func(n-i, max);
		}
		else {
			ret += (1 + func(n-i, min(max, i)));
		}
	}

	return ret;
}

int main() {
	for(int i=0;i<101;i++)
		cache[i] = -1;
	for(int i=1;i<10;i++)
		printf("%d: %d\n",i,func(i,i-1));
}
