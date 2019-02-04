#include <stdio.h>
#include <string.h>


char str[1000];
int que[1000][3];
int m;
int op;

void shift(int f, int r)
{
	char ch = str[r];
	int i;
	for(i=r-1;i>=f;i--)
	{
		str[i+1]=str[i];
	}
	str[f]=ch;
}


int main()
{
	printf("Enter string\n");
	scanf("%[^\n]s",str);
	


	printf("Enter number of queries\n");
	scanf("%d",&m);

	int i,f,r,k,j,l,len;

	for(i=0;i<1000;i++)
	{
		char ch=str[i];
		if((int)ch!=0)
			len++;
	}

	printf("Enter f,r,k\n");
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&f,&r,&k);
		que[i][0]=f;
		que[i][1]=r;
		que[i][2]=k;
	}
	

	for(i=0;i<m;i++)
	{
		f=que[i][0];
		r=que[i][1];
		k=que[i][2];
		if(f>len || r>len)
			printf("Invalid indexes\n");
		if(k>(r-f+1))
			k = (r-f+1)%k;
		printf("Number of shifts to be performed %d \n",k);
		for(j=0;j<k;j++)
		{
			shift(f-1,r-1);
			printf("String after operation %d %s\n",j,str);
		}
	}
	printf("%s\n",str);

}