
#include<stdio.h>
#include<conio.h>
#include<time.h>
# define Infinity 9999
# define Max 100
void dijikstra(int G[Max][Max], int n , int start);
void bellmon(int G[Max][Max],int n,int s);
int main(){
	int G[Max][Max],i,j,n,u;
	int p,q;
	printf("Enter number of vertices :");
	scanf("%d",&n);
	printf("ENTER THE ADJACENCY MATRIX\n");
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			p=0;
			q=0;
			printf("Enter the distance %d to %d :- ",p=i+1,q=j+1);
			scanf("%d",&G[i][j]);
		}
	}
	printf("-: Enter Matrix is :-\n");
	 for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" ");
            printf("|\t");
			printf("%d \t", G[i][j]);
			printf("|");
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0;i<150;i++){
    	printf("++");
	}
	printf("\n\n");
	printf("Enter the Starting Node (Number) :\n");
	scanf("%d",&u);
	u=u-1;
	printf("\n\n");
    for(i=0;i<150;i++){
    	printf("**");
	}
	printf("\n\n");
	clock_t start,stop;
	printf("--: DIJKSTRA ALGORITHM :--");
	start = clock();
	dijikstra(G,n,u);
	stop = clock();
	double runtime= ((double) stop - start)/ CLOCKS_PER_SEC;
	printf("\n Runtime time of Dijkastra is : %f",runtime);
	printf("\n\n");
    for(i=0;i<150;i++){
    	printf("--");
	}
	printf("\n\n");
	printf("--: BELLMAN FORD ALGORITHMS :--");
	printf("\n");
	start = clock();
	bellmon(G,n,u);
	stop = clock();
	double runtime_bellman= ((double) stop - start)/ CLOCKS_PER_SEC;
	printf("\n Runtime time of bellman is : %f",runtime_bellman);
	printf("\n\n");
    for(i=0;i<150;i++){
    	printf("--");
	}
	printf("\n\n");
	return 0;
}
void dijikstra(int G[Max][Max], int n, int startnode)
{
	int cost[Max][Max], distance[Max], pred[Max];
	int visited[Max], count, mindistance, nextnode, i,j;
	int p=0,q=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=Infinity;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=Infinity;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			p=i+1;
			printf("\nDistance of %d = %d", p, distance[i]);
			printf("\nPath = %d", p);
			j=i;
			
			do
			{
				j=pred[j];
				q=j+1;
				printf(" <-%d", q);
			}
			while(j!=startnode);
		}
}
	int key[100];

void bellmon(int G[Max][Max],int n,int s)   
{
	int i,j,k;
	int count =0;
	for(i=0;i<n;i++)
		key[i]=Infinity;
	key[s]=0;
	for(k=0;k<n-1;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(G[i][j]!=0 && key[j]>key[i]+G[i][j]){
					key[j]=key[i]+G[i][j];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G[i][j]!=0 && key[j]>key[i]+G[i][j]){
				key[j]=key[i]+G[i][j];
				count++;
			}
		}
	}
	if(count!=0)
		puts("Negative Cycle Found");
	else{
		for(i=0;i<n;i++)
			printf("%d <-- %d \t cost = %d\n",i+1,s+1,key[i]);
	}

}

//https://gist.github.com/PraSoonGosWami/c986eb382786be8fe1277078ae1f9086
//https://thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html


