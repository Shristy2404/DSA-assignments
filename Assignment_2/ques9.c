#include <stdio.h>

int a[100][100];
int n; int m;

int findsum(int p, int q, int r, int s)
{
	int i,j;
	int subsum;
	for(i=p;i<q;i++)
	{
		for(j=r;j<s;j++)
		{
			subsum = subsum + a[i][j];
		}
	}
	return subsum;
}

int maxsum()
{
	int max = -1000*m;
	int i,j;
	int subsum;
	for(i=0;i<n-m;i++)
	{
		for(j=0;j<n-m;j++)
		{
			subsum = findsum(j,j+m,i,i+m);
			if(subsum>max)
				max=subsum;
		}
	}
	return max;
}
int main()
{
	printf("Enter n\n");
	scanf("%d\n",&n);

	printf("Enter elements\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d ",&a[i][j]);
		}
	}
	printf("Enter size of sub-matrix\n");
	scanf("%d",&m);
	int sum = maxsum();
	printf("Maximum sum is %d\n",sum);
}