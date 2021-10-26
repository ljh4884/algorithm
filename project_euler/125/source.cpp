#include <stdio.h>
#include <math.h>

int main() {
	int eof = 0;
	int number = 0;
	int answer = 0;
	while(1){
		eof = scanf("%d",&number);
		if(eof == -1) {
			break;
		}

		int root_int = int(sqrt(number)) + 1;

		int pos = 1;
		int sum = 0;
		int break_cond = 0;
		for(pos = 1; pos < root_int; pos++) {
			if(sum == number && pos != 1) {
				answer += number;
				break_cond = 1;
				break;
			}
			else if(sum > number) {
				break;
			}
		}

		if(break_cond)
			break;

		int start = 1;
		int end = pos+1;

		while(1) {
			if(sum == number) {
				answer += number;
				break;
			}
			if(sum > number) {
				sum 
			}
		}

		

	}
}
