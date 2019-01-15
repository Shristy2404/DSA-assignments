#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1000];
int n; 

struct node{
	int val; 
	struct node* next;
};

struct node* root = NULL;

void input()
{
	int i=0; char ch;
	do{
		scanf("%d%c", &arr[i++], &ch);
	}while(ch!='\n');

	n=i;
	// for(i=0; i<n; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }
}


void print(struct node* ptr)
{
	if(ptr==NULL)
		printf("Empty\n");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d ", ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

struct node* create_list()
{
	struct node* ptr = NULL;
	struct node* lastptr = NULL;

	int i;
	for(i=0; i<n; i++)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		if(root == NULL)
			root = ptr;
		ptr->val = arr[i];
		if(lastptr==NULL)
			lastptr=ptr;
		if(lastptr!=NULL)
		{
			lastptr->next = ptr;
			lastptr = ptr;
		}

	}
	return (struct node*)root;
}

int search(int x)
{
	struct node* ptr = root;
	int i=0;
	while(ptr!=NULL)
	{
		//printf("%d ", ptr->val);
		if(ptr->val == x)
			return i;
		ptr=ptr->next;
		i++;
	}
	return -1;
}

struct node* return_pos(int x)
{
	struct node* ptr = root;

	while(ptr!=NULL)
	{
		if(ptr->val == x)
		{
			//printf("x found %p\n", ptr);
			return ptr; 
		}
		ptr=ptr->next;
	}
}

int delete(int x)
{
	struct node* ptr = return_pos(x);
	if(ptr->next==NULL)
		return 0;
	struct node* prev = NULL;
	prev = ptr;
	ptr=ptr->next;
	while(ptr!=NULL)
	{
		while(ptr!=NULL && ptr->val!=x)
		{
			prev = ptr;
			ptr=ptr->next;
		}

	if(ptr==NULL)
		return 1;
	prev->next = ptr->next;
	free(ptr);
	ptr=prev->next;
	}
	return 1;
}

void swap(int x)
{
	struct node* ptr = return_pos(x);
	int ind = search(x);
	struct node* ptrnext = ptr->next;
	if(ptr==root)
	{
		root = ptrnext;
		ptr->next = ptrnext->next;
		ptrnext->next=ptr;
	}
	else
	{
	struct node* prev = return_pos(arr[ind-1]);
	
	prev->next = ptrnext;
	ptr->next = ptrnext->next;
	ptrnext->next = ptr;
	}

}

int main()
{
	input();
	create_list();
	//print(root);
	printf("Enter value to search\n");
	int k; int sw;
	scanf(" %d",&k);
	printf("%d found at %d\n",k,search(k));
	//printf("%p\n",return_pos(3));
	if(search(k)!=-1)
	{
		sw=delete(k);
		printf("%d\n",sw);
		if(sw==0)
			print(root);
		else
		{
			swap(k);
		}
	}
	else
	{
		printf("Element not present\n");
	}
	print(root);
	return 0;
}