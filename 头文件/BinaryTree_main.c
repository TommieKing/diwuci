#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree.h"
#include"C:\Users\king\Desktop\新建文件夹 (2)\BinaryTree_view.h"
int main()
{

    BiTree T;
    InitBiTree(&T);
    printf("二叉树初始化成功！...");
    Sleep(1000);
    system("cls");
    int choice;
    while((choice = view()) != 10)
    {
        switch(choice)
        {
        case 1:CreateBiTree_view(&T);break;
        case 2:DestroyBiTree_view(&T);break;
        case 3:PreOrderTraverse_view(T);break;
        case 4:InOrderTraverse_view(T);break;
        case 5:PostOrderTraverse_view(T);break;
        case 6:LevelOrderTraverse_view(T);break;
        case 7:PreOrderStack_view(T);break;
        case 8:InOrderStack_view(T);break;
        case 9:PostOrderStack_view(T);break;
        
        }
    }
    
}
