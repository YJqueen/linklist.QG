#include <stdio.h>
#include <stdlib.h>

typedef struct Student
		{
			long num;
			float score;
			struct Student *next;
		}LinkList;

//修改链表节点值

void change(LinkList *list,int n)       //n为第n个节点
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

	//删除链表节点

	void delet(LinkList *list,int n)    //n为要删除的节点
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

	//插入链表节点

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
			in->next = list->next;   //把in的指针域指向list的下一个节点
			list->next = in;         //把list的指针域指向in
		}
		else
		{
			puts("the node does not exist.");
		}
	}


	//清空链表

	void EmptyTheLinkList(LinkList *list)
	{
		LinkList* psave; // 用来保存当前清除项的下一节点的地址
		while (list != NULL)
		{
			psave = list->next;
			free(list);
			list = psave;
		}
	}


	//输出链表

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
		printf("请根据n的值执行相应过程\n");
		printf("n = 0,修改节点；");
		printf("n = 1,删除节点；");
		printf("n = 2,插入节点；");
		printf("n = 3,清空链表；");
		printf("n = 4,输出链表；");
		LinkList *p;
		p = stu();
		switch(n)
		{
			case 0:{int a1;
					printf("请输入要修改第几个节点：\n");
					scanf("%d", &a1);
					change(p,a1);
					break;
				   }
			case 1:{int a2;
					printf("请输入要删除哪个节点：\n");
					scanf("%d", &a2);
					delet(p, a2);
					break;
				   }
			case 2:{int a3;
					printf("请输入要插入第几个节点:\n");
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
