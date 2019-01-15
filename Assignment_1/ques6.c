#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
	int c=0; int i; 
	for(i=2; i<n; i++)
	{
		if(n%i==0)
		{
			c++;
		}
	}
	if(c!=0 || n==1)
		return false;
	return true;
}

int main()
{
	int a; int b; 
	scanf("%d %d", &a, &b);
	int i; 
	for(i=a; i<=b; i++)
	{
		if(is_prime(i))
			printf("%d ",i);
	}
	return 0;
}