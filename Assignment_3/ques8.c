#include <stdio.h>
#include <stdbool.h>

int adj[1000][1000];
int e,v,t;
int q[1000][2];
bool visited[1000];
int path[1000];
int co=0;

void form_mat()
{
	int a,b;
	while(e--)
	{
		scanf("%d %d",&a,&b);
		adj[a][b]=1;
	}
}

void dfs1(int i)
{
	visited[i]=true;
	int j;
	for(j=1;j<=v;j++)
	{
		if(adj[i][j]==1 && !visited[j])
		{
			printf("%d is adjacent to %d ",j,i);
			dfs1(j);
		}
	}
}

void dfs(int i)
{
	printf("%d %d\n",i,co);
	visited[i]=true;
	int j;
	for(j=1;j<=v;j++)
	{
		printf("Checking\n");
		printf("%d\n",adj[i][j]);
		if(adj[i][j]==1 && !visited[j])
		{
			printf("Printing %d ",j);
			printf("Putting %d at %d\n",j,co);
			path[co++]=j;
			dfs(j);
		}
	}
}

int main()
{
	printf("Enter number of cities and sharks\n");
	scanf("%d %d\n",&v,&e);

	form_mat();

	printf("Enter number of queries\n");
	scanf("%d\n",&t);

	int i,j,k; int a,b; int flag=0;
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		q[i][0]=a;
		q[i][1]=b;
	}

	for(i=0;i<t;i++)
	{
		flag=0;
		printf("Executing query %d\n",i);
		for(j=0;j<v+1;j++)
		{
			path[i]=-1;
			visited[i]=false;
		}
		co=0;
		dfs(q[i][0]);
		for(j=0;j<v;j++)
			printf("%d ",path[j]);
		for(k=0;k<v;k++)
		{
			if(path[k]==q[i][1])
				flag=1;
		}
		if(flag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}