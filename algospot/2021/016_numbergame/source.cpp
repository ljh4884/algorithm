#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
int array[50];
int save[50][50][2];
const int c_val = 100000001;

int func(int left,int right,int turn)
{
	if(save[left][right][turn] != -1)
		return save[left][right][turn];
	if(left == right)
	{
		if(turn == 0)
			return array[left];
		else
			return -array[left];
	}
	else if(left > right)
		printf("error\n");
	int pick_left;
	int pick_right;
	int pick_no_left;
	int pick_no_right;
	int pick;
	if(turn == 0)
	{
		pick = -c_val;
		
		pick_left = array[left] + func(left+1,right,!turn);
		pick = max(pick,pick_left);

		pick_right = array[right] + func(left,right-1,!turn);
		pick = max(pick,pick_right);

		if((right - left) > 1)
		{
			
			pick_no_left = func(left+2,right,!turn);
			pick = max(pick,pick_no_left);

			pick_no_right = func(left,right-2,!turn);
			pick = max(pick,pick_no_right);
		}
	
	}
	else
	{
		pick = c_val;
		pick_left = func(left+1,right,!turn) - array[left];
		pick = min(pick,pick_left);

		pick_right = func(left,right-1,!turn) - array[right];
		pick = min(pick,pick_right);

		if((right - left) > 1)
		{
			pick_no_left = func(left+2,right,!turn);
			pick = min(pick,pick_no_left);

			pick_no_right = func(left,right-2,!turn);
			pick = min(pick,pick_no_right);
		}

	}

	save[left][right][turn] = pick;
	return pick;

	

}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<2;k++)
					save[i][j][k] = -1;
		printf("%d\n",func(0,n-1,0));

	}
}
