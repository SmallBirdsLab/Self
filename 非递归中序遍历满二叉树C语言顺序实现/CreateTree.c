/*顺序存储一个满二叉树，并按照三种方式遍历树*/
#include<stdio.h>
#include<stdlib.h>
#define max 100

//二叉树的二叉链表存储表示
typedef struct BTNode{
	char data;                      //结点数据域
	struct BTNode *lchild, *rchild; //左右孩子指针
}BTNode,*BTree;

void preorder(BTree root) // 先序遍历
{
	if(root!=NULL)
    {
        printf("%c",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
	}
}

void midorder(BTree root) // 中序遍历
{
	if(root!=NULL)
    {
        midorder(root->lchild);
        printf("%c",root->data);
        midorder(root->rchild);
	}
}

void rearorder(BTree root) // 后序遍历
{
	if(root!=NULL)
    {
        rearorder(root->lchild);
        rearorder(root->rchild);
        printf("%c",root->data);
	}
}

void main(){
	BTree T[max];
	char ch;
	int i,len; // len表示输入字符的个数
	printf("please input string:\n");

	for( len = 0; scanf("%c", &ch) && ch != '\n'; len++ ) // 先把下标0到len-1的节点存入字符
	{
		T[len] = (BTNode*)malloc(sizeof(BTNode));
		T[len]->data = ch;
	}
	for( i = 2 * len; i >= 0 ; i--) 
    {
        if(i < len) // 找到下标0到len-1的节点的子节点，
            T[i]->lchild = T[2 * i + 1];
            T[i]->rchild = T[2 * i + 2];
        else        // 因为是满二叉树的顺序存储，所以下标len到2*len全为NULL
            T[i] = NULL;
    }

	printf("先序遍历： ");
	preorder(T[0]);

	printf("\n中序遍历： ");
	midorder(T[0]);

    printf("\n后序遍历： ");
	rearorder(T[0]);
}
