#include <stdio.h>


int end = 0;
int arr[400];

void func(int index, int prev) {


	int current = 0;
	arr[index] *= 2;
	arr[index] += prev;
	if(arr[index]/10 != 0) {
		current = arr[index]/10;
		arr[index] = arr[index]%10;
	}

	if(index == end) {
		if(current != 0) {
			arr[index+1] = current;
			end += 1;
		}
		return;
	}

	func(index+1, current);
	

}

int main() {
	
	for(int i=0;i<400;i++)
		arr[i] = 0;
	arr[0] = 1;
	for(int i=0;i<1000;i++) {
		func(0, 0);
	}

	int sum = 0;
	for(int i=0;i<400;i++)
		sum += arr[i];

	printf("%d %d\n",sum,end);
}
