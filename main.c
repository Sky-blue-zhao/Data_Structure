#include "lib.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	SqList L;
	int a;
	printf("\t\t\t\t\t\t��ӭʹ��˳��洢�ṹ���Ա�������\n");
	printf("\n\t 1--�������Ա� 2--�������ݣ��������ݺ�λ�ã� 3--ɾ�����ݣ�����λ�ã� 4--Ԫ�ز�ѯ  5--��ʾ���Ա���  6--��Ϊ�ձ� 7--�˳�����\n");
	while(OK)
	{
		printf("\n��ѡ�����\n");
		scanf("%d",&a);
		if(a==1) 
		{ 
			if(InitList_Sq(&L)==OK) 
			printf("���Ա����ɹ�");
			else
			printf("���Ա�����ʧ��"); 
		} 	
		else if(a==2) 
		{ 
			if(ListInsert_Sq(&L)==OK)
			printf("�������ݳɹ�");
			else
			printf("��������ʧ��"); 
		} 
		else if(a==3)
		{ 
			if(ListDelete_Sq(&L)==OK) 
			printf("ɾ�����ݳɹ�");
			else
			printf("ɾ������ʧ��");  
		}
		else if(a==4)
		{ 
			if(GetElem(&L)==OK) 
			printf("\nԪ�ز�ѯ�ɹ�");
			else
			printf("\nԪ��λ�ò��Ϸ�"); 
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
			printf("���Ա����ٳɹ�");
			else
			printf("���Ա�����ʧ��"); 
			break; 
		}
		else
		{ 
			printf("�������");
		}     
	}
	return 0;
}
