#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"C:\Users\king\Desktop\�½��ļ��� (2)\BinaryTree.h"
#include"C:\Users\king\Desktop\�½��ļ��� (2)\BinaryTree_view.h"
Status CreateBiTree(BiTree *T,char str[],int len)
{

    (*T) = (BiTree)malloc(sizeof(BiTNode)*len);//�����ռ�
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
            (*T)[i].lchild = &(*T)[2*i+1];//��ֵ������
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
    temp[in++] = T;//����������ĸ��ڵ�
    while(in > out)
    {//out�����ÿ�������ֵ
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
    //��ʼ��ջ������·��
    BiTree stack[20];//�洢�߹��ĵ�ַ
    int top = -1;
    BiTree pmove = T;//�ƶ�ָ��
    while(top != -1 || pmove)
    {
        while(pmove)
        {
            visit(pmove->data);
            stack[++top] = pmove;//����·��
            pmove = pmove->lchild;
        }
        if(top != -1)
        {
            pmove = stack[top];//��ȡջ��Ԫ��
            top--;//��ջ
            pmove = pmove->rchild;
        }
    }
    return SUCEESS;
}

Status InOrderStack(BiTree T, void (*visit)(TElemType e))
{
    if(T == NULL)
        return EROR;
    //��ʼ��ջ������·��
    BiTree stack[20];//�洢�߹��ĵ�ַ
    int top = -1;
    BiTree pmove = T;//�ƶ�ָ��
    while(top != -1 || pmove)
    {
            //������ߣ�ͬʱ����·������ջ��
            while(pmove)
            {
                stack[++top] = pmove;
                pmove = pmove->lchild;
            }
            //��·����,��ջǰ��Ϊջ��Ϊ��
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
    //��ʼ��ջ������·��
    BiTree stack[20];//�洢�߹��ĵ�ַ
    int top = -1;
    BiTree pmove = T;//�ƶ�ָ��
    BiTree plast = NULL;//���ʱ��
    while(pmove)
    {
        stack[++top] = pmove;
        pmove = pmove->lchild;
    }
    while(top != -1)
    {
        pmove = stack[top--];
        //�ұ�Ϊ�ջ����ұ߱����ʣ���ʱ���ڵ�ſ���
        if(pmove->rchild == NULL || pmove->rchild == plast)
        {
            visit(pmove->data);
            plast = pmove;//�ı��ǵ�λ��
        }
        else
        {
            stack[++top] = pmove;//��ջ
            pmove = pmove->rchild;
            while(pmove)
            {
                stack[++top] = pmove;
                pmove = pmove->lchild;//����������
            }
        }
    }
    return SUCEESS;

}
