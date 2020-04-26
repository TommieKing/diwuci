#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode
{
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
}BiTNode,*BiTree;   // ��������

typedef enum Status
{
	SUCEESS,
	EROR
}Status;


Status InitBiTree(BiTree *T);//�������������ն�����T
Status DestroyBiTree(BiTree *T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree *T,char *str,int len);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T
Status PreOrderTraverse(BiTree T, void (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, void (*visit)(TElemType e));//�������
Status PostOrderTraverse(BiTree T, void (*visit)(TElemType e));//�������
Status LevelOrderTraverse(BiTree T, void (*visit)(TElemType e));//�������
Status PreOrderStack(BiTree T, void (*visit)(TElemType e));//ǰ������ǵݹ�
Status InOrderStack(BiTree T, void (*visit)(TElemType e));//��������ǵݹ�
Status PostOrderStack(BiTree T, void (*visit)(TElemType e));//��������ǵݹ�

void visit(TElemType e);//������Ķ�������ֵ


#endif // BINARYTREE_H_INCLUDED
