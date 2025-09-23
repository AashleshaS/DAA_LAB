#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

// function prototypes
void floydWarshall(int graph[][MAX_N],int n);
void printSolution(int dist[][MAX_N],int n);

int main(){
	int n,e;

	printf("Enter the number of vertices : ");
	scanf("%d",&n);

	int graph[MAX_N][MAX_N];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				graph[i][j]=0;
			}else{
				graph[i][j]=INF;
			}
		}
	}
	printf("Enter the number of edges : ");
	scanf("%d",&e);

	for(int i=0;i<e;i++){
		int src,dest,weight;
		printf("Enter source : ");
		scanf("%d",&src);
		printf("Enter destination : ");
		scanf("%d",&dest);
		printf("Enter weight : ");
		scanf("%d",&weight);
		graph[src-1][dest-1]=weight;
	}
	floydWarshall(graph,n);

	return 0;
}

//Implements the floyd-warshall algorithm
void floydWarshall(int graph[][MAX_N],int n){
	int dist[MAX_N][MAX_N];

	//initialize the distnace matrix with the graph
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=graph[i][j];
		}
	}

	//main algorithm loop
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				//if a path through vertex 'k' is shorter,update the distance
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	//print the final solution
	printSolution(dist,n);
}

//prints the solution matrix
void printSolution(int dist[][MAX_N],int n){
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==INF){
				printf("  INF");
			}else{
				printf("%5d",dist[i][j]);
			}
		}
		printf("\n");
	}
}