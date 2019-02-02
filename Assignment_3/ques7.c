#include <stdio.h>
#include <string.h>


char str[100];

void cipher()
{
	int i; char ch;
	for(i=0;i<100;i++)
	{
		ch=str[i];
		int x = (int)ch;
		if(x!=0 && ((x>=97 && x<=122) || (x>=65 && x<=90)))
		{
			int y = x+3;
			//printf("%d\n",y);
			if(((x>=97 && x<=122)) && y>122 || (x>=65 && x<=90) && y>90)
				y=y-26;
			//printf("%c ",(char)y);
			str[i]=(char)y;
		}
	}
	printf("%s\n",str);
}
int main()
{
	printf("Enter string\n");
	scanf("%[^\n]s",str);
	cipher();
	return 0;
}