#include <stdio.h>
#include <stdbool.h>


int e,v;
int adj[1000][1000];
int m;
int cities[1000];
int front = -1;
int rear = -1;
int q[1000];
int levels[1000];

void form_mat()
{
	int a,b;
	while(e--)
	{
		scanf("%d %d",&a,&b);
		adj[a][b]=1;
		adj[b][a]=1;
	}
}

void push(int n)
{
	if(rear==999)
		printf("Queue full\n");
	else
	{
		if(front==-1)
			front=0;
		q[rear++]=n
	}
}

int pop()
{
	if(front<=rear && !(front==-1 && rear==-1))
		return q[front++];
	else
		printf("Queue empty\n");
}

void bfs(int x)
{
	bool visited[1000];

	push(x);
	visited[x]=true;
	levels[x]=0;

	while(front<=rear)
	{
		int ele = pop();
		int i;
		for(i=1;i<=v;i++)
		{
			if(adj[ele][i]==1 && !visited[i])
			{
				push(i);
				visited[i]=true;
				levels[i]=levels[ele]+1;
			}
		}
	}

}

int main()
{
	printf("Enter total cities\n");
	scanf("%d",&v);

	e=v-1;

	form_mat();

	printf("Enter cities with universities\n");
	scanf("%d ",&m);

	int i; 
	for(i=0;i<m;i++)
	{
		int temp;
		scanf("%d",&temp);
		cities[temp]=1;
	}

	for(i=0;i<1000;i++)
		levels[i]=-1;

	bfs(1);
	int min_level = INT_MAX;
	int index;

	for(i=1;i<1000;i++)
	{
		if(cities[i]==1 && levels[i]<min)
		{
			min=levels[i];
			index=i;
		}
	}
}