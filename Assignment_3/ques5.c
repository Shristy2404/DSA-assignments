#include <stdio.h>
#include <stdbool.h>

int n;
int mat[1000][1000];
bool visited[1000][1000];
int count=0;
int result=0;

bool is_safe(int r, int c)
{
	if( (r>=0 && r<n) && (c>=0 && c<n) && mat[r][c]==1 && !visited[r][c])
		return true;
	else
		return false;
}


void dfs(int r, int c)
{
	static int row_nbr[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
    static int col_nbr[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

    visited[r][c]=true;

    for(int i=0;i<8;i++)
    {
    	if(is_safe(r+row_nbr[i],c+col_nbr[i]))
    	{
    		count++;
    		dfs(r+row_nbr[i],c+col_nbr[i]);
    	}
    }
}

int largest_region()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==1 && !visited[i][j])
			{
				count=1;
				dfs(i,j);
				if(count>result)
					result=count;
			}
		}
	}
	return result;
}

int main()
{
	printf("Enter n\n");
	scanf("%d",&n);

	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	largest_region();
	printf("%d\n",result);
}