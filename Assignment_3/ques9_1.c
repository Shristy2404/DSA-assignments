#include <stdio.h>
#include <stdbool.h>

int adj[1000][1000];
int e,v;
int q[1000];
int front=0;
int rear=0;
int nodes[1000];
int vertices[1000];
int p=0;
int flag=0;

void form_mat()
{
	int a,b;
	while(e--)
	{
		scanf("%d %d",&a,&b);
		adj[a][b]=1;
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
	if(front>=rear)
		printf("Queue empty\n");
	else
		return q[front++];
}

void bfs(int n)
{
	bool visited[1000];
	int c=0;
	for(int i=0;i<=v;i++)
	{
		nodes[i]=-1;
		visited[i]=false;
	}

	push(n);
	visited[n]=true;

	while(front!=rear)
	{
		int x=pop();
		for(int j=1;j<=v;j++)
		{
			if(adj[x][j]==1 && !visited[j])
			{
				push(j);
				nodes[c++]=j;
				visited[j]=true;
			}
		}
	}
}

int main()
{
	printf("Enter number of cities and sharks\n");
	scanf("%d %d",&v,&e);

	form_mat();

	int i,j;

	for(i=0;i<v;i++)
		nodes[i]=-1;


	for(i=1;i<=v;i++)
	{
		int c=0;
		bfs(i);
		for(j=0;j<v;j++)
		{
			if(nodes[j]!=-1)
			{
				printf("%d ",nodes[j]);
				c++;
			}
		}
		printf("for %d count is %d\n",i,c);
		if(c==v-1)
		{
			flag=1;
			//printf("Putting %d in nodes\n",i);
			vertices[p++]=i;
		}
	}
	if(flag==0)
		printf("No\n");
	else
	{
		printf("Yes\n");
		for(i=0;i<p;i++)
			printf("%d ",vertices[i]);
	}

	return 0;

}