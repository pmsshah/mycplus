#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void Insert(struct node** head_ref, struct node* new_node)
{
	new_node->next=*head_ref;
	*head_ref=new_node;
}

struct node *newNode(int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	return new_node;
}

void printList(struct node *head)
{
	struct node *temp=head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//build-manage link list.. 
	struct node* head=NULL;
	struct node *new_node;
	
	new_node=newNode(5);
	Insert(&head, new_node);
	new_node=newNode(10);
	Insert(&head, new_node);
	new_node=newNode(7);
	Insert(&head, new_node);
	new_node=newNode(3);
	Insert(&head, new_node);
	new_node=newNode(1);
	Insert(&head, new_node);
	new_node=newNode(9);
	Insert(&head, new_node);

	printf("\n Created Linked List\n");
	printList(head);
	printf("\n");
	return 0;
}