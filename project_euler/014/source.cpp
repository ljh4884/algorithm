#include <stdio.h>

int main() {
	

	int max_cnt = -1;
	long long max_value = 0;
	int cnt[1000000];
	cnt[1] = 1;
	for(long long i=2;i<=1000000;i++) {
		long long num = i;
		int count = 0;
		while(1) {
			if(num < i) {
				count += cnt[num];
				if(count > max_cnt) {
					max_cnt = count;
					max_value = i;
				}
				cnt[i] = count;
				break;
			}
			if(num % 2 == 0) {
				num = num/2;
			}
			else {
				num = num*3 + 1;
			}
			count += 1;
		}

	}
	printf("%lld %d\n",max_value,max_cnt);
	printf("%d\n",cnt[17]);
}
