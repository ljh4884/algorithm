#include <stdio.h>
#include <string.h>

int n,w;

char name[100][21];
int score[100];
int volume[100];
const int num = -10000000;

int save[100][1001];


char result[100][21];
int count;

int max(int a, int b)
{
   if(a<b)
      return b;
   else
      return a;
}

int func(int pos,int v)
{
   
   if(v > w)
      return num;
   if(pos == n)
      return 0;

   if(save[pos][v] != -1)
      return save[pos][v];
   save[pos][v] = max(func(pos+1,v),score[pos] + func(pos+1,v+volume[pos]));
   return save[pos][v];


}

void func2(int pos, int v, int s)
{
   if(pos == n-1)
   {
      if(s != 0)
      {
         strcpy(result[count],name[pos]);
         count++;
         return;
      }
      return;
   }

   
   if(save[pos+1][v+volume[pos]] == s - score[pos])
   {
      strcpy(result[count],name[pos]);
      count++;
      func2(pos+1,v+volume[pos],s-score[pos]);
   }
   else
      func2(pos+1,v,s);
}

int main()
{
   int c;
   scanf("%d",&c);
   while(c--)
   {
      scanf("%d %d",&n,&w);
      
      for(int i=0;i<n;i++)
      {
         scanf("%s %d %d",name[i],&volume[i],&score[i]);
         
         for(int j=0;j<w+1;j++)
            save[i][j] = -1;

      }
      int ret = func(0,0);
      count = 0;

      func2(0,0,ret);

      printf("%d %d\n",ret,count);

      for(int i=0;i<count;i++)
      {
         printf("%s\n",result[i]);
      }
   }
}


