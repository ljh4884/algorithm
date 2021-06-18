#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int *array)
{
	int i=0;
	for(i=0;i<12;i++)
	{
		if(array[i]%12!=0)
			break;
	}
	if(i==12)
		return 1;
	else
		return 0;
}

void fun1(int *array)
{
	array[0]+=3;
	array[1]+=3;
	array[2]+=3;
}

void fun2(int *array)
{
	array[3]+=3;
	array[7]+=3;
	array[9]+=3;
	array[11]+=3;
}
void fun3(int *array)
{
	array[4]+=3;
	array[10]+=3;
	array[14]+=3;
	array[15]+=3;
}

void fun4(int *array)
{
	array[0]+=3;
	array[4]+=3;
	array[5]+=3;
	array[6]+=3;
	array[7]+=3;
}

void fun5(int *array)
{
	array[6]+=3;
	array[7]+=3;
	array[8]+=3;
	array[10]+=3;
	array[12]+=3;

}
void fun6(int *array)
{
	array[0]+=3;
	array[2]+=3;
	array[14]+=3;
	array[15]+=3;
}
void fun7(int *array)
{
	array[3]+=3;
	array[14]+=3;
	array[15]+=3;
}
void fun8(int *array)
{
	array[4]+=3;
	array[5]+=3;
	array[7]+=3;
	array[14]+=3;
	array[15]+=3;
}
void fun9(int *array)
{
	array[1]+=3;
	array[2]+=3;
	array[3]+=3;
	array[4]+=3;
	array[5]+=3;

}
void fun10(int *array)
{
	array[3]+=3;
	array[4]+=3;
	array[5]+=3;
	array[9]+=3;
	array[13]+=3;
}

int run(int *array,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10)
{
	for(int b1=0;b1<a1;b1++)
	{
		fun1(array);
	}
	for(int b2=0;b2<a2;b2++)
	{
		fun2(array);
	}
	for(int b3=0;b3<a3;b3++)
	{
		fun3(array);
	}
	for(int b4=0;b4<a4;b4++)
	{
		fun4(array);
	}
	for(int b5=0;b5<a5;b5++)
	{
		fun5(array);
	}
	for(int b6=0;b6<a6;b6++)
	{
		fun6(array);
	}
	for(int b7=0;b7<a7;b7++)
	{
		fun7(array);
	}
	for(int b8=0;b8<a8;b8++)
	{
		fun8(array);
	}
	for(int b9=0;b9<a9;b9++)
	{
		fun9(array);
	}
	for(int b10=0;b10<a10;b10++)
	{
		fun10(array);
	}
	if(check(array)==1)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int min = 1100000;
		int array[16];

		for(int i=0;i<16;i++)
		{
			scanf("%d",&array[i]);
		}
		for(int a1=0;a1<4;a1++)
		{
			for(int a2=0;a2<4;a2++)
			{
				for(int a3=0;a3<4;a3++)
				{
					for(int a4=0;a4<4;a4++)
					{
						for(int a5=0;a5<4;a5++)
						{
							for(int a6=0;a6<4;a6++)
							{
								for(int a7=0;a7<4;a7++)
								{
									for(int a8=0;a8<4;a8++)
									{
										for(int a9=0;a9<4;a9++)
										{
											for(int a10=0;a10<4;a10++)
											{
												int temp[16];
												int sum=a1+a2+a3+a4+a5+a6+a7+a8+a9+a10;
												if(sum<min)
												{
													for(int i=0;i<16;i++)
													{
														temp[i]=array[i];
													}
													if(run(temp,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)==1)
														min=sum;
												}
												
												
												
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(min!=1100000)
			printf("%d\n",min);
		else
			printf("%d\n",-1);
	}
}
