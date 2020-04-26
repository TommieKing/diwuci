#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree.h"
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree_view.h"
Status CreateBiTree(BiTree *T,char str[],int len)
{

    (*T) = (BiTree)malloc(sizeof(BiTNode)*len);//连续空间
    int i;
    for(i=0;i<len;i++)
    {
        (*T)[i].data = str[i];
        (*T)[i].lchild = NULL;
        (*T)[i].rchild = NULL;
    }
    for(i=0;i<=len/2-1;i++)
    {
        if(2*i+1 <= len-1)
            (*T)[i].lchild = &(*T)[2*i+1];//把值赋给他
        if(2*i+2 <= len-1)
            (*T)[i].rchild = &(*T)[2*i+2];
    }
    return SUCEESS;
}

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return SUCEESS;
}

Status DestroyBiTree(BiTree *T)
{
    if(!*T)
        return EROR;
    else
    {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        (*T) = NULL;
        return SUCEESS;
    }
}

Status PreOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
    {
        return EROR;
    }
    visit(T->data);
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    return SUCEESS;
}

Status InOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    InOrderTraverse(T->lchild,visit);
    visit(T->data);
    InOrderTraverse(T->rchild,visit);
    return SUCEESS;
}

Status PostOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T->data);
    return SUCEESS;
}

Status LevelOrderTraverse(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    BiTree temp[100];
    int in = 0,out = 0;
    temp[in++] = T;//保存二叉树的根节点
    while(in > out)
    {//out假设存每个根结点值
        if(temp[out])
        {
            visit(temp[out]->data);
            temp[in++] = temp[out]->lchild;
            temp[in++] = temp[out]->rchild;
        }
        out++;
    }
    return SUCEESS;
}
void visit(TElemType e)
{
    printf("%c ",e);
}
Status PreOrderStack(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    //初始化栈，保存路径
    BiTree stack[20];//存储走过的地址
    int top = -1;
    BiTree pmove = T;//移动指针
    while(top != -1 || pmove)
    {
        while(pmove)
        {
            visit(pmove->data);
            stack[++top] = pmove;//保存路径
            pmove = pmove->lchild;
        }
        if(top != -1)
        {
            pmove = stack[top];//获取栈顶元素
            top--;//出栈
            pmove = pmove->rchild;
        }
    }
    return SUCEESS;
}

Status InOrderStack(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    //初始化栈，保存路径
    BiTree stack[20];//存储走过的地址
    int top = -1;
    BiTree pmove = T;//移动指针
    while(top != -1 || pmove)
    {
            //找最左边，同时保存路径（入栈）
            while(pmove)
            {
                stack[++top] = pmove;
                pmove = pmove->lchild;
            }
            //无路可走,出栈前提为栈不为空
            if(top != -1){
                pmove = stack[top--];
                visit(pmove->data);
                pmove = pmove->rchild;
            }
    }
    return SUCEESS;
}

Status PostOrderStack(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    //初始化栈，保存路径
    BiTree stack[20];//存储走过的地址
    int top = -1;
    BiTree pmove = T;//移动指针
    BiTree plast = NULL;//访问标记
    while(pmove)
    {
        stack[++top] = pmove;
        pmove = pmove->lchild;
    }
    while(top != -1)
    {
        pmove = stack[top--];
        //右边为空或者右边被访问，此时根节点才可以
        if(pmove->rchild == NULL || pmove->rchild == plast)
        {
            visit(pmove->data);
            plast = pmove;//改变标记的位置
        }
        else
        {
            stack[++top] = pmove;//入栈
            pmove = pmove->rchild;
            while(pmove)
            {
                stack[++top] = pmove;
                pmove = pmove->lchild;//和上面类似
            }
        }
    }
    return SUCEESS;

}
