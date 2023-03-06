#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
void insert_at_beginning(struct node **head_ref, int data)
{

	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->link=*head_ref;
	*head_ref = newNode;
}

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;
	int n, i;
	printf("Enter the size of the linked list:\n");
	int a[n];
	printf("Enter the elements in the list\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &n);
		insert_at_beginning(&head, n);
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d", temp->data);
		temp = temp->link;
	}
return 0;
}
