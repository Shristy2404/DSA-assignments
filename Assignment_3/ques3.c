#include <stdio.h>
#include <stdlib.h>

int n;
int k;
int arr[1000];
int flag=0;

struct node{
	int val;
	struct node* next;
};

struct node* root=NULL;
struct node* root_mod=NULL;

void input()
{
	printf("Enter elements\n");
	int i=0; char c;
	do
	{
		scanf("%d%c",&arr[i++],&c);
	}while(c!='\n');
	n=i;
}

struct node* create_list()
{
	struct node* ptr=NULL;
	struct node* prev=NULL;
	int i=0;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		if(root==NULL)
			root=ptr;
		ptr->val=arr[i];
		if(prev==NULL)
			prev=ptr;
		else
		{
			prev->next = ptr;
			prev = ptr;
		}
	}
	return (struct node*)root;
}

void print(struct node* ptr)
{
	if(ptr==NULL)
		printf("Empty\n");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void modify_k()
{
	struct node* temp=NULL;
	struct node* prev=NULL;
	struct node* ptr=root;
	int i=0;
	while(ptr!=NULL)
	{
		i++;
		if(i>=k && i%k==0)
		{
			printf("Should add node %d\n",i);
			temp=(struct node*)malloc(sizeof(struct node));

			if(root_mod==NULL)
				root_mod=temp;
			temp->val=ptr->val;

			if(prev==NULL)
				prev=temp;

			else
			{
				prev->next=temp;
				prev=temp;
			}
		}
		ptr=ptr->next;
	}
	//return (struct node*)root_mod;
}

void reverse()
{
	int i=0;
	struct node* temp=root_mod;
	struct node* ptr=root;
	struct node* trav=NULL;

	if(temp!=NULL)
	{
		while(temp->next!=NULL)
			temp=temp->next;
	}	

	while(ptr!=NULL)
	{
		i++;
		if(!(i>=k && i%k==0))
		{
			printf("Inserting node %d\n",i);
			trav=(struct node*)malloc(sizeof(struct node));
			if(temp==NULL && temp==root_mod)
			{
				flag=1;
				root_mod=trav;
				temp=trav;
			}
			else if(temp->next==NULL)
				temp->next=trav;
			else
			{
				trav->next=temp->next;
				temp->next=trav;
			}
			trav->val=ptr->val;
		}
		ptr=ptr->next;
	}

	if(flag==1)
	{
		ptr=root_mod;
		struct node* ptr2=root_mod;
		struct node* ptr1 = ptr->next;

		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=root_mod;
		root_mod=ptr1;
		ptr2->next=NULL;

	}
}

int main()
{
	printf("Enter k\n");
	scanf("%d",&k);

	input();
	create_list();
	print(root);

	if(k==1)
		printf("Resultant list will be empty\n");
	else
	{

	modify_k();
	print(root_mod);

	reverse();
	print(root_mod);
	}
	return 0;
}

