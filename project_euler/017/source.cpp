#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, int> num_dict;
	num_dict[0] = 0;
	num_dict[1] = 3;
	num_dict[2] = 3;
	num_dict[3] = 5;
	num_dict[4] = 4;
	num_dict[5] = 4;
	num_dict[6] = 3;
	num_dict[7] = 5;
	num_dict[8] = 5;
	num_dict[9] = 4;
	num_dict[10] = 3;
	num_dict[11] = 6;
	num_dict[12] = 6;
	num_dict[13] = 8;
	num_dict[14] = 8;
	num_dict[15] = 7;
	num_dict[16] = 7;
	num_dict[17] = 9;
	num_dict[18] = 8;
	num_dict[19] = 8;
	num_dict[20] = 6;
	num_dict[30] = 6;
	num_dict[40] = 5;
	num_dict[50] = 5;
	num_dict[60] = 5;
	num_dict[70] = 7;
	num_dict[80] = 6;
	num_dict[90] = 6;


	int count = 11;

	for(int i=1;i<1000;i++)
	{
		int temp_cnt = 0;

		int a, b, c;
		int flag_a = 0;
		int flag_b = 0;
		a = i/100;
		b = (i%100) / 10;
		c = i%10;

		if(a != 0) {
			temp_cnt += num_dict[a];
			temp_cnt += 7;
			flag_a = 1;
		}

		if(b != 0) {
			if(b == 1) {
				flag_b = 1;
				temp_cnt += num_dict[b*10+c];
				if(flag_a == 1)
					temp_cnt += 3;
			}
			else {
				flag_b = 2;
				temp_cnt += num_dict[b*10];
				if(flag_a == 1)
					temp_cnt += 3;
			}
		}

		if(c != 0) {
			if(flag_a == 1 && flag_b == 0) {
				temp_cnt += 3;
			}
			if(flag_b != 1) {
				temp_cnt += num_dict[c];
			}
		}

		count += temp_cnt;

	}

	printf("%d\n",count);
}
