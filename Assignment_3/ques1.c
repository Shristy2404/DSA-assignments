#include <stdio.h>
#include <stdbool.h>

char t[1000];
char p[1000];
int len;
int len2=0;
int a[1000];

bool is_obtainable()
{
	int i,j; int c=0; int ind=0;
	for(i=0;i<len2;i++)
	{
		char ch=p[i];
		printf("Checking for %c from %d ",ch,ind);
		for(j=ind;j<len;j++)
		{
			if(t[j]==ch)
			{
				ind=j+1;
				c++;
				break;
			}
		}
	}
	printf("%d\n",c);
	if(c==len2)
		return true;
	else 
		return false;	
}

int main()
{
	printf("Enter string t\n");
	scanf("%[^\n]s",t);

	printf("Enter string p\n");
	scanf(" %[^\n]s",p);

	printf("Enter length of array a\n");
	scanf("%d",&len);

	printf("Enter array\n");
	int i;
	int count=0;
	for(i=0;i<len;i++)
	{
		scanf(" %d ",&a[i]);
	}

	for(i=0;i<1000;i++)
	{
		if((int)(p[i])!=0)
			len2++;
	}
	//printf("%d\n",len2);

	for(i=0;i<len;i++)
	{
		t[a[i]-1]='0';
		printf("%s\n",t);
		if(is_obtainable())
		{
			printf("Obtainable\n");
			count++;
		}
		else
			break;
	}
	printf("%d\n",count);
	return 0;

}