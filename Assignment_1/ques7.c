#include <stdio.h>
#include <string.h>

char str[10000];
int n;

void shift(int val)
{
	int c=0;
	int i;
	for(i=0; i<n; i++)
	{
		if(str[i]!=' ' && c==0)
		{
			c=1;
			if(str[i]+val <97)
			{
				str[i]= str[i]+val+26;
			}
			else if(str[i]+val >122)
			{
				str[i]= str[i]+val-26;
			}
			else
			{
			str[i]=str[i]+val;
			}
		}
		else if(str[i]!=' ' && c==1)
		{
			c=0;
		}
	}
}

void reverse()
{
	int i; int start; int j;
	int p=0;
	for(i=0; i<n; i++)
	{
		if(str[i]!=' ')
		{
			char w[100];
			start = i;
			while(str[i]!=' ')
			{
				w[p++]=str[i];
				i++;
			}
			for(j=p-1; j>=0; j--)
			{
				str[start++]=w[j];
			}
			//printf("%s\n",w);
			i--;
		}
		else
		{
			p=0;
		}
	}
}

int main()
{
	scanf("%[^\n]s", str);
	n = strlen(str);
	printf("%s %d\n",str,n);
	printf("1. Encode 2.Decode\n");
	int ch;
	scanf("%d",&ch);
	if(ch==1)
	{
		shift(3);
		//printf("%s\n",str);
		reverse();
	}
	else if(ch==2)
	{
		reverse();
		//printf("%s\n",str);
		shift(-3);	
	}
	printf("%s\n",str);
	return 0;
}

