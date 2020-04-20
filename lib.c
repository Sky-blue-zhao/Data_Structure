#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 // 线性表储存空间得初始分配量 
#define LISTINCREMENT 10   // 线性表存储空间得分配增量 

#define TURE 1
#define FAlSE 0
#define OK 1
#define ERROR 0
#define INFEASEBLE -1
#define OVERFLOW -2
// Status 是函数的类型，其值是函数结果状态代码 
typedef int ElemType; 
typedef int Status; 

typedef struct {
	ElemType *elem;        // 存储空间基址
	int length;            // 当前长度
	int listsize;          // 当前分配量的存储容量（以sizeof（ElemType）为单位） 
}SqList ; 

Status InitList_Sq(SqList *L)
{
    // 构造一个空的线性表L 
	(*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));    
    if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
    return OK;
} //InitList_Sq


Status ListInsert_Sq(SqList *L){
	// 在顺序线性表L中第i个位置之前插入新的元素e
	// i的合法值为 1<i<ListLength_Sq(L)+1
	ElemType *q,*p,i,e;
	printf("\n\t\t\t\t\t\t请输入插入的位置\t");
	scanf("%d",&i); 
	printf("\n\t\t\t\t\t\t请输入插入的元素\t");
	scanf("%d",&e); 
	if(i<1||i>(*L).length+1)
		return ERROR;   //i值不合法
	if((*L).length>=(*L).listsize){
		ElemType *newbase;
		newbase = (ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;      // 增加存储容量 
	}
	q = &((*L).elem[i-1]);
	for (p = &((*L).elem[(*L).length-1]);p>=q;--p)
		*(p+1) = *p; 
	*q =e;
	++(*L).length ;
	return OK;
} //ListInsert_Sq

Status ListDelete_Sq(SqList *L){
	// 在顺序表L中删除第I个元素 ， 并用e返回其值
	// i的合法值为 1<i<ListLength_Sq(L) 
	ElemType *p,*q,i,e;
	printf("\n\t\t\t\t\t\t请输入删除的位置\t");
	scanf("%d",&i); 
	if((i<1)||(i>(*L).length))
		return ERROR;   // i值不合法
	p = &((*L).elem[i-1]);                     // p为被删除元素的位置 
	e = *p;                                    // 被删除元素的值赋给e
	printf("\n\t\t\t\t\t\t删除的元素：%d\n",e);
	q = (*L).elem + (*L).length - 1;           // 表尾元素的位置
	for(++p ; p <= q ; ++p)
		*(p-1) =* p ;       // 被删除元素之后的元素左移
	--(*L).length;                             // 表长减 1
	return OK; 	 
}   // ListDelete_Sq

Status DestoryList(SqList *L) {
	// 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L 
	free((*L).elem);
	(*L).elem=NULL;
	(*L).length=0;
	(*L).listsize=0;
	return OK;
	}  

Status GetElem(SqList *L){
	//初始条件：顺序线性表已存在。操作结果：返回线性表中第 i 个元素的值
	ElemType i,e,*p,n,*q;
	printf("\t\t\t\t\t1--输出线性表所有元素，2--输出指定位置元素\n");
	scanf("%d",&n); 
	printf("\n\t\t\t\t\t\t线性表：");
	if (n==1)
	{
		p = &((*L).elem[0]);
		q = (*L).elem + (*L).length - 1;
		for(p ; p <= q ; ++p)	
		{
			e = *p;                                    // 查询目标元素的值赋给e
			printf("%d\t",e);// 显示 e 的值
		} 
		return OK;	
	}
	else if (n==2) 
	{
		printf("\n\t\t\t\t\t\t请输入目标元素的位置\n");
		scanf("%d",&i);
		if((i<1)||(i>(*L).length))
			return ERROR;   // i值不合法
		p = &((*L).elem[i-1]);                     // p为目标元素的位置 
		e = *p;                                    // 查询目标元素的值赋给e
		printf("\n\t\t\t\t\t\t目标元素值：%d\n",e);// 显示 e 的值
		return OK;
	}
	else
	{
		return ERROR;
	}
} 

void ListLength(SqList *L){
	if (!(*L).elem) exit(OVERFLOW);
	printf("\n\t\t\t\t\t\t线性表长度：%d\n",(*L).length);// 显示 L.length 线性表长度 
}

void ClearList(SqList *L){
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;  // 置为空表 
}




