  
  c = getch();				/* Read a character from kbd	*/

  if( 'c' == c ){	

	setcolor(15); 
	line(tree->x, tree->y,tree->x-100, tree->y+100);
  
 			/* Repeat until a key is hit	*/
    setcolor( 2);	/* Randomly select a color	*/
    setfillstyle( 1,2);	
	pieslice( tree->x, tree->y,0,360 ,mradius );
	setcolor(15); 
    settextstyle(0,0, 1); 
    outtextxy(tree->x, tree->y, "a"); 
	
	
	//////////////////////////////////////////////////
	
	
	 setcolor(4); 
	line(tree->x, tree->y,tree->x-100, tree->y+100);

  
  
  
  
  
  

  }
  
  
  
  
  
  
  
 /////////////////////////////////////////////////// 
  
 	  if(tree)  
    {  
        printf("\n preorder:\n ");  
        PreOrderTraverse(tree);  
        printf("\n");  
  
  
        printf("\n inorder:\n ");  
        InOrderTraverse(tree);  
        printf("\n");  
  
        printf("\n postorder\n ");  
        PostOrderTraverse(tree);  
        printf("\n");  
    }  
    printf("\n");  
	
	Pause();	 
  
 ///////////////////////////////////////////////////////




        if(tree->lchild!=NULL && tree->rchild!=NULL  ) 
		{
			
			setcolor(4);
			line(tree->x, tree->y, tree->lchild->x, tree->lchild->y);

			setcolor(4);
			line(tree->x, tree->y, tree->rchild->x, tree->rchild->y);
		
			
	
	
		}else if(tree->lchild!=NULL && tree->rchild==NULL  ) 
		{
			setcolor(4);
			line(tree->x, tree->y, tree->lchild->x, tree->lchild->y);
		
			
			
			

		}else if(tree->lchild==NULL && tree->rchild!=NULL  ) 
		{

			setcolor(4);
			line(tree->x, tree->y, tree->rchild->x, tree->rchild->y);

		}		
			
			 
  
  
  
  
  
  
  
  
  
  
  