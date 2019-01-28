#include <stdio.h>
#include <stdbool.h>


int adj[1000][1000];
int e,v;
int q[1000];
int front=-1; int rear=-1;
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
}

void push(int n)
{	
	if(rear==999)
		printf("Queue is full\n");
	else
		q[rear++]=n;
}

int pop()
{
	if(front<=rear)
		return q[front]
}

bool isBipartite(int adj[1000][1000], int src)
{
	int colour[v];
	int i;
	for(i=0; i<v; i++)
		colour[i]=-1;

	colour[src]=1;


}