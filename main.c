#include <stdio.h>
#include <stdlib.h>

typedef struct Student
		{
			long num;
			float score;
			struct Student *next;
		}LinkList;

//�޸�����ڵ�ֵ

void change(LinkList *list,int n)       //nΪ��n���ڵ�
{
	int i = 0;
	while (i < n && list != NULL)
	{
		list = list->next;
		i++;
	}
	if (list != NULL)
	{
		puts("input a change number:");
		scanf("%ld,%f",&list->num, &list->score);
	}
	else
	{
		puts("the node does not exist.");
	}
}

	//ɾ������ڵ�

	void delet(LinkList *list,int n)    //nΪҪɾ���Ľڵ�
	{
		int i = 0;
		while (i < n && list != NULL)
		{
			list = list->next;
			i++;
		}
		if (list != NULL)
		{
			list = list->next->next;
			free(list->next);
		}
		else
		{
			puts("the node does not exist.");
		}
	}

	//��������ڵ�

	void insert(LinkList *list, int n)
	{
		LinkList *in;
		int i = 0;
		while (i < n && list != NULL)
		{
			list = list->next;
			i++;
		}
		if (list != NULL)
		{
			in = (LinkList*)malloc(sizeof(LinkList));
			puts("input the insert number:");
			scanf("%ld,%f",&in->num, &in->score);
			in->next = list->next;   //��in��ָ����ָ��list����һ���ڵ�
			list->next = in;         //��list��ָ����ָ��in
		}
		else
		{
			puts("the node does not exist.");
		}
	}


	//�������

	void EmptyTheLinkList(LinkList *list)
	{
		LinkList* psave; // �������浱ǰ��������һ�ڵ�ĵ�ַ
		while (list != NULL)
		{
			psave = list->next;
			free(list);
			list = psave;
		}
	}


	//�������

	void output(LinkList *list)
	{
		while (list->next != NULL)
		{
			list = list->next;
			printf("\nnum:%ld\nscore:%f\n",list->num, list->score);
		}
	}

	struct Student *stu(void)
{
	int n;
	struct Student *head, *p1, *p2;
	n = 0;
	p1 = p2 =(struct Student*)malloc(sizeof(struct Student));
	scanf("%ld,%f",&p1->num,&p1->score);
	head = NULL;
	while (p1->num != 0)
	{
		n++;
		if (n == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Student*)malloc(sizeof(struct Student));
		scanf("%ld,%f",&p1->num,&p1->score);
	}
	p2->next = NULL;
	return (head);
}

int main()
{

		int n = 0;
		scanf("%d",&n);
		printf("�����n��ִֵ����Ӧ����\n");
		printf("n = 0,�޸Ľڵ㣻");
		printf("n = 1,ɾ���ڵ㣻");
		printf("n = 2,����ڵ㣻");
		printf("n = 3,�������");
		printf("n = 4,�������");
		LinkList *p;
		p = stu();
		switch(n)
		{
			case 0:{int a1;
					printf("������Ҫ�޸ĵڼ����ڵ㣺\n");
					scanf("%d", &a1);
					change(p,a1);
					break;
				   }
			case 1:{int a2;
					printf("������Ҫɾ���ĸ��ڵ㣺\n");
					scanf("%d", &a2);
					delet(p, a2);
					break;
				   }
			case 2:{int a3;
					printf("������Ҫ����ڼ����ڵ�:\n");
					scanf("%d", &a3);
					insert(p, a3);
					break;
				   }
			case 3:{EmptyTheLinkList(p);break;}
			case 4:output(p);
					break;
		}

    return 0;
}
