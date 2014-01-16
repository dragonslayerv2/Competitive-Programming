#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
union REGS r;
void main (void)
{
int x=100,y=100;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
rectangle(100,100,200,120);
rectangle(102,102,198,118);
r.x.ax=0;
int86(0x33,&r,&r);
r.x.ax=1;
int86(0x33,&r,&r);
while(!kbhit())
{
r.x.ax=3;
x=r.x.cx;
y=r.x.dx;
int86(0x33,&r,&r);
if(x>102 && x<198 && y>102 && y<118)
{
setcolor(15);
outtextxy(105,105,"Over");
delay(100);
setcolor(0);
outtextxy(105,105,"Over");
}

}

getche();
closegraph();
}
