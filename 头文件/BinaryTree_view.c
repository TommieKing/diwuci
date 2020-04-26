#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"C:\Users\king\Desktop\�½��ļ��� (2)\BinaryTree.h"
#include"C:\Users\king\Desktop\�½��ļ��� (2)\BinaryTree_view.h"
int view()
{
    int ch;
    printf("*************************\n");
    printf("��ѡ����Ҫ�Ĺ��ܣ�\n");
    printf("1.���������\n");
    printf("2.���ٶ�����\n");
    printf("3.ǰ�����������\n");
    printf("4.�������������\n");
    printf("5.�������������\n");
    printf("6.�������������\n");
    printf("7.�ǵݹ�ǰ�����������\n");
    printf("8.�ǵݹ��������������\n");
    printf("9.�ǵݹ�������������\n");
    printf("10.�˳�\n");
    printf("*************************\n");
    while(scanf("%d",&ch) != 1 || ch < 1 || ch >10)
    {
        printf("�����������������\n");
        fflush(stdin);
    }
    fflush(stdin);
    return ch;
}

void CreateBiTree_view(BiTree *T)
{
    if(*T != NULL)
    {
        printf("���Ѿ�����");
        system("pause");
        system("cls");
        return;
    }
    char str[15] = {'\0'};
    printf("���������ֵ��");
    scanf("%s",str);
    int i =0;
    while(str[i] != '\0')
        i++;
    int len = i;
    CreateBiTree(&(*T),str,len);
    fflush(stdin);
    printf("�����ɹ���");
    system("pause");
    system("cls");
}

void DestroyBiTree_view(BiTree *T)
{
    if(DestroyBiTree(&(*T)) == SUCEESS)
    {
        printf("�ݻٳɹ���");
        Sleep(1000);
        system("cls");
        return;
    }
    printf("����Ϊ����");
    Sleep(1000);
    system("cls");
    return;
}

void PreOrderTraverse_view(BiTree T)
{
    if(PreOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ���");
    }
    system("pause");
    system("cls");
    return;
}
void InOrderTraverse_view(BiTree T)
{
    if(InOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}
void PostOrderTraverse_view(BiTree T)
{
    if(PostOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}
void LevelOrderTraverse_view(BiTree T)
{
    if(LevelOrderTraverse(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}

void PreOrderStack_view(BiTree T)
{
    if(PreOrderStack(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}

void InOrderStack_view(BiTree T)
{
    if(InOrderStack(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}

void PostOrderStack_view(BiTree T)
{
    if(PostOrderStack(T,visit) == SUCEESS)
    {
        printf("\n�����ɹ���");
    }
    else
    {
        printf("�����ǿ������޷�����");
    }
    system("pause");
    system("cls");
    return;
}
