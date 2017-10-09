#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <assert.h>
#include <math.h>
 
#define FAILURE 1
#define SUCCESS 0
 
#define DRIVER_PATH "C:\\GIF" /* change the path if different */
 
#define SCRN_WIDTH     640
#define SCRN_HEIGHT 480
 
#define BSKTBALL_R    10
#define BSKTBALL_V    1
#define SKYLINE_Y    301
 
typedef struct _basketballTag
{
    int     x, y;
    int        radius;
    int     velocity;
} BASKETBALL_T;

int    MaxColors;

 
/* initialize graph. */
static int     init_graph(void);
/* play basketball animation. */
static void bsktball_ani(void);
 
 
int main(void)
{
    if (init_graph() == FAILURE)
    {
        printf("Initialize graph mode failure\n");
        exit(EXIT_FAILURE);
    }
 
    bsktball_ani();
	closegraph(); 	
    return 0;
}
 
/* initialize graph. */
static int init_graph(void)
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
 
 
/* initialize basketball */
static void bsktball_init(BASKETBALL_T *self, int x, int y, int radius);
/* set basket ball velocity */
static void bsktball_setv(BASKETBALL_T *self, int velocity);
/* move basketball */
static void bsktball_move(BASKETBALL_T *self);
/* draw basketball */
static void bsktball_draw(const BASKETBALL_T *self);
/* draw background */
static void draw_bkgnd(void);
/* clear zone */
static void clr_zone(int x1, int y1, int x2, int y2);
/* draw skyline */
static void draw_skyline(void);
 
 
/* play basketball animation. */
static void bsktball_ani(void)
{
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
    }
}
 
/* initialize basketball */
static void bsktball_init(BASKETBALL_T *self, int x, int y, int radius)
{
    assert(self);
 
    memset((void *)self, 0, sizeof(BASKETBALL_T));
    self->x = x;
    self->y = y;
    self->radius = radius;
}
 
/* set basket ball velocity */
static void bsktball_setv(BASKETBALL_T *self, int velocity)
{
    assert(self);
 
    self->velocity = velocity;
}
 
/* move basketball */
static void bsktball_move(BASKETBALL_T *self)
{
    assert(self);
 
    if (((self->x - self->radius) < 0)  ||
        ((self->x + self->radius) >= SCRN_WIDTH))
		{
			
		self->velocity = -(self->velocity);			
			
		}
 
    self->x += self->velocity;
	self->radius += self->velocity;

	
}
 
/* draw basketball */
static void bsktball_draw(const BASKETBALL_T *self)
{
    assert(self);
 
    setcolor(0);
    circle(self->x, self->y, self->radius);
    setfillstyle(SOLID_FILL,RED);
    fillellipse(self->x, self->y, self->radius, self->radius);
}
 
/* draw background */
static void draw_bkgnd(void)
{
    setbkcolor(BLACK);
}
 
/* clear zone */
static void clr_zone(int x1, int y1, int x2, int y2)
{
    setfillstyle(SOLID_FILL, getbkcolor());
    bar(x1, y1, x2, y2);
}
 
/* draw skyline */
static void draw_skyline(void)
{
    setcolor(9);
    line(0, SKYLINE_Y, SCRN_WIDTH - 1, SKYLINE_Y);
}



