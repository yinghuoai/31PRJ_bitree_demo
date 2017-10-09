#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <assert.h>
#include <math.h>
#include <dos.h>
#include <stdarg.h>
#include "02demo3.h"



 
 
void qiuqiu(void)
{
    if (init_graph() == FAILURE)
    {
        printf("Initialize graph mode failure\n");
        exit(EXIT_FAILURE);
    }
 
    bsktball_ani();

	closegraph(); 	
    
}

 

 
 
 
 
 
/* initialize graph. */
int init_graph(void)
{
    int gdriver = VGA, gmode = VGAHI;
    int    err_code;
 
    initgraph(&gdriver, &gmode, DRIVER_PATH);
    if ((err_code = graphresult()) != grOk)
    {
        grapherrormsg(err_code);
        return FAILURE;
    }
    
	return SUCCESS;
	
}
 
 

 
 
/* play basketball animation. */
void bsktball_ani(void)
{
	int i = 0;
    BASKETBALL_T bsktball;
 
    bsktball_init(&bsktball,
                  BSKTBALL_R, SKYLINE_Y - BSKTBALL_R, BSKTBALL_R);
    bsktball_setv(&bsktball, -BSKTBALL_V);
 
    draw_bkgnd();
    while (!kbhit())
    {
        /* draw background, ground, basketball */
        clr_zone(bsktball.x - BSKTBALL_R, 0,
                 bsktball.x + BSKTBALL_R, SKYLINE_Y - 1);
        draw_skyline();
        bsktball_draw(&bsktball);
 
        /* move */
        bsktball_move(&bsktball);
		
		
		if( bsktball.x >= SCRN_WIDTH - 50 + bsktball.radius )
		{
			
			
			while(i<=16)
			{
				
				
				sound(100+100*i);
				delay(1500);
				
				
				i++;
			}


			nosound();
			break;

			
			
		}
		
		
		
		
    }
	
	
	
	
	
}
 
/* initialize basketball */
void bsktball_init(BASKETBALL_T *self, int x, int y, int radius)
{
    assert(self);
 
    memset((void *)self, 0, sizeof(BASKETBALL_T));
    self->x = x;
    self->y = y;
    self->radius = radius;
}
 
/* set basket ball velocity */
void bsktball_setv(BASKETBALL_T *self, int velocity)
{
    assert(self);
 
    self->velocity = velocity;
}
 
/* move basketball */
void bsktball_move(BASKETBALL_T *self)
{

    assert(self);

 
    if (((self->x - self->radius) < 0)  ||
        ((self->x + self->radius) >= SCRN_WIDTH))
		{
			
		self->velocity = -(self->velocity);			
			
		}
 


		
	    self->x += self->velocity;
	


	
	
	
}
 
/* draw basketball */
void bsktball_draw(const BASKETBALL_T *self)
{
    assert(self);
 
    setcolor(0);
    circle(self->x, self->y, self->radius);
    setfillstyle(SOLID_FILL,RED);
    fillellipse(self->x, self->y, self->radius, self->radius);
}
 
/* draw background */
void draw_bkgnd(void)
{
    setbkcolor(BLACK);
}
 
/* clear zone */
void clr_zone(int x1, int y1, int x2, int y2)
{
    setfillstyle(SOLID_FILL, getbkcolor());
    bar(x1, y1, x2, y2);
}
 
/* draw skyline */
void draw_skyline(void)
{

    setcolor(9);
    line(0, SKYLINE_Y, SCRN_WIDTH - 50, SKYLINE_Y);
    setcolor(6);
    line(SCRN_WIDTH - 50, SKYLINE_Y, SCRN_WIDTH - 1, SKYLINE_Y);
	
}




















