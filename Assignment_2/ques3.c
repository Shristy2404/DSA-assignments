#include <stdio.h>
#include <stdbool.h>


int adj[1000][1000];
int e,v;
int q[1000];
int front=-1; int rear=-1;

void push(int n)
{	
	if(rear==999)
		printf("Queue is full\n");
	else
	{
		if(front==-1)
		{
			rear=0;
			front=0;
		}
		q[rear++]=n;
	}
}

int pop()
{
	if(front<=rear && !(front==-1 && rear==-1))
		return q[front++];
}

bool isBipartite(int src)
{
	int colour[v];
	int i;
	for(i=0; i<v; i++)
		colour[i]=-1;

	colour[src]=1;

	push(src);

	while(front<=rear)
	{
		int u = pop();
		if(adj[u][u]==1)
			return false;

		for(i=0;i<v;i++)
		{
			if(adj[u][i]==1 && colour[i]==-1)
			{
				colour[i]=1 - colour[u];
				push(i);
			}
			else if(adj[u][i]==1 && colour[i]==colour[u])
				return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&e,&v);
	int i,j=0;
	for(i=0; i<v; i++)
	{
		for(j=0; j<v; j++)
		{
			scanf("%d ",&adj[i][j]);
		}
	}
	if(isBipartite(0))
		printf("Bipartite\n");
	else 
		printf("Not Bipartite\n");

	return 0;
}