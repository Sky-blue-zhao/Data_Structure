#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 // ���Ա���ռ�ó�ʼ������ 
#define LISTINCREMENT 10   // ���Ա�洢�ռ�÷������� 

#define TURE 1
#define FAlSE 0
#define OK 1
#define ERROR 0
#define INFEASEBLE -1
#define OVERFLOW -2
// Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���� 
typedef int ElemType; 
typedef int Status; 

typedef struct {
	ElemType *elem;        // �洢�ռ��ַ
	int length;            // ��ǰ����
	int listsize;          // ��ǰ�������Ĵ洢��������sizeof��ElemType��Ϊ��λ�� 
}SqList ; 

Status InitList_Sq(SqList *L)
{
    // ����һ���յ����Ա�L 
	(*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));    
    if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
    return OK;
} //InitList_Sq


Status ListInsert_Sq(SqList *L){
	// ��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	// i�ĺϷ�ֵΪ 1<i<ListLength_Sq(L)+1
	ElemType *q,*p,i,e;
	printf("\n\t\t\t\t\t\t����������λ��\t");
	scanf("%d",&i); 
	printf("\n\t\t\t\t\t\t����������Ԫ��\t");
	scanf("%d",&e); 
	if(i<1||i>(*L).length+1)
		return ERROR;   //iֵ���Ϸ�
	if((*L).length>=(*L).listsize){
		ElemType *newbase;
		newbase = (ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;      // ���Ӵ洢���� 
	}
	q = &((*L).elem[i-1]);
	for (p = &((*L).elem[(*L).length-1]);p>=q;--p)
		*(p+1) = *p; 
	*q =e;
	++(*L).length ;
	return OK;
} //ListInsert_Sq

Status ListDelete_Sq(SqList *L){
	// ��˳���L��ɾ����I��Ԫ�� �� ����e������ֵ
	// i�ĺϷ�ֵΪ 1<i<ListLength_Sq(L) 
	ElemType *p,*q,i,e;
	printf("\n\t\t\t\t\t\t������ɾ����λ��\t");
	scanf("%d",&i); 
	if((i<1)||(i>(*L).length))
		return ERROR;   // iֵ���Ϸ�
	p = &((*L).elem[i-1]);                     // pΪ��ɾ��Ԫ�ص�λ�� 
	e = *p;                                    // ��ɾ��Ԫ�ص�ֵ����e
	printf("\n\t\t\t\t\t\tɾ����Ԫ�أ�%d\n",e);
	q = (*L).elem + (*L).length - 1;           // ��βԪ�ص�λ��
	for(++p ; p <= q ; ++p)
		*(p-1) =* p ;       // ��ɾ��Ԫ��֮���Ԫ������
	--(*L).length;                             // ���� 1
	return OK; 	 
}   // ListDelete_Sq

Status DestoryList(SqList *L) {
	// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L 
	free((*L).elem);
	(*L).elem=NULL;
	(*L).length=0;
	(*L).listsize=0;
	return OK;
	}  

Status GetElem(SqList *L){
	//��ʼ������˳�����Ա��Ѵ��ڡ�����������������Ա��е� i ��Ԫ�ص�ֵ
	ElemType i,e,*p,n,*q;
	printf("\t\t\t\t\t1--������Ա�����Ԫ�أ�2--���ָ��λ��Ԫ��\n");
	scanf("%d",&n); 
	printf("\n\t\t\t\t\t\t���Ա�");
	if (n==1)
	{
		p = &((*L).elem[0]);
		q = (*L).elem + (*L).length - 1;
		for(p ; p <= q ; ++p)	
		{
			e = *p;                                    // ��ѯĿ��Ԫ�ص�ֵ����e
			printf("%d\t",e);// ��ʾ e ��ֵ
		} 
		return OK;	
	}
	else if (n==2) 
	{
		printf("\n\t\t\t\t\t\t������Ŀ��Ԫ�ص�λ��\n");
		scanf("%d",&i);
		if((i<1)||(i>(*L).length))
			return ERROR;   // iֵ���Ϸ�
		p = &((*L).elem[i-1]);                     // pΪĿ��Ԫ�ص�λ�� 
		e = *p;                                    // ��ѯĿ��Ԫ�ص�ֵ����e
		printf("\n\t\t\t\t\t\tĿ��Ԫ��ֵ��%d\n",e);// ��ʾ e ��ֵ
		return OK;
	}
	else
	{
		return ERROR;
	}
} 

void ListLength(SqList *L){
	if (!(*L).elem) exit(OVERFLOW);
	printf("\n\t\t\t\t\t\t���Ա��ȣ�%d\n",(*L).length);// ��ʾ L.length ���Ա��� 
}

void ClearList(SqList *L){
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;  // ��Ϊ�ձ� 
}




