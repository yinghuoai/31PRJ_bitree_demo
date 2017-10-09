#define ESC	0x1b			/* Define the escape key	*/
#define TRUE	1			/* Define some handy constants	*/
#define FALSE	0			/* Define some handy constants	*/
#define PI	3.14159 		/* Define a value for PI	*/
#define ON	1			/* Define some handy constants	*/
#define OFF	0			/* Define some handy constants	*/
#define SOUND 4000
#define DELAY 10


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
void PreOrderTraverse2(BiTNode *tree)  ;
void displayLeaf(BiTNode* tree); 
BiTNode*   search(BiTNode* tree,char ch);
void clear(BiTNode* tree);
void InOrderTraverse2(BiTNode *tree);
void show(BiTNode *tree);












