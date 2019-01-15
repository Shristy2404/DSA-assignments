#include <stdio.h>

int n; 
int arr[1000][1000];

void form()
{
	int k=0; int l=0; int i;
	int m=n; int p=n; 
	int val = n*n;

	while(k<m && l<p)
	{

			for(i=l; i<p; i++)
			{
				arr[k][i]=val--;
			}
			k++;
			for(i=k; i<m; i++)
			{
				arr[i][p-1]=val--;
			}
			p--;
			if(k<m)
			{
				for(i=p-1; i>=l; i--)
				{
					arr[m-1][i]=val--;
				}
				m--;
			}
			if(l<p)
			{
				for(i=m-1; i>=k; i--)
				{
					arr[i][l]=val--;
				}
				l++;
			}
	}
}

void transform()
{
	int i,j; 
	for(i=0; i<n; i++)
	{
		for(j=0; j<(n/2); j++)
		{
			int temp = arr[i][j];
			arr[i][j]=arr[i][n-j-1];
			arr[i][n-j-1]=temp;
		}
	}
	for(i=0; i<(n/2); i++)
	{
		for(j=0; j<n; j++)
		{
			int temp = arr[i][j];
			arr[i][j]= arr[n-i-1][j];
			arr[n-i-1][j]= temp;
		}
	}
}


void print()
{
	int i,j; 
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	scanf("%d", &n);
	form();
	if(n%2==0)
		print();
	else
	{
		transform();
		print();
	}
	return 0;
}