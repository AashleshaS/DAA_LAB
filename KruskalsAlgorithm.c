#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function to find parent of a node
int find(int parent[], int i) {
	if(parent[i]!=i){
		parent[i]=find(parent,parent[i]);
	}
	return parent[i];

}

//function to unite two sets(union by rank)
void union1(int parent[], int rank[], int i, int j) {
	int rootI =find(parent,i);
	int rootJ =find(parent,j);

	if(rootI !=rootJ){
		if(rank[rootI]<rank[rootJ]){
			parent[rootI]=rootJ;
		}
		else if(rank[rootI]>rank[rootJ]){
			parent[rootJ]=rootI;
		}
		else{
			parent[rootJ]=rootI;
			rank[rootI]=rank[rootI]+1;
		}
	}
}


void kruskalMST(int **cost, int V) {
	int parent[V],rank[V];
	int mst_weight=0;
	int edge_count=0;

	//initialize parent and rank
	for(int i=0;i<V;i++){
		parent[i]=i;
		rank[i]=0;
	}
	while(edge_count<V-1){
		int min=999; //represent infinity
		int u=-1,v=-1;

		//find minimum edge
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if (cost[i][j]!=0 && find(parent,i)!=find(parent,j)){
					if(cost[i][j]<min){
						min=cost[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		//include the edge in MST
		if(u!=-1 && v!=-1){
			union1(parent,rank,u,v);
			printf("Edge %d:(%d, %d) cost:%d\n",edge_count,u,v,min);
			mst_weight=mst_weight+min;
			edge_count=edge_count+1;
		}
	}
	printf("Minimum cost= %d\n",mst_weight);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}