#include<stdio.h>
#include<stdlib.h>


int n;
int c[100] = {0}; //color array

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

// Inserts the new node at end including the pointer to the previous node
void insert(struct Node** head, int val, int pre, int nex)
{
	Node *temp = *head;
    Node *new = (Node *)malloc(sizeof(struct Node));
    new -> data = val;
    new -> next = NULL;
    for(int i=1; i<pre; i++)
		{
			temp = temp -> next;
		}
		new -> prev = temp;

	if(*head == NULL && val == 1)
	{
		*head = new;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new;
	}
}

// Prints the list
void print(Node** head)
{
	Node* temp = *head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp -> next;
	}
	printf("\n");
}

//debugging - prints the previous nodes starting from second node
void printpre(Node** head)
{

	Node* temp = *head;
	temp = temp -> next;
	while(temp != NULL)
	{
		printf("%d ", temp->prev->data);
		temp = temp -> next;
	}
	printf("\n");
}

void loopcheck(Node** head)
{
	Node* temp = *head;
	Node* pre = NULL;
	while(temp != NULL)
	{
		if(temp -> prev != pre)
		{
			Node* temp1 = temp->prev;
			while(temp1 != temp)
			{
				 printf("%d ", temp1->data);
				 temp1 = temp1->next;
			}
			printf("%d %d\n", temp1->data, (temp1->prev)->data);
		}
		pre = temp;
		temp = temp->next;
	}

}

void color(Node** head)
{
	c[0] = 0;
	c[1] = 1;
	int counter = 2;
	int val;

	Node* temp = *head;
	temp = temp -> next -> next;
	Node* parent = *head;
	parent = parent -> next;
	Node* grandparent = temp -> prev;
	while(temp != NULL)
	{
		if(parent == grandparent)
		{
			c[counter] = c[counter-2];
		}
		else
		{
			val = (c[counter-1]+1) % 3;
			if(val!=c[(grandparent -> data)-1])
                c[counter] = val;
            else
                c[counter] = (val+1)%3;
		}
		counter++;
		parent = temp;
		temp = temp -> next;
		if(temp != NULL)
			grandparent = temp -> prev;

	}

	for(int i=0; i< counter; i++)
        printf("%d ",c[i]);
}

int main()
{
	Node* head = NULL;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf("Enter the list: \n");
	int x, y, z;
	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		insert(&head, x, y, z);
	}

	printf("\n");
	print(&head);
	// printpre(&head);
	loopcheck(&head);
	//printf("\n");
	color(&head);
	printf("\n");

}