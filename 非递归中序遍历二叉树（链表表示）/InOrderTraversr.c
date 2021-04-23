/*在上面树的基础上，中序遍历二叉树的非递归算法，栈写的非常简单*/
#include<stdio.h>
#include<stdlib.h>
#define max 100

//二叉树的二叉链表存储表示
typedef struct BTNode{
	char data;                      //结点数据域
	struct BTNode *lchild, *rchild; //左右孩子指针
}BTNode,*BTree;

// 中序遍历二叉树的非递归算法
void InOrderTraversr(BTree root)
{
    BTNode *p = root;
    BTree S[max];     // 一个非常简单，容量为max的栈
    int top = 0;      // 栈顶的下标
    while(p || top)
    {
        if(p)
        {
            S[top++] = p;  // 根节点进去栈
            p = p->lchild; // 遍历左子树
        }
        else
        {
            p = S[--top];  // 出栈，赋值给p
            printf("%c", p->data);
            p = p->rchild; // 遍历右子树
        }
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
	for( i = 2 * len; i >= 0 ; i--) // 找到子节点，下标len到2*len为NULL
    {
        if(i < len)
        {
            T[i]->lchild = T[2 * i + 1];
            T[i]->rchild = T[2 * i + 2];
        }
        else
            T[i] = NULL;
    }
	printf("\n中序遍历二叉树的非递归算法：\n");
	InOrderTraversr(T[0]);
}
