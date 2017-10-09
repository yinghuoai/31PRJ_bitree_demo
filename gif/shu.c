
#ifdef __TINY__
#error BGIDEMO will not run in the tiny model.
#endif


#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <assert.h>
#include <math.h>
#include <dos.h>
#include <stdarg.h>






#define ESC	0x1b			/* Define the escape key	*/
#define TRUE	1			/* Define some handy constants	*/
#define FALSE	0			/* Define some handy constants	*/
#define PI	3.14159 		/* Define a value for PI	*/
#define ON	1			/* Define some handy constants	*/
#define OFF	0			/* Define some handy constants	*/
#define SOUND 4000
#define DELAY 10
#define FAILURE 1
#define SUCCESS 0
 
#define DRIVER_PATH "C:\\GIF" /* change the path if different */
 
#define SCRN_WIDTH     640
#define SCRN_HEIGHT 480
 
#define BSKTBALL_R    10
#define BSKTBALL_V    1
#define SKYLINE_Y    301


struct PTS {
  int x, y;
};	/* Structure to hold vertex points	*/

int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
double AspectRatio;		/* Aspect ratio of a pixel on the screen*/
int    MaxX, MaxY;		/* The maximum resolution of the screen */
int    MaxColors;		/* The maximum # of colors available	*/
int    ErrorCode;		/* Reports any graphics errors		*/
struct palettetype palette;		/* Used to read palette info	*/


typedef struct _basketballTag
{
    int     x, y;
    int        radius;
    int     velocity;
} BASKETBALL_T;


 
  
typedef struct tree_node  
{  
    char data[2];  
    struct tree_node *lchild,*rchild;  
	int depth,x,y,color,biaoji;
	
	
	
}BiTNode;
#define Tree_NodeLen sizeof(BiTNode) 



void StatusLine( char *msg );
void DrawBorder(void);
void changetextstyle(int font, int direction, int charsize);
void MainWindow( char *header );
void visit(BiTNode *tree);  
void PreOrderTraverse(BiTNode *tree);  
void InOrderTraverse(BiTNode *tree);  
void PostOrderTraverse(BiTNode *tree); 
void PreOrderTraverse2(BiTNode *tree);
void InOrderTraverse2(BiTNode *tree);
void PostOrderTraverse2(BiTNode *tree);
 
BiTNode *CreateBiTree(BiTNode *tree);
void Pause(void);
void Pause2(char*);
void ColorDemo(void);
int gprintf( int *xloc, int *yloc, char *fmt, ... );
void Initialize(void);
void ReportStatus(void);
void PaletteDemo(void);
void TextDemo(void);
void CircleDemo(void);
void shixinDemo(BiTNode *tree,int color);
void lineshow(BiTNode *tree,int lcolor);
void yin();

void displayLeaf(BiTNode* tree); 
BiTNode*   search(BiTNode* tree,char ch);
void search2(BiTNode* tree,char ch); 
void clear(BiTNode* tree);

void delete(BiTNode* tree);

void show(BiTNode *tree);
void command();


 

int   init_graph(void);

void bsktball_ani(void);


void bsktball_init(BASKETBALL_T *self, int x, int y, int radius);

void bsktball_setv(BASKETBALL_T *self, int velocity);

void bsktball_move(BASKETBALL_T *self);

void bsktball_draw(const BASKETBALL_T *self);

void draw_bkgnd(void);

void clr_zone(int x1, int y1, int x2, int y2);

void draw_skyline(void);

extern void qiuqiu(void);


 

 
 
 
 
 

BiTNode* tree=NULL;

char *Fonts[] = {
  "DefaultFont",   "TriplexFont",   "SmallFont",
  "SansSerifFont", "GothicFont"
};

char *LineStyles[] = {
  "SolidLn",  "DottedLn",  "CenterLn",  "DashedLn",  "UserBitLn"
};

char *FillStyles[] = {
  "EmptyFill",  "SolidFill",      "LineFill",      "LtSlashFill",
  "SlashFill",  "BkSlashFill",    "LtBkSlashFill", "HatchFill",
  "XHatchFill", "InterleaveFill", "WideDotFill",   "CloseDotFill"
};

char *TextDirect[] = {
  "HorizDir",  "VertDir"
};

char *HorizJust[] = {
  "LeftText",   "CenterText",   "RightText"
};

char *VertJust[] = {
  "BottomText",  "CenterText",  "TopText"
};


char* msg1 = "SUCCESS: preorder  \n  press a to menu";
char* msg2 = "SUCCESS: inorder  \n   press a to menu";
char* msg3 = "SUCCESS: postorder \n  press a to menu";
char* msg4 = "SUCCESS: leaf  \n  press a to menu";
char* msg5 = "SUCCESS: find  \n  press a to menu";
char* msg6 = "SUCCESS: delete  \n  press a to menu";
char* msg7 = "SUCCESS: insert  \n  press a to menu";
char* msg8 = "SUCCESS: exit  \n   press a to menu";
char* msg9 = "please choose  \n   press a to menu";
char* msg10 = "SUCCESS: help  \n   press a to menu";
char* msg11 = "MENU  \n  press a to menu";
char* msg12 = "input error!!!  \n  press a to menu";
 
int main(void)  
{  
	BiTNode* p;
	char ch;

	int color=1,lcolor =15;
	
	

	
	
	qiuqiu();
	
	Initialize(); 		
	
    printf("\n please input tree node:\n ");  
    tree = CreateBiTree(tree);  
		
	
	
		

	
	
 

	
	



	
	MainWindow( "bitree" );
	StatusLine( "this is your bitree" );



	lineshow(tree,lcolor-11);		
	shixinDemo(tree,color);
	yin();	
	delay(2000);
	
		
	ReportStatus();
	Pause2(msg9);

	
 
	closegraph(); 
	
	
	

	
		
  return(0);
  
  
}  

void command()
{
	printf("please input command:   ");
	
}




void Pause()
{
  static char msg[] = "Esc aborts or press a key...";
  int c;

  StatusLine( msg );			

  c = getch();				

  if( ESC == c ){			
    closegraph();			
    exit( 1 );				
  }

  if( 0 == c ){ 			
    c = getch();			
  }

  cleardevice();			

}


void Pause2(char* msg)
{
  
  	BiTNode* p;


	int color=1,lcolor =15;
  
	int c;

  
  
  StatusLine( msg );		

  c = getch();	

	cleardevice();
  
	switch(c)
	{
		case '1':
		
			lineshow(tree,lcolor-11);		
			shixinDemo(tree,color);
			PreOrderTraverse(tree);
			yin();
			Pause2(msg1);
		
			break;
		case '2':
		
			lineshow(tree,lcolor-11);		
			shixinDemo(tree,color);
			InOrderTraverse(tree);
			yin();
			Pause2(msg2);	
		
		
			break;
			
		case '3':
		
			lineshow(tree,lcolor-11);		
			shixinDemo(tree,color);
			PostOrderTraverse(tree);
			yin();
			Pause2(msg3);	
							
		
			break;
			
			
		case '4':
		
	
			lineshow(tree,lcolor-11);		
			shixinDemo(tree,color);
			displayLeaf(tree);
			yin();	
			Pause2(msg4);
					
				
		
			break;
		case '5':
		
			
			p=search(tree,'b');

			
			if(p)
			{

				lineshow(tree,lcolor-11);		
				shixinDemo(tree,color);	
				
				setcolor(4);	
				setfillstyle( 1,4);	
				pieslice( p->x, p->y,0,360 ,MaxY /30 );
				setcolor(15); 
				settextstyle(0,0, 1); 
				outtextxy(p->x,p->y, p->data); 			
				
				
				
				yin();	
				Pause2(msg5);
				
			}
					
		
		
			break;
		case '6':
			
			
		
			delete(tree);
			
			
			lineshow(tree,lcolor-11);		
			shixinDemo(tree,color);
			yin();
			Pause2(msg6);
		
			break;
		case '7':
		
		
		
			break;
		case '8':
		
			closegraph();			
			exit( 1 );	
		
			break;
					
		case '9':
	

		
			break;
		case 'a':
	
			ReportStatus();	
			Pause2(msg9);
			break;
					
		default:
		
		
			lineshow(tree,lcolor);		
			shixinDemo(tree,color);
			yin();
			Pause2(msg12);
		
		
		
		
	}
  

  if( ESC == c ){			
    closegraph();			
    exit( 1 );				
  }

  if( 0 == c ){ 			
    c = getch();			
  }

  cleardevice();			

}




void ColorDemo(void)
{
  struct viewporttype vp;
  int color, height, width;
  int x, y, i, j;
  char cnum[5];

  MainWindow( "Color Demonstration" );

  color = 1;
  getviewsettings( &vp );		
  width  = 2 * ( (vp.right+1) / 16 );	  
  height = 2 * ( (vp.bottom-10) / 10 );

  x = width / 2;
  y = height / 2;	

  for( j=0 ; j<3 ; ++j ){		

    for( i=0 ; i<5 ; ++i ){		

      setfillstyle(SOLID_FILL, color);	
      setcolor( color );		

      bar( x, y, x+width, y+height );	
      rectangle( x, y, x+width, y+height ); 

      if( color == BLACK ){		
	setcolor( WHITE );		
	rectangle( x, y, x+width, y+height );  
      }

      itoa( color, cnum, 10 );		
      outtextxy( x+(width/2), y+height+4, cnum );  

      color = ++color % MaxColors;	
      x += (width / 2) * 3;		
    }				

    y += (height / 2) * 3;		
    x = width / 2;			
  }					

  Pause();				

}



void MainWindow( char *header )
{
  int height;

  cleardevice();			
  setcolor( MaxColors - 1 );		
  setviewport( 0, 0, MaxX, MaxY, 1 );	

  height = textheight( "H" );            

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  outtextxy( MaxX/2, 2, header );
  setviewport( 0, height+4, MaxX, MaxY-(height+4), 1 );
  DrawBorder();
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}


void StatusLine( char *msg )
{
  int height;

  setviewport( 0, 0, MaxX, MaxY, 1 );	
  setcolor(13);		

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
  setfillstyle( EMPTY_FILL, 0 );

  height = textheight( "H" );          
  bar( 0, MaxY-8*(height+4), MaxX, MaxY );
  rectangle( 0, MaxY-8*(height+4), MaxX, MaxY );
  outtextxy( MaxX/2, MaxY-8*(height+2), msg );
  setviewport( 1, height+5, MaxX-1, MaxY-8*(height+5), 1 );

}


void DrawBorder(void)
{
  struct viewporttype vp;

  setcolor( MaxColors - 1 );		

  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

  getviewsettings( &vp );
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}

void changetextstyle(int font, int direction, int charsize)
{
  int ErrorCode;

  graphresult();			
  settextstyle(font, direction, charsize);
  ErrorCode = graphresult();		
  if( ErrorCode != grOk ){		
    closegraph();
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}

int gprintf( int *xloc, int *yloc, char *fmt, ... )
{
  va_list  argptr;			
  char str[140];			
  int cnt;				

  va_start( argptr, format );		

  cnt = vsprintf( str, fmt, argptr );	
  outtextxy( *xloc, *yloc, str );	
  *yloc += textheight( "H" ) + 2;          

  va_end( argptr );			

  return( cnt );			

}



void Initialize(void)
{
  int xasp, yasp;			

  GraphDriver = DETECT; 		
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();		
  if( ErrorCode != grOk ){		
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }

  getpalette( &palette );		
  MaxColors = getmaxcolor() + 1;	

  MaxX = getmaxx();
  MaxY = getmaxy();			

  getaspectratio( &xasp, &yasp );	
  AspectRatio = (double)xasp / (double)yasp; 

}

void ReportStatus(void)
{
  struct viewporttype	  viewinfo;	
  struct linesettingstype lineinfo;
  struct fillsettingstype fillinfo;
  struct textsettingstype textinfo;
  struct palettetype	  palette;

  char *driver, *mode;			
  int x, y;

  getviewsettings( &viewinfo );
  getlinesettings( &lineinfo );
  getfillsettings( &fillinfo );
  gettextsettings( &textinfo );
  getpalette( &palette );

  x = 10;
  y = 4;

  MainWindow( "menu choice: " );
  settextjustify( LEFT_TEXT, TOP_TEXT );

  settextstyle(0,0,2);
  setcolor(2);

  gprintf( &x, &y, "(1)  preorder" );
  gprintf( &x, &y, "(2)  inorder");
  gprintf( &x, &y, "(3)  postorder" );

  gprintf( &x, &y, "(4)  leaf");
  gprintf( &x, &y, "(5)  find a p/i/l" );

  gprintf( &x, &y, "(6)  del a" );
  gprintf( &x, &y, "(7)  insert z w l/r");
  gprintf( &x, &y, "(8)  exit" );
  gprintf( &x, &y, "(9)  help");
  gprintf( &x, &y, "(a)  menu" );

  

 
				

}



void PaletteDemo(void)
{
  int i, j, x, y, color;
  struct viewporttype vp;
  int height, width;

  MainWindow( "Palette Demonstration" );
  StatusLine( "Press any key to continue, ESC to Abort" );

  getviewsettings( &vp );
  width  = (vp.right - vp.left) / 15;	
  height = (vp.bottom - vp.top) / 10;	

  x = y = 0;				
  color = 1;				


      setfillstyle( SOLID_FILL, color++ );	
      bar( x, y, x+width, y+height );		
      x += width + 1;				
      color = 1 + (color % (MaxColors - 2));	
  
  
  while( !kbhit() ){			
    setpalette( 1+random(MaxColors - 2), random( 65 ) );
  }

  setallpalette( &palette );

  Pause();				

}


void CircleDemo(void)
{
  int mradius;				

  MainWindow( "Circle Demonstration" );
  StatusLine( "ESC Aborts - Press a Key to stop" );

  mradius = MaxY / 20;			/* Determine the maximum radius */

  while( !kbhit() ){			/* Repeat until a key is hit	*/
    setcolor( random( MaxColors - 1 ) + 1 );	/* Randomly select a color	*/
    setfillstyle( 2,2);	
	circle( MaxX/2, MaxY/2, mradius );
     	/* Set the color of box */

	
	
  }					/* End of WHILE not KBHIT	*/

  Pause();				/* Wait for user's response     */

}

void shixinDemo(BiTNode *tree,int color)
{
  int mradius;				/* Maximum radius allowed	*/
  char c;
 
	tree->color=color;


	
    if(tree==NULL) 
	{
		return;  


	}	
    else{  
	
		

	
		mradius = MaxY /30;			/* Determine the maximum radius */
		setcolor(color);	/* Randomly select a color	*/
		setfillstyle( 1,color);	
		pieslice( tree->x, tree->y,0,360 ,mradius );
		setcolor(15); 
		settextstyle(0,0, 1); 
		outtextxy(tree->x,tree->y, tree->data); 	
	
        shixinDemo(tree->lchild,color);  
        shixinDemo(tree->rchild,color);  
		
		

		
    } 	

	
	
	
	


  
  
  

  
}




void lineshow(BiTNode *tree,int lcolor)
{
	if(tree==NULL) 
	{
		return;  


	}	
    else{ 
	
		if(tree->lchild!=NULL && tree->rchild!=NULL  ) 
		{
			setcolor(lcolor);
			line(tree->x, tree->y, tree->lchild->x, tree->lchild->y);

			setcolor(lcolor);
			line(tree->x, tree->y, tree->rchild->x, tree->rchild->y);
		
			
	
	
		}else if(tree->lchild!=NULL && tree->rchild==NULL  ) 
		{
			setcolor(lcolor);
			line(tree->x, tree->y, tree->lchild->x, tree->lchild->y);
		
			
			
			

		}else if(tree->lchild==NULL && tree->rchild!=NULL  ) 
		{

			setcolor(lcolor);
			line(tree->x, tree->y, tree->rchild->x, tree->rchild->y);

		}		
		
		
			lineshow(tree->lchild,lcolor);
			lineshow(tree->rchild,lcolor);
		
	}
	
	
	
}


void yin()
{
	int i=0;

	while(i<=16)
	{
		
		
		sound(100+100*i);
		delay(50);
		
		
		i++;
	}


	nosound();

	
	
	
}





BiTNode *CreateBiTree(BiTNode *tree)  
{  
    char ch1,ch2,ch3 ;  

    ch1 = getchar(); 
	ch2 = getchar();
	ch3 = getchar();

  
  
    if(ch1 == '.')  
    {  
        tree = NULL;  
    }  
    else  
    {  
        tree = (BiTNode *)malloc(Tree_NodeLen);  
        tree->data[0] = ch1;
        tree->data[1] = '\0';	
		tree->depth = ch2-'0';
		tree->biaoji = ch3-'0';
		tree->color = 1;
		tree->x = (MaxX/pow(2,tree->depth)  )*(tree->biaoji*2-1) ;
		tree->y = (MaxY/6)*(tree->depth-1)+20;
		
		
		
        tree->lchild = CreateBiTree(tree->lchild);  
        tree->rchild = CreateBiTree(tree->rchild);  
    }  
	
	
    return (tree);  
	
	
}  

void show(BiTNode *tree)
{
	
	if(tree->lchild!=NULL || tree->rchild!=NULL  ) 
		{
			
			if(tree->color==2&&tree->lchild->color==2)
			{
				
			setcolor(4);
			line(tree->x, tree->y, tree->lchild->x, tree->lchild->y);				
				
				
			}else if(tree->color==2&&tree->lchild->color==2)
			{
				setcolor(4);
				line(tree->x, tree->y, tree->rchild->x, tree->rchild->y);
					
			}
			
			



		
			
	
	
		}
			
				
		setcolor(2);	/* Randomly select a color	*/
		setfillstyle( 1,2);	
		pieslice( tree->x, tree->y,0,360 ,MaxY /30 );
		setcolor(15); 
		settextstyle(0,0, 1); 
		outtextxy(tree->x,tree->y, tree->data); 	
	
		delay(1000); 
  	
	
	
	
}






void visit(BiTNode *tree)  
{  
	
    printf(" ");  
    putchar(tree->data[0]);  
    printf("\t");  
}  

void PreOrderTraverse2(BiTNode *tree)  
{  



    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
		visit(tree);
		
        PreOrderTraverse2(tree->lchild);  
        
        PreOrderTraverse2(tree->rchild);  
    }  
  


  
} 


void PreOrderTraverse(BiTNode *tree)  
{  




    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
		show(tree);
        PreOrderTraverse(tree->lchild);  
        PreOrderTraverse(tree->rchild);  
		
    }  
}  


void InOrderTraverse2(BiTNode *tree)  
{  
    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
        InOrderTraverse(tree->lchild);  
        visit(tree);  
        InOrderTraverse(tree->rchild);  
    }  
  
}  
  



void InOrderTraverse(BiTNode *tree)  
{  
    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
        InOrderTraverse(tree->lchild);  
        

		show(tree);
  
  



		
        InOrderTraverse(tree->rchild);  
    }  
  
}  
  
  
  
  
  
  
  
  
void PostOrderTraverse2(BiTNode *tree)  
{  
    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
        PostOrderTraverse(tree->lchild);  
        PostOrderTraverse(tree->rchild);  
        visit(tree);  
    }  
} 
  
  

  
void PostOrderTraverse(BiTNode *tree)  
{  
    if(!tree)  
    {  
        return;  
    }  
    else  
    {  
        PostOrderTraverse(tree->lchild);  
        PostOrderTraverse(tree->rchild);  
        show(tree);  
    }  
} 


void displayLeaf(BiTNode* tree)  
{  
	int mradius;
	
    if(tree==NULL)  
        return;  
    if(tree->lchild ==NULL && tree->rchild==NULL)  
	{
		mradius = MaxY /30;			/* Determine the maximum radius */
		setcolor(14);	/* Randomly select a color	*/
		setfillstyle( 1,14);	
		pieslice( tree->x, tree->y,0,360 ,mradius );
		setcolor(15); 
		settextstyle(0,0, 1); 
		outtextxy(tree->x,tree->y, tree->data); 
		
	} 
    else{  
        displayLeaf(tree->lchild);  
        displayLeaf(tree->rchild);  
    }  
}  
  
BiTNode*   search(BiTNode* tree,char ch)  
{  
    BiTNode* p;  
    if(tree==NULL)  
        return NULL;  
    if(tree->data[0]==ch)  
        return tree;  
    else{  
        if((p=search(tree->lchild,ch))!=NULL)  
            return p;  
        else  
            return  search(tree->rchild,ch);    
    }  
}  
  
void   search2(BiTNode* tree,char ch)  
{  
  
    if(tree==NULL )  
        return;  

	
    if(tree->lchild->data[0]==ch  )  
	{
		tree->lchild=NULL;
		return;
		
	}else if( tree->rchild->data[0]==ch  )  
	{
		tree->rchild=NULL;
		return;
		
	}  
    else{  
			search2(tree->lchild,ch);
            search2(tree->rchild,ch);    
    }  
	
	
}  
  
  
  
  
void delete(BiTNode* tree)
{
	BiTNode* p;
	char c;

	cleardevice();
	printf("please input delete node: ");
	
	scanf("%c",&c);

	cleardevice();
	
	p=search(tree,c);
	if(!p)
	{
		
		Pause2(msg12);
		return;
		
	}else
	{
		search2(tree,c);
	}
	

	

	
	
}
  
  
  




void inseartLeftNode(BiTNode* tree,char ch)  
{  
    BiTNode* p;
	BiTNode* newNode;  
    if(tree==NULL)  
        return;  
    p=tree->lchild;  
    newNode=(BiTNode*)malloc(sizeof(BiTNode));  
    newNode->data[0]=ch;  
    newNode->rchild=NULL;  
    newNode->lchild=p;  
    tree->lchild=newNode;  
}  
  

void inseartRightNode(BiTNode* tree,char ch)  
{  
    BiTNode* p;
	BiTNode* newNode; 
	
    if(tree==NULL)  
        return;  
    p=tree->rchild;  
    newNode=(BiTNode*)malloc(sizeof(BiTNode));  
    newNode->data[0]=ch;  
    newNode->lchild=NULL;  
    newNode->rchild=p;  
    tree->rchild=newNode;  
}  


int BTreeHeight(BiTNode* tree)  
{  
    int lchildHeight,rchildHeight;  
    if(tree==NULL)  
        return 0;  
    lchildHeight=BTreeHeight(tree->lchild);  
    rchildHeight=BTreeHeight(tree->rchild);  
    return (lchildHeight>rchildHeight)?(1+lchildHeight):(1+rchildHeight);  
}  




 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 
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
			
			
			yin();
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
    setbkcolor(0);
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




 
 
 
 
 
 
 
 
 
 
 
 
 
 