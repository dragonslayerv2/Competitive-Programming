#include<stdio.h>
#include<errno.h>
#include<conio.h>
void showdata(FILE *p)
{
     printf("%p\n",p->_ptr);
     printf("%d\n",p->_cnt);
     printf("%p\n",p->_base);
     printf("%d\n",p->_flag);
     printf("%d\n",p->_file);
     printf("%d\n",p->_charbuf);
     printf("%d\n",p->_bufsiz);
     printf("%p\n",p->_tmpfname);
     printf("------------\n\n");
    
     
}
int main()
{
 FILE*p;
  
 perror("");getch();
 p=fopen("output.txt","o");printf("%d",errno);
 perror("");getch();
 showdata(p);
 getch();
 fputc('s',p);
 showdata(p);
 getch();
 fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();fputc('s',p);
 showdata(p);
 getch();
 fgetc(p);
 showdata(p);
 
 
}
