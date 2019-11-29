#include <stdio.h>
#include <string.h>
# define Infinity 9999
# define Max 100

void networks(int G[Max][Max], int n , int startnode);

struct Network
{
    char ename[32];
    
};

struct Network emp[999];
int i, j;
void ask(int n)
{
    for(i = 1; i <= n; i++)
    {
        printf("\nEnter %dst Home Address:\n", i);
        printf("\n IP Address:\t");
        scanf("%s", emp[i].ename);
       
    }
    
}
void networks(int G[Max][Max], int n , int startnode){
	
	int cost[Max][Max],distance[Max],pred[Max];
	int visited[Max],count,mindistance,nextnode,i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(G[i][j]==0)
				cost[i][j]=Infinity;
			else
				cost[i][j]=G[i][j];
	for(i=1;i<=n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=Infinity;
		for(i=1;i<=n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}			
			visited[nextnode]=1;
			for(i=1;i<=n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
	printf("\t Distance from Router %d :-",startnode);
	

	for(i=1;i<=n;i++)
		if(i!=startnode)
		{
			printf("\n\tDistance of node %d = %d ",i,distance[i]);
			printf("Home address : %s",emp[i].ename);
	}
}
	
int main()
{
	int G[Max][Max],w,n,e,u,v,i,j,str;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	printf("\n Enter the number of edges: \n");
	scanf("%d",&e);
	printf("\n Enter the Starting Node: \n");
	scanf("%d",&str);
	for(i=1;i<=n;i++){
	   for(j=1;j<=n; j++){
	   	if(i==j)
	   	{
	   		G[i][j]=0;
		   }
		else{
			G[i][j]=Infinity;
		}
	   	
		}
    }
	for(i=1;i<=e;i++){
	    printf("\n Enter the end vertices of edge %d with its weight \n",i);
		scanf("%d%d%d",&u,&v,&w);
    	G[u][v]=G[v][u]=w;
    }
	printf("\n Martrix of input data:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",G[i][j]);
			
		}
		printf("\n");
	}
	for(i=0;i<100;i++){
		printf("-");
	}
	printf("\n\n");
	printf("\t\tRouting Topology\n");
	ask(n);
	networks(G,n,str);
	


	return 0;

}




