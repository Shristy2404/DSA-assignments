#include <stdio.h>
#include <stdbool.h>

int adj[1000][1000];
int e,v;
int q[1000];
int t;
int que[10][2];
int front=0;
int rear=0;
int nodes[1000];

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

	printf("Enter number of queries\n");
	scanf("%d",&t);

	int i,j;
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&que[i][0],&que[i][1]);
	}

	// for(i=1;i<=v;i++)
	// {
	// 	bfs(i);
	// 	for(j=0;j<v;j++)
	// 	{
	// 		if(nodes[j]!=-1)
	// 			printf("%d ", nodes[j]);
	// 	}
	// 	printf("\n");
	// }

	for(i=0;i<t;i++)
	{
		int flag=0;
		int x=que[i][0];
		int y=que[i][1];
		bfs(x);
		for(j=0;j<v;j++)
		{
			if(nodes[j]==y)
			{
				flag=1;
				printf("Yes\n");
				break;
			}
		}
		if(flag==0)
			printf("No\n");
	}
	return 0;

}