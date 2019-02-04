#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[10];
int count[26]={0};
int l=0;


bool check()
{
	int i,j;
	char ch;
	int p =0;
	int l_flag=0;

	for(i=97;i<=122;i++)
	{
		//printf("%c ",(char)(i));
		//printf("\n");
		for(j=0;j<10;j++)
		{
			ch = str[j];
			//printf("%c ",ch);
			//printf("%c\n",ch, (char)i);
			if(ch == (char)i)
			{
				//printf("Matched\n");
				count[p]++;
			}
		}
		p++;
	}

	for(j=0;j<10;j++)
	{
		if((int)(str[j])!=0)
			l++;
	}
	
	printf("%d\n",l);
	if(l%2==0)
	{
		for(i=0;i<26;i++)
		{
			if(count[i]%2!=0)
				return false;
		}
		return true;
	}
	else
	{
		for(i=0;i<26;i++)
		{
			if(count[i]%2!=0)
				l_flag++;
		}
		if(l_flag>1)
			return false;

		return true;
	}
}

int main()
{
	printf("Enter string\n");
	scanf("%s",str);
	if(check())
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}