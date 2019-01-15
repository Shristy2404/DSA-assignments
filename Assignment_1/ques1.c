#include <stdio.h>

int arr[100][100];
int n;

void input(int n)
{
	int i,j;
	int a;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &a);
			arr[i][j]=a;
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

void find()
{
	int i,j; int min, max; 
	int f = 0;
	int p1 =0; int p2=0;
	int p3 = 0; int p4 = 0; 
	int c=0;

	for(i=0; i<n; i++)
	{
		//printf("Inside for\n");
		min = arr[i][0];
		for(j=0; j<n; j++)
		{
			if(arr[i][j]<min)
			{
				min = arr[i][j];
				p1 = i;
				p2 = j;
			}
		}
		printf("Min of row %d is %d\n",i,min);

		max = arr[0][p2];
		for(j=0; j<n; j++)
		{
			if(arr[j][p2]>max)
			{
				max = arr[j][p2];
				p3 = j;
				p4 = p2;
			}
		}

		printf("Max of column %d is %d\n",p2,max);
		// for(j=0; j<n; j++)
		// {
		// 	f=0;
		// 	if(arr[j][p2]>min && j!=p1)
		// 	{
		// 		//printf("%d\n",min);
		// 		//printf("%d\n",arr[j][p2]);
		// 		f=1; 
		// 		break;
		// 	}
		// }

		if(p1==p3 && p2==p4 && min==max)
		{
			printf("%d , %d\n", p1,p2);
			printf("%d\n", arr[p1][p2]);
		}
		else
			c++;

	}
	if(c==n)
		printf("No saddle point\n");
}

int main()
{
	scanf("%d", &n);
	//printf("N is %d\n", n);
	input(n);
	find();
	return 0;
}