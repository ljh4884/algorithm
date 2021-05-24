#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int m;
int size;
char e[16];
int e_num[15];
int e_ori[15];

const int mod =1000000007;

int save[1<<15][20][2];

int func(int bit,int divi,int check,int pos)
{
	if(pos == size)
	{
		if(check == 1 && divi == 0)
			return 1;
		else
			return 0;
	}
	
	if(save[bit][divi][check] != -1)
		return save[bit][divi][check];


	int prev = -1;
	int ret = 0;
	for(int i=0;i<size;i++)
	{
		int cur_check = 1;
		if((bit & (1<<i)) == 0)
		{
			if(prev == e_num[i])
				continue;
			if(check == 0 && e_ori[pos] < e_num[i])
				continue;
			if(check == 0 && e_ori[pos] == e_num[i])
				cur_check = 0;
			ret = (ret + func((bit | (1<<i)),(divi*10 + e_num[i])%m,cur_check,pos+1))%mod;
			prev = e_num[i];
		}
	}
	save[bit][divi][check] = ret;
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%s %d",e,&m);
		
		size = strlen(e);

		for(int i=0;i<size;i++)
		{
			e[i]-=48;
			e_ori[i] = e[i];
			e_num[i] = e[i];
		}

		for(int i=0;i<(1<<size);i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<2;k++)
					save[i][j][k] = -1;

		sort(e_num,e_num+size);

		printf("%d\n",func(0,0,0,0));
		
	}
}
