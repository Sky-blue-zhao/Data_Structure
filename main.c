#include "lib.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	SqList L;
	int a;
	printf("\t\t\t\t\t\t欢迎使用顺序存储结构线性表管理程序\n");
	printf("\n\t 1--创建线性表 2--插入数据（输入数据和位置） 3--删除数据（输入位置） 4--元素查询  5--显示线性表长度  6--置为空表 7--退出程序\n");
	while(OK)
	{
		printf("\n请选择操作\n");
		scanf("%d",&a);
		if(a==1) 
		{ 
			if(InitList_Sq(&L)==OK) 
			printf("线性表创建成功");
			else
			printf("线性表销毁失败"); 
		} 	
		else if(a==2) 
		{ 
			if(ListInsert_Sq(&L)==OK)
			printf("插入数据成功");
			else
			printf("插入数据失败"); 
		} 
		else if(a==3)
		{ 
			if(ListDelete_Sq(&L)==OK) 
			printf("删除数据成功");
			else
			printf("删除数据失败");  
		}
		else if(a==4)
		{ 
			if(GetElem(&L)==OK) 
			printf("\n元素查询成功");
			else
			printf("\n元素位置不合法"); 
		} 
		else if(a==5)
		{ 
			ListLength(&L); 
		} 
		else if(a==6)
		{ 
			ClearList(&L); 
		} 
		else if(a==7) 
		{ 
			if(DestoryList(&L)==OK) 
			printf("线性表销毁成功");
			else
			printf("线性表销毁失败"); 
			break; 
		}
		else
		{ 
			printf("输入错误");
		}     
	}
	return 0;
}
