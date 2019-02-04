#include <stdio.h>

int n,m;
int a[1000][1000] = {0};
int vis[1000] = {0};
int dis[1000][1000] = {0};
int q[1000];
int r = 0;
int f = 0;
int c = 0;
int max = 0;
int path[1000] = {0};

void init()
{
	for(int i=0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			vis[i] = 0;
			q[i] = 0;
		}
	}
	f = 0;
	r = 0;
}

void dfs(int i, int end, int c)
{
	vis[i] = 1;
	path[c] = i;

	if(c == max && path[c] == end)
	{
		for(int j=0; j<=c; j++)
			printf("%d ",path[j]);
		printf("\n");
	}

	for(int j=0; j<n; j++)
	{
		if(a[i][j] == 1 && vis[j] == 0)
		{			
			dfs(j, end, c+1);
		}
	}
	vis[i] = 0;
}

void push(int val)
{
	q[r++] = val;
}

int pop()
{
	return q[f++];
}

void bfs(int row, int val)
{
	vis[val] = 1;
	push(val);

	int i;
	while(f<r)
	{
		i = pop();
		for(int j=0; j<n; j++)
		{
			if(a[i][j] == 1 && vis[j] == 0)
			{
				push(j);
				vis[j] = 1;
				dis[row][j] = dis[row][i]+1;
			}
		}
	}
	for(int j=0; j<n; j++)
	{
		if(dis[row][j] > max)
		{
			max = dis[row][j];
		}
	}

}

void printarr()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf("Enter the number of edges: ");
	scanf("%d", &m);

	printf("Enter the adjacency matrix: \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//printarr();
	printf("\n");

	for(int i = 0; i<n; i++)
	{
		bfs(i, i);
		init();
	}
	
	printf("\nDiameter is : %d \n", max);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(dis[i][j] == max)
			{
				dfs(i,j,0);
				//init();
			}
		}
	}
	
	return 0;
}