#include <stdio.h>
#include <stdlib.h>

// Function to Sort the files in ascending order, perform optimal file merging and return the minimum cost
int optimalMerge(int files[], int n) {
	int totalCost=0;
	int current_n=n;
	if(n<=1){
		return 0;
	}

	for(int i=0;i<n-1;i++){
		for(int k=0;k<current_n-1;k++){
			for(int j=0;j<current_n-1-k;j++){
				if(files[j]>files[j+1]){
					int temp=files[j];
					files[j]=files[j+1];
					files[j+1]=temp;
				}
			}
		}
		int file1=files[0];
		int file2=files[1];

		int mergedFile=file1+file2;
		totalCost+=mergedFile;

		files[0]=mergedFile;

		for(int j=2;j<current_n;j++){
			files[j-1]=files[j];
		}

		current_n--;
	}
	return totalCost;
}

int main() {
    int n;
    printf("Number of files: ");
    scanf("%d", &n);
    int *files = (int *)malloc(n * sizeof(int));
    printf("Enter the sizes of %d files: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d\n", minCost);
    free(files);
    return 0;
}