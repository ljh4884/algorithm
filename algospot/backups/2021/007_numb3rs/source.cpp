#include <stdio.h>

int array[50][50];
int n,d,p,t;
double save[101][50][50];



double func(int rest_day,int pos,int pick)
{
   if(rest_day == 0)
   {
      if(pos == pick)
         return 1;
      else
         return 0;
   }

   if(save[rest_day][pos][pick] > -0.5)
      return save[rest_day][pos][pick];

   double ret = 0;
   double size = 0;
   
   for(int i=0;i<n;i++)
      size+=array[pos][i];


   for(int i=0;i<n;i++)
      if(array[pos][i] == 1)
         ret +=  (func(rest_day - 1,i,pick)/size);

   save[rest_day][pos][pick] = ret;
   return ret;
}



int main()
{
   int c;
   scanf("%d",&c);
   while(c--)
   {

      scanf("%d %d %d",&n,&d,&p);

      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            scanf("%d",&array[i][j]);

      for(int i=0;i<d+1;i++)
         for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
               save[i][j][k] = -1;
         
      scanf("%d",&t);
      for(int i=0;i<t;i++)
      {
         int temp;
         scanf("%d",&temp);
         printf("%.8lf ",func(d,p,temp));
      }
      printf("\n");

   }
}
