#include <stdio.h>
#include <algorithm>

using namespace std;

int n,k;
int array[500];

int save[501];


long long save_2[501];
const long long max_val = 2147483648;


typedef struct data{
   int key;
   int value;
}data;

data result[500];
int size;



int max(int a, int b)
{
   if(a>b)
      return a;
   else
      return b;
}

long long min(long long a, long long b)
{
   if(a<b)
      return a;
   else
      return b;
}


int func(int pos)
{
   if(save[pos+1] != -1)
      return save[pos+1];

   int ret = 1;



   for(int i=pos+1;i<n;i++)
   {
      if(pos == -1)
         ret = max(ret , 1+func(i));
      else if(array[pos] < array[i])
         ret = max(ret , 1+func(i));
   }
   save[pos+1] = ret;
   return ret;
   
}

long long func_2(int pos)
{
   if(save_2[pos+1] != -1)
      return save_2[pos+1];

   if(func(pos) == 1)
      return 1;

   long long ret = 0;

   for(int i = pos+1; i<n;i++)
   {
      if((func(pos) == func(i) + 1))
      {
         if(pos == -1)
            ret += func_2(i);
         else if(array[pos] < array[i])
            ret += func_2(i); 
      }
   }
   ret = min(ret,max_val);
   save_2[pos+1] = ret;
   return ret;

}

void func_3(int pos,long long skip)
{

   data temp[500];
   int temp_size = 0;
   for(int i=pos+1;i<n;i++)
   {
      if(func(pos) == func(i) + 1)
      {
         if(pos == -1)
         {
            temp[temp_size].key = i;
            temp[temp_size].value = array[i];
            temp_size++;
         }
         else if(array[pos] < array[i])
         {
            temp[temp_size].key = i;
            temp[temp_size].value = array[i];
            temp_size++;
         }
      }
   }






   long long cnt = 0;
   for(int i=temp_size - 1;i>-1;i--)
   {
      cnt = func_2(temp[i].key);
      if( (skip - cnt) < 0)
      {
         result[size].key = temp[i].key;
         result[size].value = temp[i].value;
         size++;
         func_3(temp[i].key,skip);
         break;
      }
      skip -= cnt;
   }



}

int main()
{
   int c;
   scanf("%d",&c);
   while(c--)
   {
      scanf("%d %d",&n,&k);
      
      for(int i=0;i<n;i++)
         scanf("%d",&array[i]);

      for(int i=0;i<n+1;i++)
         save[i] = -1;

      for(int i=0;i<n+1;i++)
         save_2[i] = -1;

      printf("%d\n",func(-1)-1);
      size = 0;
      func_3(-1,k-1);
      for(int i=0;i<size;i++)
      {
         printf("%d ",result[i].value);
      }
      printf("\n");
      
   }
}
