#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int adj[1000][1000];
int adj_temp[1000][1000];
int v;
int f[1000];
int delta;
bool visited[1000];

void form_graph()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(abs(f[i]-f[j])>delta)
			{
				adj[i][j]=1;
				adj[j][i]=1;
			}
		}
	}
}

void print()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

void dfs(int n)
{
	visited[n]=true;
	int i;
	for(i=0;i<v;i++)
	{
		if(n==i && adj[n][i] == 1)
			adj_temp[i][i] = 1;

		if(adj[n][i]==1 && !visited[i])
		{
			adj_temp[n][i]=1;
			adj_temp[i][n]=1;
			dfs(i);
		}
	}

}

int main()
{
	printf("Enter number of vertices\n");
	scanf("%d ",&v);

	printf("Enter factors\n");
	int i,j,k;
	for(i=0;i<v;i++)
	{
		scanf("%d ",&f[i]);
	}

	printf("Enter delta\n");
	scanf("%d ",&delta);

	form_graph();
	print();
	int c=0;

	for(i=0;i<v;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			c++;
			for(j=0;j<v;j++)
			{
				for(k=0;k<v;k++)
				{
					printf("%d ",adj_temp[j][k]);
				}
				printf("\n");
			}
			printf("\n********************\n");
		}
	}
	printf("There are %d components",c);
	return 0;
}