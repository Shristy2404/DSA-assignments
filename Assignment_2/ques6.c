#include <stdio.h>
#include <stdbool.h>

int adj1[1000][1000];
int adj2[1000][1000];
int adj_temp[1000][1000];
int adj_temp2[1000][1000];
int e,v;
bool visited[1000];

void print_mat(int n, int mat[1000][1000])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

void form_new_graph()
{
	int i,j,k;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(adj1[i][j]!=0)
			{
				for(k=j+1;k<v;k++)
				{
					if(adj1[i][k]!=0)
					{
						adj2[adj1[i][j]-2][adj1[i][k]-2]=1;
						adj2[adj1[i][k]-2][adj1[i][j]-2]=1;
					}
				}
			}
		}
	}
}

void remove_vertex(int n)
{
	int i,j;
	for(i=0;i<e;i++)
	{
		for(j=0;j<e;j++)
		{
			if(i==n || j==n)
				adj_temp[i][j]=0;
			else
				adj_temp[i][j]=adj2[i][j];
		}
	}
}

void dfs(int n)
{
	visited[n]=true;
	int i;
	for(i=0;i<e;i++)
	{
		if(adj_temp[n][i]==1 && !visited[i])
		{
			adj_temp2[n][i]=1;
			adj_temp2[i][n]=1;
			dfs(i);
		}
	}
}

int main()
{
	int flag=0;
	printf("Enter number of vertices\n");
	scanf("%d",&v);

	printf("Enter number of edges\n");
	scanf("%d",&e);

	printf("Enter adjacency matrix\n");
	int i,j,k,l;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&adj1[i][j]);
		}
	}

	int count = e+1;
	for(i=v-1;i>=0;i--)
	{
		for(j=v-1;j>=0;j--)
		{
			if(adj1[i][j]==1)
			{
				//printf("%d %d %d\n",i,j,count);
				adj1[i][j]=count;
				adj1[j][i]=count;
				count--;
			}
		}
	}
	printf("Original graph is: \n");
	print_mat(v,adj1);

	form_new_graph();

	printf("New graph is: \n");
	print_mat(e,adj2);

	for(i=0;i<e;i++)
	{
		int c=0;
		remove_vertex(i);
		for(j=0;j<e;j++)
		{
			if(!visited[j])
			{
				dfs(j);
				c++;
			}
		}
		if(c>1)
		{
			flag=1;
			printf("Removing vertex %d, there are %d components\n",i,c);
			for(k=0;k<e;k++)
			{
				for(l=0;l<e;l++)
				{
					printf("%d ",adj_temp2[k][l]);
					adj_temp2[k][l]=0;
				}
				printf("\n");
			}
		}
		for(j=0;j<e;j++)
			visited[j]=false;
	}
	if(flag==0)
		printf("No cut vertex\n");

	return 0;
}