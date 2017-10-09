
#ifdef __TINY__
#error BGIDEMO will not run in the tiny model.
#endif

#include <dos.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <graphics.h>

#include "02demo3.h"
#include "tree5.h"



 

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


char* msg1 = "SUCCESS: preorder";
char* msg2 = "SUCCESS: inorder";
char* msg3 = "SUCCESS: postorder";
char* msg4 = "SUCCESS: leaf ";
char* msg5 = "SUCCESS: find ";
char* msg6 = "SUCCESS: delete ";
char* msg7 = "SUCCESS: insert ";
char* msg8 = "SUCCESS: exit";


  
  
int main(void)  
{  

	int color=1,lcolor =15;
	
	qiuqiu();
	
	
	Initialize(); 		/* Set system into Graphics mode	*/

	
	
  if( GraphDriver==EGA || GraphDriver==EGALO || GraphDriver==VGA )
    /*PaletteDemo();  */
	/*TextDemo();   */
	


    printf("\n please input tree node:\n ");  
    tree = CreateBiTree(tree);  
	

	
	MainWindow( "bitree" );
	StatusLine( "ESC Aborts - Press a Key to stop" );


		
	lineshow(tree,lcolor);		
	shixinDemo(tree,color);
	yin();

	Pause();
	
	
	lineshow(tree,lcolor);		
	shixinDemo(tree,color);
	
	PreOrderTraverse(tree);
	
		
	yin();

	Pause2(msg1);
	
	lineshow(tree,lcolor);		
	shixinDemo(tree,color);
	
	InOrderTraverse(tree);
	
		
	yin();

	Pause2(msg2);	
	
	
	
	
	
	
	
	
	
	lineshow(tree,lcolor);		
	shixinDemo(tree,color);

	
	displayLeaf(tree);
	
	
	yin();	
	Pause2(msg4);
	
	
	
	CircleDemo();   
	closegraph(); 
	
	
	

	
		/* Return the system to text mode	*/
  return(0);
  
  
}  






void Pause()
{
  static char msg[] = "Esc aborts or press a key...";
  int c;

  StatusLine( msg );			/* Put msg at bottom of screen	*/

  c = getch();				/* Read a character from kbd	*/

  if( ESC == c ){			/* Does user wish to leave?	*/
    closegraph();			/* Change to text mode		*/
    exit( 1 );				/* Return to OS 		*/
  }

  if( 0 == c ){ 			/* Did use hit a non-ASCII key? */
    c = getch();			/* Read scan code for keyboard	*/
  }

  cleardevice();			/* Clear the screen		*/

}


void Pause2(char* msg)
{
  
  
  int c;

  
  
  StatusLine( msg );			/* Put msg at bottom of screen	*/

  c = getch();				/* Read a character from kbd	*/

  if( ESC == c ){			/* Does user wish to leave?	*/
    closegraph();			/* Change to text mode		*/
    exit( 1 );				/* Return to OS 		*/
  }

  if( 0 == c ){ 			/* Did use hit a non-ASCII key? */
    c = getch();			/* Read scan code for keyboard	*/
  }

  cleardevice();			/* Clear the screen		*/

}




void ColorDemo(void)
{
  struct viewporttype vp;
  int color, height, width;
  int x, y, i, j;
  char cnum[5];

  MainWindow( "Color Demonstration" );  /* Show demonstration name      */

  color = 1;
  getviewsettings( &vp );		/* Get the current window size	*/
  width  = 2 * ( (vp.right+1) / 16 );	   /* Get box dimensions	   */
  height = 2 * ( (vp.bottom-10) / 10 );

  x = width / 2;
  y = height / 2;	/* Leave 1/2 box border 	*/

  for( j=0 ; j<3 ; ++j ){		/* Row loop			*/

    for( i=0 ; i<5 ; ++i ){		/* Column loop			*/

      setfillstyle(SOLID_FILL, color);	/* Set to solid fill in color	*/
      setcolor( color );		/* Set the same border color	*/

      bar( x, y, x+width, y+height );	/* Draw the rectangle		*/
      rectangle( x, y, x+width, y+height );  /* outline the rectangle	*/

      if( color == BLACK ){		/* If box was black...		*/
	setcolor( WHITE );		/* Set drawing color to white	*/
	rectangle( x, y, x+width, y+height );  /* Outline black in white*/
      }

      itoa( color, cnum, 10 );		/* Convert # to ASCII		*/
      outtextxy( x+(width/2), y+height+4, cnum );  /* Show color #	*/

      color = ++color % MaxColors;	/* Advance to the next color	*/
      x += (width / 2) * 3;		/* move the column base 	*/
    }				/* End of Column loop		*/

    y += (height / 2) * 3;		/* move the row base		*/
    x = width / 2;			/* reset column base		*/
  }					/* End of Row loop		*/

  Pause();				/* Pause for user's response    */

}



void MainWindow( char *header )
{
  int height;

  cleardevice();			/* Clear graphics screen	*/
  setcolor( MaxColors - 1 );		/* Set current color to white	*/
  setviewport( 0, 0, MaxX, MaxY, 1 );	/* Open port to full screen	*/

  height = textheight( "H" );           /* Get basic text height        */

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

  setviewport( 0, 0, MaxX, MaxY, 1 );	/* Open port to full screen	*/
  setcolor( random( MaxColors - 1 ));		/* Set current color to white	*/

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
  setfillstyle( EMPTY_FILL, 0 );

  height = textheight( "H" );           /* Detemine current height      */
  bar( 0, MaxY-8*(height+4), MaxX, MaxY );
  rectangle( 0, MaxY-8*(height+4), MaxX, MaxY );
  outtextxy( MaxX/2, MaxY-8*(height+2), msg );
  setviewport( 1, height+5, MaxX-1, MaxY-8*(height+5), 1 );

}


void DrawBorder(void)
{
  struct viewporttype vp;

  setcolor( MaxColors - 1 );		/* Set current color to white	*/

  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

  getviewsettings( &vp );
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}

void changetextstyle(int font, int direction, int charsize)
{
  int ErrorCode;

  graphresult();			/* clear error code		*/
  settextstyle(font, direction, charsize);
  ErrorCode = graphresult();		/* check result 		*/
  if( ErrorCode != grOk ){		/* if error occured		*/
    closegraph();
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}

int gprintf( int *xloc, int *yloc, char *fmt, ... )
{
  va_list  argptr;			/* Argument list pointer	*/
  char str[140];			/* Buffer to build sting into	*/
  int cnt;				/* Result of SPRINTF for return */

  va_start( argptr, format );		/* Initialize va_ functions	*/

  cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
  outtextxy( *xloc, *yloc, str );	/* Send string in graphics mode */
  *yloc += textheight( "H" ) + 2;       /* Advance to next line         */

  va_end( argptr );			/* Close va_ functions		*/

  return( cnt );			/* Return the conversion count	*/

}



void Initialize(void)
{
  int xasp, yasp;			/* Used to read the aspect ratio*/

  GraphDriver = DETECT; 		/* Request auto-detection	*/
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();		/* Read result of initialization*/
  if( ErrorCode != grOk ){		/* Error occured during init	*/
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }

  getpalette( &palette );		/* Read the palette from board	*/
  MaxColors = getmaxcolor() + 1;	/* Read maximum number of colors*/

  MaxX = getmaxx();
  MaxY = getmaxy();			/* Read size of screen		*/

  getaspectratio( &xasp, &yasp );	/* read the hardware aspect	*/
  AspectRatio = (double)xasp / (double)yasp; /* Get correction factor	*/

}

void ReportStatus(void)
{
  struct viewporttype	  viewinfo;	/* Params for inquiry procedures*/
  struct linesettingstype lineinfo;
  struct fillsettingstype fillinfo;
  struct textsettingstype textinfo;
  struct palettetype	  palette;

  char *driver, *mode;			/* Strings for driver and mode	*/
  int x, y;

  getviewsettings( &viewinfo );
  getlinesettings( &lineinfo );
  getfillsettings( &fillinfo );
  gettextsettings( &textinfo );
  getpalette( &palette );

  x = 10;
  y = 4;

  MainWindow( "Bitree graph: " );
  settextjustify( LEFT_TEXT, TOP_TEXT );

  driver = getdrivername();
  mode = getmodename(GraphMode);	/* get current setting		*/

  gprintf( &x, &y, "Graphics device    : %-20s (%d)", driver, GraphDriver );
  gprintf( &x, &y, "Graphics mode      : %-20s (%d)", mode, GraphMode );
  gprintf( &x, &y, "Screen resolution  : ( 0, 0, %d, %d )", getmaxx(), getmaxy() );

  gprintf( &x, &y, "Current view port  : ( %d, %d, %d, %d )",
  viewinfo.left, viewinfo.top, viewinfo.right, viewinfo.bottom );
  gprintf( &x, &y, "Clipping           : %s", viewinfo.clip ? "ON" : "OFF" );

  gprintf( &x, &y, "Current position   : ( %d, %d )", getx(), gety() );
  gprintf( &x, &y, "Colors available   : %d", MaxColors );
  gprintf( &x, &y, "Current color      : %d", getcolor() );

  gprintf( &x, &y, "Line style         : %s", LineStyles[ lineinfo.linestyle ] );
  gprintf( &x, &y, "Line thickness     : %d", lineinfo.thickness );

  gprintf( &x, &y, "Current fill style : %s", FillStyles[ fillinfo.pattern ] );
  gprintf( &x, &y, "Current fill color : %d", fillinfo.color );

  gprintf( &x, &y, "Current font       : %s", Fonts[ textinfo.font ] );
  gprintf( &x, &y, "Text direction     : %s", TextDirect[ textinfo.direction ] );
  gprintf( &x, &y, "Character size     : %d", textinfo.charsize );
  gprintf( &x, &y, "Horizontal justify : %s", HorizJust[ textinfo.horiz ] );
  gprintf( &x, &y, "Vertical justify   : %s", VertJust[ textinfo.vert ] );

  Pause();				/* Pause for user to read screen*/

}



void PaletteDemo(void)
{
  int i, j, x, y, color;
  struct viewporttype vp;
  int height, width;

  MainWindow( "Palette Demonstration" );
  StatusLine( "Press any key to continue, ESC to Abort" );

  getviewsettings( &vp );
  width  = (vp.right - vp.left) / 15;	/* get width of the box 	*/
  height = (vp.bottom - vp.top) / 10;	/* Get the height of the box	*/

  x = y = 0;				/* Start in upper corner	*/
  color = 1;				/* Begin at 1st color		*/

/* For 15 columns of boxes	*/
      setfillstyle( SOLID_FILL, color++ );	/* Set the color of box */
      bar( x, y, x+width, y+height );		/* Draw the box 	*/
      x += width + 1;				/* Advance to next col	*/
      color = 1 + (color % (MaxColors - 2));	/* Set new color	*/
  
  
  while( !kbhit() ){			/* Until user enters a key...	*/
    setpalette( 1+random(MaxColors - 2), random( 65 ) );
  }

  setallpalette( &palette );

  Pause();				/* Wait for user's response     */

}

void TextDemo(void)
{
  int charsize[] = {
    1, 3, 7, 3, 4   };
  int font, size;
  int h, x, y, i;
  struct viewporttype vp;
  char buffer[80];

  for( font=0 ; font<5 ; ++font ){	/* For each of the four fonts	*/

    sprintf( buffer, "%s Demonstration", Fonts[font] );
    MainWindow( buffer );
    getviewsettings( &vp );

    changetextstyle( font, VERT_DIR, charsize[font] );
    settextjustify( CENTER_TEXT, BOTTOM_TEXT );
    outtextxy( 2*textwidth("M"), vp.bottom - 2*textheight("M"), "Vertical" );

    changetextstyle( font, HORIZ_DIR, charsize[font] );
    settextjustify( LEFT_TEXT, TOP_TEXT );
    outtextxy( 2*textwidth("M"), 2, "Horizontal" );

    settextjustify( CENTER_TEXT, CENTER_TEXT );
    x = (vp.right - vp.left) / 2;
    y = textheight( "H" );

    for( i=1 ; i<5 ; ++i ){		/* For each of the sizes */
      size = (font == SMALL_FONT) ? i+3 : i;
      changetextstyle( font, HORIZ_DIR, size );
      h = textheight( "H" );
      y += h;
      sprintf( buffer, "Size %d", size );
      outtextxy( x, y, buffer );

    }

    if( font != DEFAULT_FONT ){ 	/* Show user declared font size */
      y += h / 2;			/* Move down the screen 	*/
      settextjustify( CENTER_TEXT, TOP_TEXT );
      setusercharsize( 5, 6, 3, 2 );
      changetextstyle( font, HORIZ_DIR, USER_CHAR_SIZE );
      outtextxy( (vp.right-vp.left)/2, y, "User Defined Size" );
    }

    Pause();				/* Pause to let user look	*/

  }					/* End of FONT loop		*/

}

void CircleDemo(void)
{
  int mradius;				/* Maximum radius allowed	*/

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
	gotoxy(10,400);
    printf(" ");  
    putchar(tree->data[0]);  
    printf("\t");  
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
        visit(tree);  
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
  

void clear(BiTNode* tree)  
{  
    BiTNode* pl;
	BiTNode* pr;  
    if(tree==NULL)  
        return;  
    pl= tree->lchild;  
    pr= tree->rchild;  
    tree->lchild=NULL;  
    tree->rchild=NULL;  
    free(tree);  
    tree=NULL;  
    clear(pl);  
    clear(pr);  
}  





