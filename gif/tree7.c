
typedef struct 
{
	
	const char* text;
	char key;
	void* func;
	int pnum;
	
}list;

typedef struct mg
{
	list* item;
	
	void (*doing)(struct mg*);
	
	int fnum;


	
}manage;

extern  int a;

extern list flist[];
extern manage fmanage;
extern char str1[3][20];


void menu(manage* cpfmanage);

extern void choose(manage* cpfmanage);

void init();

extern void change();

extern int add2(int,int);
extern int add3(int,int,int);
extern int mul2(int,int);
extern int mul3(int,int,int);
extern int value(int);
extern void f1();
extern void putstr(char*);














