#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree.h"
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree_view.h"
int view()
{
    int ch;
    printf("*************************\n");
    printf("请选择需要的功能：\n");
    printf("1.构造二叉树\n");
    printf("2.销毁二叉树\n");
    printf("3.前序遍历二叉树\n");
    printf("4.中序遍历二叉树\n");
    printf("5.后序遍历二叉树\n");
    printf("6.层序遍历二叉树\n");
    printf("7.非递归前序遍历二叉树\n");
    printf("8.非递归中序遍历二叉树\n");
    printf("9.非递归后序遍历二叉树\n");
    printf("10.退出\n");
    printf("*************************\n");
    while(scanf("%d",&ch) != 1 || ch < 1 || ch >10)
    {
        printf("输入错误，请重新输入\n");
        fflush(stdin);
    }
    fflush(stdin);
    return ch;
}

void CreateBiTree_view(BiTree *T)
{
    if(*T != NULL)
    {
        printf("树已经创建");
        system("pause");
        system("cls");
        return;
    }
    char str[15] = {'\0'};
    printf("请输入结点的值：");
    scanf("%s",str);
    int i =0;
    while(str[i] != '\0')
        i++;
    int len = i;
    CreateBiTree(&(*T),str,len);
    fflush(stdin);
    printf("创建成功！");
    system("pause");
    system("cls");
}

void DestroyBiTree_view(BiTree *T)
{
    if(DestroyBiTree(&(*T)) == SUCEESS)
    {
        printf("摧毁成功！");
        Sleep(1000);
        system("cls");
        return;
    }
    printf("该树为空树");
    Sleep(1000);
    system("cls");
    return;
}

void PreOrderTraverse_view(BiTree T)
{
    if(PreOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树");
    }
    system("pause");
    system("cls");
    return;
}
void InOrderTraverse_view(BiTree T)
{
    if(InOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}
void PostOrderTraverse_view(BiTree T)
{
    if(PostOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}
void LevelOrderTraverse_view(BiTree T)
{
    if(LevelOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}

void PreOrderStack_view(BiTree T)
{
    if(PreOrderStack(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}

void InOrderStack_view(BiTree T)
{
    if(InOrderStack(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}

void PostOrderStack_view(BiTree T)
{
    if(PostOrderStack(T,visit) == SUCEESS)
    {
        printf("\n遍历成功！");
    }
    else
    {
        printf("该树是空树，无法遍历");
    }
    system("pause");
    system("cls");
    return;
}
