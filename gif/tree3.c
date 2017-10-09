#include<stdio.h>  
#include<stdlib.h>  
//二叉树的节点定义  
typedef struct TreeNode  
{  
    char ch;                  //数据域  
    struct TreeNode *lchild;  //左孩子  
    struct TreeNode *rchild;  //右孩子  
}BTNode,*PBTNode;  
  
//先序构造二叉树  
void createBTree(PBTNode *root)  
{  
    char ch;  
    ch=getchar();  
    if(ch=='#')  
        *root=NULL;  
    else{  
        *root=(PBTNode)malloc(sizeof(BTNode));  
        (*root)->ch=ch;  
        (*root)->lchild=NULL;  
        (*root)->rchild=NULL;  
        createBTree(&(*root)->lchild);  
        createBTree(&(*root)->rchild);  
    }  
}  
  
//先序遍历二叉树  
void preOrder(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    printf("%-3c",root->ch);  
    preOrder(root->lchild);  
    preOrder(root->rchild);  
}  
  
//中序遍历二叉树  
void inOrder(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    preOrder(root->lchild);  
    printf("%-3c",root->ch);  
    preOrder(root->rchild);  
}  
  
//后序遍历二叉树  
void postOrder(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    preOrder(root->lchild);  
    preOrder(root->rchild);  
    printf("%-3c",root->ch);  
}  
  
//输出叶子结点  
void displyLeaf(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    if(root->lchild==NULL&&root->rchild==NULL)  
        printf("%-3c",root->ch);  
    else{  
        displyLeaf(root->lchild);  
        displyLeaf(root->rchild);  
    }  
}  
  
//左结点插入  
void inseartLeftNode(PBTNode root,char ch)  
{  
    PBTNode p,newNode;  
    if(root==NULL)  
        return;  
    p=root->lchild;  
    newNode=(PBTNode)malloc(sizeof(BTNode));  
    newNode->ch=ch;  
    newNode->rchild=NULL;  
    newNode->lchild=p;  
    root->lchild=newNode;  
}  
  
//右结点插入  
void inseartRightNode(PBTNode root,char ch)  
{  
    PBTNode p,newNode;  
    if(root==NULL)  
        return;  
    p=root->rchild;  
    newNode=(PBTNode)malloc(sizeof(BTNode));  
    newNode->ch=ch;  
    newNode->lchild=NULL;  
    newNode->rchild=p;  
    root->rchild=newNode;  
}  
  
//销毁一颗二叉树  
void clear(PBTNode* root)  
{  
    PBTNode pl,pr;  
    if(*root==NULL)  
        return;  
    pl=(*root)->lchild;  
    pr=(*root)->rchild;  
    (*root)->lchild=NULL;  
    (*root)->rchild=NULL;  
    free((*root));  
    *root=NULL;  
    clear(&pl);  
    clear(&pr);  
}  
  
//删除左子树  
void deleteLeftTree(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    clear(&root->lchild);  
    root->lchild=NULL;  
}  
  
//删除右子树  
void deleteRightTree(PBTNode root)  
{  
    if(root==NULL)  
        return;  
    clear(&root->rchild);  
    root->rchild=NULL;  
}  
  
//查找结点  
PBTNode   search(PBTNode root,char ch)  
{  
    PBTNode p;  
    if(root==NULL)  
        return NULL;  
    if(root->ch==ch)  
        return root;  
    else{  
        if((p=search(root->lchild,ch))!=NULL)  
            return p;  
        else  
            return  search(root->rchild,ch);    
    }  
}  
  
//求二叉树的高度  
int BTreeHeight(PBTNode root)  
{  
    int lchildHeight,rchildHeight;  
    if(root==NULL)  
        return 0;  
    lchildHeight=BTreeHeight(root->lchild);  
    rchildHeight=BTreeHeight(root->rchild);  
    return (lchildHeight>rchildHeight)?(1+lchildHeight):(1+rchildHeight);  
}  
  
//求叶子结点的个数  
int countLeaf(PBTNode root)  
{  
    if(root==NULL)  
        return 0;    
    if(root->lchild==NULL&&root->rchild==NULL)  
        return 1;  
    else{  
        return countLeaf(root->lchild)+countLeaf(root->rchild);  
    }  
}  
  
//求所有结点的个数  
int countAll(PBTNode root)  
{  
    if(root==NULL)  
        return 0;  
    return countAll(root->lchild)+countAll(root->rchild)+1;  
}  
  
//复制二叉树  
PBTNode copyBTree(PBTNode root)  
{  
    PBTNode p,lchild,rchild;  
    if(root==NULL)  
        return NULL;  
    lchild=copyBTree(root->lchild);  
    rchild=copyBTree(root->rchild);  
    p=(PBTNode)malloc(sizeof(BTNode));  
    p->ch=root->ch;  
    p->lchild=lchild;  
    p->rchild=rchild;  
    return p;  
}