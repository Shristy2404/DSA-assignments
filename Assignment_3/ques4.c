#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int adj[1000][1000];
int e,v;
int x,y;
int q[1000];
int front=0;
int rear=0;
int parent[1000];
int dist[1000];
bool visited[1000];
int path[1000];
int count=0;


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
		printf("Queue is full\n");
	else
		q[rear++]=n;
}

int pop()
{
	if(front>=rear)
		printf("Queue is empty\n");
	else
		return q[front++];
}

void init()
{
	int i;
	front=0;
	rear=0;
	for (int i = 0; i < 1000; ++i)
	{
		visited[i]=false;
		q[i]=-1;
		path[i]=-1;
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
}

bool bfs(int u, int f)
{
	int c=0;
	visited[u]=true;
	push(u);
	dist[u]=0;

	while(front!=rear)
	{
		int ele=pop();
		int i;
		for(i=1;i<=v;i++)
		{
			if(adj[ele][i]==1 && !visited[i])
			{
				push(i);
				dist[i]=dist[ele]+1;
				parent[i]=ele;
				visited[i]=true;

				if(i==f)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	printf("Enter number of cities and cities x and y\n");
	scanf("%d %d %d",&v,&x,&y);

	e=v-1;
	form_mat();

	int i,j,k,t,flag;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			printf("Checking path for %d to %d\n",i,j);
			flag=0;
			if(i==j)
				continue;
			init();
			if(bfs(i,j))
			{
				printf("%d and %d are connected\n",i,j);
				int l=dist[j];
				int c=l;
				//printf("Length of path between %d and %d is %d ",i,j,l);
				int vertex=j;
				path[c--]=vertex;
				while(vertex!=-1)
				{
					path[c--]=parent[vertex];
					vertex=parent[vertex];
				}
				path[l]=j;
				// printf("Path between %d  and %d is ",i,j);
				// for(k=0;k<=l;k++)
				// 	printf("%d ",path[k]);
				// printf("\n");
				for(k=0;k<=l;k++)
				{
					if(path[k]==x)
					{
						for(t=k+1;t<=l;t++)
						{
							if(path[t]==y)
								flag=1;
						}
					}
				}
				if(flag==0)
				{
					//printf("Taking path from %d to %d\n",i,j);
					count++;	
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}