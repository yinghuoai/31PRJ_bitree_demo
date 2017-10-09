
#define NULL 0

typedef char EleType;

typedef struct node{
	
	struct node* next;
	EleType data;
	
	
}ChainNode;

typedef struct{
	
	ChainNode* head;
	ChainNode* tail;
	
}List;


List* CreateList(void);
void DestroyList(List* lp);
void ClearList(List* lp);
int ListAppend(List* lp,EleType data);
int ListDelete(List* lp,int n);
int ListInsert(List* lp,int n,EleType data);
int GetElement(List* lp,int n,EleType* dp);
ChainNode* GetAddr(List* lp,int n);
ChainNode* NewChainNode(EleType data);
int TraverseList(List* lp,int (*f)(EleType*));





List* CreateList(void)
{
	List* lp;
	EleType* data = 0;
	
	lp = (List*)malloc(sizeof(List));
	if(!lp)
	{
		return NULL;
		
		
	}
	
	
	lp->head = lp->tail = NewChainNode(*data);
	
	if(!lp->head)
	{
		free(lp);
		return NULL;
		
	}
	
	
	return 0;
	
	

	
}


void DestroyList(List* lp)
{
	ClearList(lp);
	free(lp->head);
	free(lp->tail);
	free(lp);
	
	
	
	
}




void ClearList(List* lp)
{
	
	while(ListDelete(lp,1));
	
	
}



int ListAppend(List* lp,EleType data)
{
	ChainNode* p;
	
	p= NewChainNode(data);
	
	if(!p)
	{
		
		return NULL;
	}
	
	lp->tail->next = p;
	lp->tail = p;
	
	return 1;
	
	
	
	
	
}



int ListDelete(List* lp,int n)
{
	
	ChainNode* p;
	p= GetAddr(lp,n);
	if(!p)
	{
		return 0;
		
	}
	
	
	
	

	
	
	
	
	
	
	
	
	
}



int ListInsert(List* lp,int n,EleType data);
int GetElement(List* lp,int n,EleType* dp);
ChainNode* GetAddr(List* lp,int n)
{
	int i=0;
	
	if( n<0  )
	{
		return 0;
	}
	
	
	
	
	while(i<n&&!p->next )
	{
		p=p->next;
		i++;
	}		
	
	
	
	
	
	
}



ChainNode* NewChainNode(EleType data);
int TraverseList(List* lp,int (*f)(EleType*));

















