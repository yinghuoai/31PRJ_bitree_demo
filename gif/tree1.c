#include <stdio.h>  
#include<stdlib.h>  

  
typedef struct tree_node  
{  
    char data;  
    struct tree_node *lchild,*rchild;  
	int depth,x,y,color;
	
	
	
}BiTNode;
#define Tree_NodeLen sizeof(BiTNode)  

BiTNode *tree;

BiTNode *CreateBiTree(BiTNode *tree);  
  
void visit(BiTNode *tree);  
void PreOrderTraverse(BiTNode *tree);  
void InOrderTraverse(BiTNode *tree);  
void PostOrderTraverse(BiTNode *tree);  
  
int main(void)  
{  
    printf("\n please input tree node:\n ");  
    tree = CreateBiTree(tree);  
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
    return 0;  
}  
BiTNode *CreateBiTree(BiTNode *tree)  
{  
    char ch ;  
    ch = getchar();  
  
    if(ch == '.')  
    {  
        tree = NULL;  
    }  
    else  
    {  
        tree = (BiTNode *)malloc(Tree_NodeLen);  
        tree->data = ch;  
        tree->lchild = CreateBiTree(tree->lchild);  
        tree->rchild = CreateBiTree(tree->rchild);  
    }  
    return(tree);  
}  

void visit(BiTNode *tree)  
{  
    printf(" ");  
    putchar(tree->data);  
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
        visit(tree);  
        PreOrderTraverse(tree->lchild);  
        PreOrderTraverse(tree->rchild);  
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
        visit(tree);  
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