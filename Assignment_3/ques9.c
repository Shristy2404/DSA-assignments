#include <stdio.h>
#include <stdbool.h>

int adj[1000][1000];
int e,v;
int q[1000];
int front=0;
int rear=0;
bool visited[1000];
int flag = 0;

void form_mat()
{
	int a,b;
	while(e--)
	{
		scanf("%d %d",&a,&b);
		adj[a-1][b-1]=1;
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
	printf("%d %d %d\n",n,front,rear);
	visited[n]=true;
	push(n);
	//int c[1000]={0};
	int p=0;

	int j;

	while(front<rear)
	{
		int x=pop();
		for(j=0;j<v;j++)
		{
			if(adj[x][j]==1 && !visited[j])
			{
				p++;
				push(j);
			}
		}
		printf("p is %d for %d\n",p,n);
	}
	if(p==v-1)
	{
		flag = 1;
		printf("%d\n",n);
	}

}
int main()
{
	printf("Enter number of vertices and edges\n");
	scanf("%d %d",&v,&e);

	form_mat();

	int i,j;
	for(i=0;i<v;i++)
	{
		front=0;
		rear=0;
		for(j=0;j<v;j++)
		{
			visited[j]=false;
			q[j]=-1;
		}
		bfs(i);
	}

	return 0;
}