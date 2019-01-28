#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int n,mat[100][100]={{0}},q[100]={0},visited[100]={0},dist[100][100],prev[100],cycle[100][100]={{0}},min_cycle=INT_MAX;

int pop(int home){
	int min=INT_MAX,index=-1;
	for (int i = 0; i < n; ++i)
	{
		// printf("dist of %d from home is %d\n",i,dist[home][i]);
		if(visited[i]==0 && dist[home][i]<min){
			min=dist[home][i];
			index=i;
		}
	}
	// printf("popping %d\n",index );
	if(dist[home][index]==2147483647)
		return -1;
	else
		return index;
}
void dj(int home){
	dist[home][home]=0;
	int temp_home=pop(home);
	do{
		// printf("visited %d at a dist of %d\n", temp_home,dist[home][temp_home]);
		visited[temp_home]=1;
		for (int i = 0; i < n; ++i)
		{
			if(mat[temp_home][i]>0){
				if(dist[home][i]>dist[home][temp_home]+mat[temp_home][i]){
					dist[home][i]=dist[home][temp_home]+mat[temp_home][i];
					prev[i]=temp_home;
				}
			}
		}
		temp_home = pop(home);
	}while(temp_home!=-1);
}
int main(int argc, char const *argv[])
{
	// For getting input from input.txt file 
    freopen("../input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("../output.txt", "w", stdout);
    scanf(" %d",&n);
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		scanf(" %d",&mat[i][j]);
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		if(mat[i][j]>0){
	    		    for (int k = 0; k < n; ++k){
	    		    	visited[k]=0;
	    				for (int l = 0; l < n; ++l)
	    					dist[k][l]=INT_MAX;
	    		    }

	    		int temp=mat[i][j];
	    		mat[i][j]=0;
	    		printf("calling for %d %d\n",i,j);
	    		dj(i);
	    		if(dist[i][j]<INT_MAX){
	    			cycle[i][j]=dist[i][j]+temp;
	    			min_cycle=min_cycle>cycle[i][j]?cycle[i][j]:min_cycle;

	    		}
	    		mat[i][j]=temp;
	    	}
    	}
    }
    printf("min cycle is %d\n",min_cycle);
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < i+1; ++j)
    	{
    		if(cycle[i][j]==min_cycle){
	    		    for (int k = 0; k < n; ++k){
	    		    	visited[k]=0;
	    				for (int l = 0; l < n; ++l)
	    					dist[k][l]=INT_MAX;
	    		    }    			
    			int tmp=mat[i][j];
	    		mat[i][j]=0;
    			dj(i);
    			int temp=j;
				do{
					printf("%d -> ",temp );
					temp=prev[temp];
				}while(temp!=i);
				printf("%d\n", i);
				mat[i][j]=tmp;
    		}
    		
		}
		printf("\n");
	}  
}