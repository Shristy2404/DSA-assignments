#include <stdio.h>
#include <stdlib.h>

int arr[1000];
int n;
int ch;

struct single_node{
	int val; 
	struct single_node* next;
};

struct double_node{
	int val;
	struct double_node* prev;
	struct double_node* next;
};

struct single_node* sroot = NULL;
struct double_node* droot = NULL;

void input()
{
	int i=0; char c;
	do
	{
		scanf("%d%c",&arr[i++],&c);
	}while(c!='\n');
	n=i;
}

void print_single(struct single_node* ptr)
{
	int c=0;
	if(ptr==NULL)
		printf("Empty\n");
	else
	{
		while(c!=n)
		{
			printf("%d ",ptr->val);
			ptr=ptr->next;
			c++;
		}
	}
}

void print_double(struct double_node* ptr)
{
	int c=0;
	if(ptr==NULL)
		printf("Empty\n");
	else
	{
		while(c!=n)
		{
			printf("%d ",ptr->val);
			ptr=ptr->next;
			c++;
		}
	}
}

struct single_node* createlistsorc()
{
	struct single_node* ptr = NULL;
	struct single_node* prev = NULL;
	int i;
	for(i=0; i<n; i++)
	{
		ptr = (struct single_node*)malloc(sizeof(struct single_node));
		if(sroot==NULL)
			sroot=ptr;
		ptr->val=arr[i];
		if(prev == NULL)
			prev = ptr;
		else
		{
			prev->next = ptr;
			prev = ptr;
		}
	}
	if(ch==3)
		prev->next = sroot;

	return (struct single_node*)sroot;
}

struct double_node* createlistd()
{
	struct double_node* ptr = NULL;
	struct double_node* last = NULL;
	int i;
	for(i=0; i<n; i++)
	{
		ptr = (struct double_node*)malloc(sizeof(struct double_node));
		if(droot==NULL)
		{
			ptr->prev = NULL;
			droot = ptr;
		}
		ptr->val = arr[i];
		if(last==NULL)
		{
			last = ptr;
		}
		else
		{
			last->next = ptr;
			ptr->prev = last;
			ptr-> next = NULL;
			last = ptr;
		}
	}
	return (struct double_node*)droot; 
}

void find_single_node(int l)
{
	struct single_node* ptr = sroot;
	int c=0;
	int value;
	int lim = n-l+1;
	if(l>n)
		printf("Invalid node number");
	else
	{
		while(c!=lim)
		{
			value=ptr->val;
			ptr=ptr->next;
			c++;
		}
		printf("%d\n",value);
	}
}

void find_double_node(int l)
{
	struct double_node* ptr = droot;
	int c=0;
	int value;
	int lim = n-l+1;
	if(l>n)
		printf("Invalid node number");
	else
	{
		while(c!=lim)
		{
			value=ptr->val;
			ptr=ptr->next;
			c++;
		}
		printf("%d\n",value);
	}
}

int main()
{
	int k;
	printf("1. Singly linked list  2. Doubly linked list 3. Circularly linked list\n");
	scanf(" %d\n",&ch);
	input();
	printf("Enter k\n");
	scanf(" %d",&k);
	//printf("%d %d\n",ch,k);
	if(ch==1 || ch ==3)
	{
		print_single(createlistsorc());
		find_single_node(k);
	}
	else if(ch == 2)
	{
		print_double(createlistd());
		find_double_node(k);
	}
	else
		printf("Invalid choice\n");

	return 0;
}
