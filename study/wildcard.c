#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *wild)
{
    for(int i=0;i<strlen(wild);i++)
    {
        if(wild[i]!='*')
            return 0;
    }
    return 1;
}

int find(char *wild,char *name)
{
    if(strlen(name)==0)
    {
        if(strlen(wild)==0)
            return 1;
        else
            return check(wild);
    }
    else
    {
        if(wild[0]=='*')
        {
            if(strlen(wild)==1)
                return 1;
            else
            {
                int sum=0;
                for(int i=0;i<strlen(name);i++)
                {
                    sum = sum|find(&wild[1],&name[i]);
                }
                return sum;
            }
        }
        else if(wild[0]=='?')
        {
            return find(&wild[1],&name[1]);
        }
        else
        {
            if(wild[0]==name[0])
                return find(&wild[1],&name[1]);
            else
                return 0;
        }
    }
}


void sort(char **name,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(name[i],name[j])>0)
            {
                char temp[100];
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
}

int main()
{
    int c,n;
    scanf("%d",&c);

    for(int cnt=0;cnt<c;cnt++)
    {
        char *wild;
        char **name;
        char **save;
        int count=0;
        wild = (char*)malloc(sizeof(char)*100);
        scanf("%s",wild);
        scanf("%d",&n);
        name = (char**)malloc(sizeof(char*)*n);
        save = (char**)malloc(sizeof(char*)*n);
        for(int i=0;i<n;i++)
        {
            name[i]=(char*)malloc(sizeof(char)*100);
            save[i]=(char*)malloc(sizeof(char)*100);
            scanf("%s",name[i]);
            if(find(wild,name[i])==1)
            {
                strcpy(save[count],name[i]);
                count++;
            }
        }
        sort(save,count);
        for(int i=0;i<count;i++)
        {
            printf("%s\n",save[i]);
        
        }

    }

}
