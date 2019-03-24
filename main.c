#include <stdio.h>
#include <stdlib.h>


typedef struct DoubleLinkNode

{

   int data;

   struct DoubleLinkNode *prev;

   struct DoubleLinkNode *next;

}Node;


void print(Node*head)
{
	Node*temp;
	int j = 0;
	temp = head;
	while (temp->next != NULL)
	{
		j++;
		printf("%d ",temp->data);
	}
}

//����ڵ�

int InsertNode(Node*head)
{
	Node *new1;
	Node *pnext = head;
	int i = 0;
	int n;
	printf("���������ڼ����ڵ�:\n");
	scanf("%d",&n);
	while ((i < n) && (pnext != NULL))
	{
		i++;
		pnext = pnext->next;
	}
	if (pnext == NULL)
	{
		return 1;
	}
	else
	{
		new1 = (Node*)malloc(sizeof(Node));
		printf("���������ڵ�����:");
		scanf("%d",&new1->data);

		new1->next = pnext->next;
		if (n == 0)
		{
			pnext->next = new1;
			pnext->next->prev = new1;
			new1->prev = pnext;
		}

	}
	return 0;
}

//ɾ���ڵ�

int DeleteNode(Node*head)
{
	Node *pnext = head;
	Node *ptr;
	int n;
	int i = 0;
	printf("Ҫɾ���Ǹ��ڵ�?");
	scanf("%d",&n);
	while ((i < n) && (pnext != NULL))
	{
		i++;
		pnext = pnext->next;
	}
	if (pnext->next->next != NULL)
	{
		ptr = pnext->next;
		ptr->next->prev = pnext;
		pnext = ptr->next;
		free(ptr);
	}
	else
	{
		ptr = pnext->next;
		free(ptr);
	}
	return 0;
}

Node*Create_Double_link()
	{
		Node*head;
		Node*pnext;
		Node*plast;
		int i, n;
		head = (Node*)malloc(sizeof(Node));
		head->prev = NULL;
		head->next = NULL;

		printf("������˫������ĳ���:\n");
		scanf("%d",&n);
		while (n!=0)
		{
			plast = head;
			for (i = 0; i < n; i++)
			{
				pnext = (Node*)malloc(sizeof(Node));
				printf("������Ӧ�����ݣ�");
				scanf("%d",&pnext->data);
				plast->next = pnext;
				pnext->prev = plast;
				plast = plast->next;
			}
			pnext->next = NULL;
			break;
		}
		return head;
}

int main()
{

	Node *head = Create_Double_link();
	InsertNode(head);
	DeleteNode(head);
	print(head);
	return 0;
}

