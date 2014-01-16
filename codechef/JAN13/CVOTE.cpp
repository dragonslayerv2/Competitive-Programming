#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct chefs
{
        char name[20];
        char country[20];
        int votes;
};


struct cities
{
    char name[20];
    int votes;
}city[10005];
int comparechef (const void * a, const void * b)
{
    return strcmp( ((chefs*)a)->name, ((chefs*)b)->name);
}
int comparecities (const void * a, const void * b)
{
    return strcmp( ((cities*)a)->name, ((cities*)b)->name);
}
int positionchef(char *s,chefs *chef,int n)
{
    int pos;
    int l=1;
    int h=n;
    while(l<=h)
    {
     pos=(l+h)/2;
     int cond=strcmp(s,chef[pos].name);
    // printf("Comparing %s with %s got %d\n",s,chef[pos].name,cond);
     if(!cond)
                  return pos;
     else if(cond>0)
                      l=pos+1;
     else
                      h=pos-1;
    }
}
int positioncity(char *s,cities *city,int n)
{
    int pos;
    int l=1;
    int h=n;
    while(l<=h)
    {
     pos=(l+h)/2;
     int cond=strcmp(s,city[pos].name);
    // printf("Comparing %s with %s got %d\n",s,chef[pos].name,cond);
     if(!cond)
                  return pos;
     else if(cond>0)
                      l=pos+1;
     else
                      h=pos-1;
    }
}
int main()
{
        int n,m;
        int k=1;
        chefs chef[10005];
        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++)
        {
                scanf("%s",chef[i].name);
                scanf("%s",chef[i].country);
                chef[i].votes=0;

                int flag=0;
                for(int j=1;j<k;j++)
                {
                    if(!strcmp(chef[i].country,city[j].name))
                        flag=1;
                }
                if(!flag)
                {
                        strcpy(city[k].name,chef[i].country);
                        city[k].votes=0;
                        k++;
                }
        }

        qsort (chef+1, n, sizeof(chefs), comparechef);
        qsort (city+1, k-1, sizeof(cities), comparecities);


        int max=-1;
        int anschef=-1;

        for(int i=0;i<m;i++)
        {
            char input[20];
            scanf("%s",input);
            int pos=positionchef(input,chef,n);
            chef[pos].votes++;

            if(max<chef[pos].votes)
            {
                max=chef[pos].votes;
                anschef=pos;
            }
            else if(max==chef[pos].votes&&pos<anschef)
                anschef=pos;
        }
        max=-1;
        int anscity=-1;
        for(int i=1;i<=n;i++)
        {
            int pos=positioncity(chef[i].country,city,k-1);
            city[pos].votes+=chef[i].votes;
            if(max<city[pos].votes)
            {
                max=city[pos].votes;
                anscity=pos;
            }
            else if(max==city[pos].votes&&pos<anscity)
                anscity=pos;
        }

/*
        printf("---Details----\n");
        for(int i=1;i<k;i++)
        {
            printf("%s %d\n",city[i].name,city[i].votes);

        }*/
        printf("%s\n",city[anscity].name);
        printf("%s\n",chef[anschef].name);

        return 0;
}
