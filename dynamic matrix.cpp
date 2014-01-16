// Functions to create a 2D matrix and deallocate it...
int ** allocate(int r,int c)
{
     int **a=(int **)malloc(r*sizeof(int *));
     if(a==NULL) {return 0;}
    for(int i=0;i<r;i++)
    {
            a[i]=(int *)malloc(c*sizeof(int));
            if(a[i]==NULL) {return 0;}
    }
    return a; 
}
void deallocate(int **a,int r,int c)
{
          for(int i=0;i<r;i++)
          {
                    free(a[i]);
          }
          free(a);

}
