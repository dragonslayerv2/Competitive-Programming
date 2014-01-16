/*
Name:Helicopter game using Allegro Game Library
Author:Ankush Chauhan
Date: 31/07/12 12:42
*/

#include <allegro.h>

void init();
void deinit();
BITMAP *bmp;
void generate_obs(void);
void attrib_init(void);
void draw_helicopter(void);
void draw_obstacle(void);
int check_collision(void);
void gameover(void);
void show_score(void);
int obs_x_pos,obs_y_pos;//Variables storing Obstacle coordinates
int obs_x_len,obs_y_len;//Variables storing Obstacle Size
int hel_x_pos,hel_y_pos;//Variables storing Helicopter coordinates
int hel_x_len,hel_y_len;//Variables storing Helicopter Size
int game_status;
long int score;

int main()
{
    init(); //Initailize Allegro
    int check,air_resistance,speed_obs,gravity,throttle,check_obs;
    gravity=2;//Optimum values 2..5
    check=0;//Dont Change
    check_obs=0;//Dont Change
    air_resistance=10;//Optimum values 1..20
    throttle=7;//Optimum values 1..10
    speed_obs=6;//Optimum values 5..1
    attrib_init();
  bmp=create_bitmap(640,480); //Create Bitmap for double buffering
int val;//declare variable user key input
    while (!key[KEY_ESC] ) //Exits when keyboard buffer contains ESC
    {

          
          clear_to_color(bmp, makecol(25,155,200));//Clear screen buffer
          draw_helicopter();//Draw helicopter havng fixed x-coordinate(SCREEN_W/2) and having variable y-coordinate
          draw_obstacle();
          show_score();
          blit(bmp,screen,0,0,0,0,640,480); //write bitmap to screen
          if((check_collision()==0) && (game_status==1))
          { check++;
                                   check_obs++;
                                   if(check==air_resistance)
                                   {
                                   check=0;
                                                   if (key[KEY_SPACE])
                                                      hel_y_pos=hel_y_pos-throttle;
                                                   else
                                                      hel_y_pos=hel_y_pos+gravity;
                                   }
                                   if(check_obs==speed_obs)
                                   {
                                   check_obs=0;
                                   if(!(obs_x_pos>=0 && obs_x_pos<=640))//Move obstacle closer
                                   {
                                   generate_obs();
                                                  if(score>0&&score%10==0&&speed_obs>1)//Level Increase at 10 Score
                                                                   speed_obs--;
                                   }
                                   else
                                   obs_x_pos-=1;
                                   }
          }
          else
          {
          gameover();
          }
                
       
}


deinit();
return 0;
}
END_OF_MAIN()

void generate_obs()
{
     clear_to_color(bmp, makecol(0,10,0));//Clear screen buffer
   if(obs_x_pos<=0)
   {
      obs_x_pos=SCREEN_W;
      obs_y_pos+=70;
      if(obs_y_pos<0||(obs_y_pos+obs_y_len)>SCREEN_H)
      obs_y_pos=1;
      
   }
   score++;
}
void draw_obstacle()
{ //Limit the size of any graphic routine from provided limits otherwise optimize collision_check()
     rectfill(bmp, obs_x_pos, obs_y_pos, obs_x_pos+obs_x_len, obs_y_pos+obs_y_len, makecol(205,20,20));
}


      
void draw_helicopter()
{ //Limit the size of any graphic routine from provided limits otherwise optimize collision_check()
     rectfill(bmp, hel_x_pos, hel_y_pos, hel_x_pos+hel_x_len, hel_y_pos+hel_y_len, makecol(205,100,100));
     circlefill(bmp, hel_x_pos+10, hel_y_pos+10, 5, makecol(200,200,200));
}
  
void show_score()
{
textprintf_right_ex(bmp, font, SCREEN_W-1, SCREEN_H-10, makecol(250, 200, 100),-1,"Score:%d ",score);
textprintf_centre_ex(bmp, font, SCREEN_W/2, 10, makecol(209, 247, 100),-1,"Throttle by Pressing SPACE or ESC. To Exit");
}

int check_collision()
{
    int a,b,c,d;
    if(hel_y_pos<=0||hel_y_pos>=SCREEN_H)//Map Boundary Collision
     return -1;
    for(a=hel_x_pos;a<hel_x_pos+hel_x_len;a++)
    for(b=hel_y_pos;b<hel_y_pos+hel_y_len;b++)
    for(c=obs_x_pos;c<obs_x_pos+obs_x_len;c++)
    for(d=obs_y_pos;d<obs_y_pos+obs_y_len;d++)
        if(a==c&&b==d)
         return -1;//Obstacle Collision
    return 0;
}
void gameover()
{
               int val;
               textprintf_centre_ex(screen, font, SCREEN_W/2, SCREEN_H/2-20, makecol(200, 255, 200),-1,"Game Over!!! Press y to retry or Esc to to exit");
               textprintf_centre_ex(screen, font, SCREEN_W/2, SCREEN_H/2+20, makecol(100, 100, 100),-1,"Your Score is %d",score);
               clear_keybuf();
               game_status=0;
               val= readkey();
               if (((val & 0xff) == 'y')||((val & 0xff) == 'Y'))
                  attrib_init();
           
}
void attrib_init()
{
             score=0;
             clear_keybuf();
             obs_x_len=5;
             obs_y_len=150;
             obs_x_pos=620;
             obs_y_pos=180;
             hel_x_pos=SCREEN_W/4;
             hel_y_pos=SCREEN_H/2;
             hel_x_len=20;
             hel_y_len=20;
             game_status=1;
}


void init()
{
int depth, res;
allegro_init();
depth = desktop_color_depth();
if (depth == 0) depth = 32;
set_color_depth(depth);
res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
if (res != 0)
{
allegro_message(allegro_error);
exit(-1);
}

install_timer();
install_keyboard();
install_mouse();
set_window_title("Helicopter Game Using Allegro By Ankush Chauhan");
}

void deinit()
{
clear_keybuf();
}
