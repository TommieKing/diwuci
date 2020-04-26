#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct  BiTNode
{
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
}BiTNode,*BiTree;   // 二叉链表

typedef enum Status
{
	SUCEESS,
	EROR
}Status;


Status InitBiTree(BiTree *T);//操作结果：构造空二叉树T
Status DestroyBiTree(BiTree *T);
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status CreateBiTree(BiTree *T,char *str,int len);
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T
Status PreOrderTraverse(BiTree T, void (*visit)(TElemType e));
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status InOrderTraverse(BiTree T, void (*visit)(TElemType e));//中序遍历
Status PostOrderTraverse(BiTree T, void (*visit)(TElemType e));//后序遍历
Status LevelOrderTraverse(BiTree T, void (*visit)(TElemType e));//层序遍历
Status PreOrderStack(BiTree T, void (*visit)(TElemType e));//前序遍历非递归
Status InOrderStack(BiTree T, void (*visit)(TElemType e));//中序遍历非递归
Status PostOrderStack(BiTree T, void (*visit)(TElemType e));//后序遍历非递归

void visit(TElemType e);//构造出的二叉树求值


#endif // BINARYTREE_H_INCLUDED
