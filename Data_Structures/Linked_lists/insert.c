#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void println(struct node *head)
{
	while(head->next != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int getlen(struct node *head)
{
	int count = 0;
	while(head != NULL)
	{
		count += 1;
		head = head->next;
	}
	return (count);
}

void insert_head(struct node **head_ref, int newdata)
{
	struct node *newnode = (struct node *) malloc(sizeof(struct node)) ;
	newnode->data = newdata;
	newnode->next = NULL;
	
	newnode->next = *head_ref;
	*head_ref = newnode;
}

int main()
{
	struct node *head;
//	head->next = NULL;
	insert_head(&head, 1);
	insert_head(&head, 2);
	println(head);
	return(0);
}

