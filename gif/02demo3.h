#define FAILURE 1
#define SUCCESS 0
 
#define DRIVER_PATH "C:\\GIF" /* change the path if different */
 
#define SCRN_WIDTH     640
#define SCRN_HEIGHT 480
 
#define BSKTBALL_R    10
#define BSKTBALL_V    1
#define SKYLINE_Y    301

#define ESC	0x1b			/* Define the escape key	*/
#define TRUE	1			/* Define some handy constants	*/
#define FALSE	0			/* Define some handy constants	*/
#define PI	3.14159 		/* Define a value for PI	*/
#define ON	1			/* Define some handy constants	*/
#define OFF	0			/* Define some handy constants	*/



 
typedef struct _basketballTag
{
    int     x, y;
    int        radius;
    int     velocity;
} BASKETBALL_T;


 
/* initialize graph. */
int   init_graph(void);
/* play basketball animation. */
void bsktball_ani(void);

/* initialize basketball */
void bsktball_init(BASKETBALL_T *self, int x, int y, int radius);
/* set basket ball velocity */
void bsktball_setv(BASKETBALL_T *self, int velocity);
/* move basketball */
void bsktball_move(BASKETBALL_T *self);
/* draw basketball */
void bsktball_draw(const BASKETBALL_T *self);
/* draw background */
void draw_bkgnd(void);
/* clear zone */
void clr_zone(int x1, int y1, int x2, int y2);
/* draw skyline */
void draw_skyline(void);

extern void qiuqiu(void);
 
 