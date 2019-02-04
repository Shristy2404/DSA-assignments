#include <stdio.h>
#include <stdbool.h>

int adj[1000][1000];
int e,v; int t;
int q[1000];
int front = -1;
int rear = -1;

void push(int n)
{	
	if(rear==999)
		printf("Queue is full\n");
	else
	{
		if(front==-1)
			front++;
		q[rear++]=n;
	}
}

int pop()
{
	if(front<=rear && front!=-1)
		return q[front++];
	else
		printf("Queue empty\n");
}


void form_mat()
{
	int a,b;
	while(e--)
	{	
		scanf("%d %d ",&a,&b);
		adj[a][b]=1;
		adj[b][a]=1;
	}
}

int bfs(int x)
{
	int count=0;
	int level[1000];
	bool visited[1000];

	push(x);

	level[x]=0;
	visited[x]=true;

	while(front<=rear)
	{
		int ele = pop();
		int i;
		for(i=0;i<v;i++)
		{
			if(adj[ele][i]==1 && !visited[i])
			{
				push(i);
				level[i]=level[ele]+1;
				visited[i]=true;
			}
		}
	}

	int i;
	for(i=0;i<v;i++)
	{
		if(level[i]==t)
			count++;
	}
	return count;
}

int main()
{
	printf("Enter number of nodes\n");
	scanf("%d\n",&v);

	printf("Enter number of edges\n");
	scanf("%d\n",&e);

	form_mat();

	printf("Enter the required distance\n");
	scanf("%d ",&t);

	int i,j; int res;
	for(i=0;i<v;i++)
	{
		front =-1;
		rear = -1;
		for(j=0;j<v;j++)
		{
			q[j]=-1;
		}
		res= res+ bfs(i);
	}
	printf("Result is %d\n", res/2);
	return 0;
}
