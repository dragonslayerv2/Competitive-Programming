#include<iostream.h>
#include<conio.h>
#include<process.h>

struct symbol
{
       char c;
       int count;
       symbol *next;
}*head=NULL;

symbol* createnode(char c)
{
     symbol *temp;
     temp=new symbol;
     if(temp==NULL)
     {
                   cout<<"NOT ENOUGH MEMORY";
                   getch();
                   exit(1);
     }
     temp->c=c;
     temp->count=1;
     temp->next=NULL;
     return temp;
}

void insert(symbol *x)
{
     if(head==NULL)
     {
                   head=x; 
     } 
     else
     {
                   x->next=head;
                   head=x;
     }
}
void del()
{
     symbol *x;
     
     while(head)
     {
                x=head;
                head=head->next;
                delete x;
     }
}
void print()
{
     symbol *x=head;
     while(x)
     {
      cout<<x->c<<"   "<<x->count<<endl;
      x=x->next;
     }
}
int search(char c)
{
    symbol *p;
    p=head;
    while(p)
    {
           if(p->c==c)
           {
                      p->count++;
                      return 1;
           }
    p=p->next;       
    }
    return -1;
}
void min()
{
 int min=head->count;
 char minchar=head->c;
 symbol *x=head;
 while(x)
 {
            if(x->count<min)
            {
                            
                            system("cls");
                            min=x->count;
                            minchar=x->c;
            }          
            else if(x->count==min)
            {
                 cout<<x->c;
            }
            x=x->next;
 
 }
} 
int main()
{
     while(1)
     {
             char c=getche();
             
             if(search(c)==-1)
             {
                              insert(createnode(c));                 
             }
             if(c=='\b')
                      break;
     }
     system("cls");
            min();
             printf("\n\n");
             print();
             getch();
}
